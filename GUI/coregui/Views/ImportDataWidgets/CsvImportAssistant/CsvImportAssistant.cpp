// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant.cpp
//! @brief     Implements class CsvImportAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "DataFormatUtils.cpp"
#include "CsvImportAssistant.h"
#include "mainwindow_constants.h"
#include "StyleUtils.h"
#include <QPushButton>
#include <QTableWidget>
#include <QSettings>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
#include <QFormLayout>

namespace
{
const QSize default_dialog_size(300, 400);
}

CsvImportAssistant::CsvImportAssistant(QString& file, QWidget* parent):
        QDialog(parent)
      ,m_fileName(file)
      ,m_intensityCol(0)
      ,m_coordinateCol(0)
      ,m_units(AxesUnits::NBINS)
      ,m_tableWidget(nullptr)
      ,m_separatorField(nullptr)
      ,m_firstDataRowSpinBox(nullptr)
      ,m_lastDataRowSpinBox(nullptr)
      ,m_importButton(nullptr)
      ,m_csvFile(nullptr)
      ,m_csvArray()
      ,m_coordinateUnitsSelector(nullptr)
      ,m_setAsTheta(new QAction(HeaderLabels[_theta_],nullptr))
      ,m_setAs2Theta(new QAction(HeaderLabels[_2theta_],nullptr))
      ,m_setAsQ(new QAction(HeaderLabels[_q_],nullptr))
      ,m_setAsIntensity(new QAction("Set as " + HeaderLabels[_intensity_] + " column",nullptr))
{
    //We disable 2theta until the functionallity to handle it is implemented
    m_setAs2Theta->setDisabled(true);
    //
    setWindowTitle("Data Importer");
    setMinimumSize(default_dialog_size);
    resize(600, 600);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    StyleUtils::setResizable(this);
    setLayout(createLayout());

    if(!initialSetup()){
        showErrorMessage("The file exist but it seems to be empty");
        return;
    }

    Reload();
}

QBoxLayout* CsvImportAssistant::createLayout()
{
    //table Widget
    m_tableWidget = new QTableWidget();
    m_tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(m_tableWidget, &QTableWidget::customContextMenuRequested, this, &CsvImportAssistant::onColumnRightClick);

    //Import button
    m_importButton = new QPushButton("Import");
    m_importButton->setDefault(true);
    connect(m_importButton, &QPushButton::clicked, this, &CsvImportAssistant::onImportButton);

    //Reject button
    auto rejectButton = new QPushButton("Cancel");
    connect(rejectButton, &QPushButton::clicked, this, &CsvImportAssistant::onRejectButton);

    //Separator field
    m_separatorField = new QLineEdit(QString(""));
    m_separatorField->setMaxLength(1);
    m_separatorField->setMaximumWidth(100);
    connect(m_separatorField, &QLineEdit::editingFinished, this, &CsvImportAssistant::reloadCsvFile);

    //First Row SpinBox
    m_firstDataRowSpinBox = new QSpinBox();
    m_firstDataRowSpinBox->setMinimum(1);
    m_firstDataRowSpinBox->setMaximum(1);
    m_firstDataRowSpinBox->setValue(1);
    m_firstDataRowSpinBox->setMaximumWidth(100);
    connect(m_firstDataRowSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
            [this]()
            {
                m_lastDataRowSpinBox->setMinimum(m_firstDataRowSpinBox->value());
                Reload();
            }
    );

    //Last Row SpinBox
    m_lastDataRowSpinBox = new QSpinBox();
    m_lastDataRowSpinBox->setMinimum(1);
    m_lastDataRowSpinBox->setMaximum(1);
    m_lastDataRowSpinBox->setValue(1);
    m_lastDataRowSpinBox->setMaximumWidth(100);
    connect(m_lastDataRowSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
            [this]()
            {
                m_firstDataRowSpinBox->setMaximum(m_lastDataRowSpinBox->value());
                Reload();
            }
    );

    //Column type selector
    m_coordinateUnitsSelector = new QComboBox();
    m_coordinateUnitsSelector->setMaximumWidth(100);
    m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::NBINS]);
    connect(m_coordinateUnitsSelector,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this, [this](){ setCoordinateUnits(); });


    auto layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);

    //place table Widget
    auto tableLayout = new QVBoxLayout;
    tableLayout->setMargin(10);
    tableLayout->addWidget(new QLabel("Right click on the table to select what will be imported"));
    tableLayout->addWidget(m_tableWidget);

    //place separator_field and first_row:
    auto controlsLayout = new QFormLayout;
    controlsLayout->addRow(tr("&Corodinate Units: "), m_coordinateUnitsSelector);
    controlsLayout->addRow(tr("&Separator: "), m_separatorField);
    controlsLayout->addRow(tr("&From row: "), m_firstDataRowSpinBox);
    controlsLayout->addRow(tr("&To row: "), m_lastDataRowSpinBox);

    //buttons layout
    auto buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(m_importButton);
    buttonsLayout->addWidget(rejectButton);

    //place controls and import/reject buttons
    auto controlsAndButtonsGrid = new QGridLayout;
    controlsAndButtonsGrid->setMargin(10);
    controlsAndButtonsGrid->addItem(new QSpacerItem(10000,1),1,1,2,1);
    controlsAndButtonsGrid->addLayout(controlsLayout, 1, 2, 1, 1, Qt::AlignRight);
    controlsAndButtonsGrid->addLayout(buttonsLayout, 2, 2, 1, 1, Qt::AlignLeft);

    //build all the layout
    layout->addLayout(tableLayout);
    layout->addLayout(controlsAndButtonsGrid);

    return layout;
}

bool CsvImportAssistant::initialSetup(){
    try {
        m_csvFile = std::make_unique<CSVFile>(m_fileName.toStdString(), separator());
    }
    catch (...) {
        showErrorMessage("There was a problem opening the file \"" + m_fileName.toStdString() + "\"");
        return false;
    }

    size_t lastRow = m_csvFile->NumberOfRows();
    auto csvArray = m_csvFile->asArray();


    if (lastRow < 1) {
        m_importButton->setDisabled(true);
        return false;
    }

    //Automatically ignore empty lines at the end:
    while(QString::fromStdString(accumulate(csvArray[lastRow-1].begin(), csvArray[lastRow-1].end(), std::string(""))).trimmed() == ""){
        lastRow--;
        if (lastRow < 1) {
            m_importButton->setDisabled(true);
            return false;
        }
    }

    //Set maximum values for spinboxes
    m_firstDataRowSpinBox->setMaximum(int(lastRow));
    m_lastDataRowSpinBox->setMaximum(int(lastRow));
    m_lastDataRowSpinBox->setValue(int(lastRow));

    std::vector<std::vector<std::string>> tmp(csvArray.begin() , csvArray.begin() + maxLines());
    m_csvArray.swap(tmp);
    return true;
}


void CsvImportAssistant::Reload()
{
    m_importButton->setEnabled(false);
    m_coordinateUnitsSelector->setEnabled(false);
    std::ifstream f(m_fileName.toStdString());
    if(f.good()){
        generate_table();
    }else{
        QMessageBox msgBox;
        std::string message = "There was a problem opening the file \"" + m_fileName.toStdString() + "\"";
        message += "\n Check for any errors in the path and try again.";
        msgBox.setText(QString::fromStdString(message));
        msgBox.setIcon(msgBox.Critical);
        msgBox.exec();
    }

    //Enable import button only if the user has selected its columns for 1d import
    if( m_intensityCol > 0 )
        m_importButton->setEnabled(true);

    //Enable Coordinate Selector
    if( m_coordinateCol > 0 )
        m_coordinateUnitsSelector->setEnabled(true);
}

void CsvImportAssistant::reloadCsvFile(){
    reset();
    initialSetup();
    Reload();
}

void CsvImportAssistant::onRejectButton(){
    reject();
}


void CsvImportAssistant::onImportButton()
{
    try {
        auto data = getData();
        accept();
    } catch(std::exception& e){
        QString message = QString("Unable to import, the following exception was thrown:\n") + QString::fromStdString(e.what());
        QMessageBox::warning(nullptr, "Wrong data format", message);
    }
}

ImportDataInfo CsvImportAssistant::getData()
{

    std::unique_ptr<OutputData<double>> resultOutputData;
    resultOutputData = std::make_unique<OutputData<double>>();

    auto nRows = m_tableWidget->rowCount();
    auto firstRow = int(firstLine()-1);
    auto lastRow = int(lastLine());

    //Coordinate and Intensity columns selected
    if(m_coordinateCol * m_intensityCol > 0){
        //Fill intensity values and coordinate values:
        std::vector<double> coordValues;
        std::vector<double> intensityValues;
        int intensityCol = int(m_intensityCol-1);
        int coordinateCol = int(m_coordinateCol-1);
        for(auto row = firstRow; row < lastRow; row++) {
            coordValues.push_back(
            helperDoubleParser(
                            m_tableWidget->item(row,coordinateCol)->text().toStdString()
                            )
                        );

            intensityValues.push_back(
             helperDoubleParser(
                           m_tableWidget->item(row,intensityCol)->text().toStdString()
                            )
                        );
        }
        auto axisName = m_coordinateName.toStdString();
        PointwiseAxis coordAxis(axisName, coordValues);
        resultOutputData->addAxis(coordAxis);

        for(unsigned i = 0; i < intensityValues.size(); i++)
            (*resultOutputData)[i] = intensityValues[i];
    }

    //Single column selected
    else if( m_intensityCol > 0){
        //Fill intensity values
        std::vector<double> intensityValues;
        int intensityCol = int(m_intensityCol-1);
        for(auto row = firstRow; row < lastRow; row++) {
            intensityValues.push_back(
            helperDoubleParser(
                           m_tableWidget->item(row,intensityCol)->text().toStdString()
                            )
                        );

        }
        resultOutputData->addAxis("AXIS", size_t(nRows), 0.0, double(nRows-1));
        for(unsigned i = 0; i < intensityValues.size(); i++)
            (*resultOutputData)[i] = intensityValues[i];

    }

    //We shouldn't be here
    else{
        showErrorMessage("Somethig went wrong during 1D data import.");
        return ImportDataInfo();
    }

    ImportDataInfo result(std::move(resultOutputData),m_units);
    return result;

    /*In case a 2d import is needed in the future
     *Use ArrayUtils::Create2dData(vector<vector<double>>)
     * ArrayUtils::Create2d
    */
}

void CsvImportAssistant::generate_table() {
    removeBlankColumns();

    set_table_data();

    greyOutCells();
}

void CsvImportAssistant::set_table_data(){

    if(m_csvArray.empty()){
        m_tableWidget->clearContents();
        m_tableWidget->setRowCount(0);
        return;
    }

    size_t nRows = m_csvArray.size();
    size_t nCols = m_csvArray[0].size();
    m_tableWidget->clearContents();
    m_tableWidget->setColumnCount(int(nCols));
    m_tableWidget->setRowCount(0);

    for(unsigned i = 0; i < nRows ; i++){
        m_tableWidget->insertRow(m_tableWidget->rowCount());
        unsigned I = unsigned(m_tableWidget->rowCount()) - 1;
        for(unsigned j = 0; j < m_csvArray[i].size(); j++){
            m_tableWidget->setItem(int(I),int(j),new QTableWidgetItem(QString::fromStdString(m_csvArray[i][j])));
        }
    }
}

void CsvImportAssistant::greyOutCells(){
    int nRows = m_tableWidget->rowCount();
    int nCols = m_tableWidget->columnCount();
    QFont italicFont;
    italicFont.setItalic(true);
    italicFont.setStrikeOut(true);

    //grey out non useful first rows
    for(int i = 0; i < int(firstLine()) - 1; i++)
        for(int j = 0; j < nCols; j++){
            m_tableWidget->item(i,j)->setBackground(Qt::gray);
            m_tableWidget->item(i,j)->setFont(italicFont);
        }

    //grey out non useful last rows
    for(int i = int(lastLine()); i < nRows; i++)
        for(int j = 0; j < nCols; j++){
            m_tableWidget->item(i,j)->setBackground(Qt::gray);
            m_tableWidget->item(i,j)->setFont(italicFont);
        }

    //Return if there are no columns to grey out
    if( m_intensityCol  < 1 )
        return;

    //Grey out columns
    for(int i = 0; i < nRows; i++)
        for(int j = 0; j < nCols; j++)
            if(j+1 != int(m_coordinateCol) &&
                            j+1 != int(m_intensityCol) ){
                m_tableWidget->item(i,j)->setBackground(Qt::gray);
                m_tableWidget->item(i,j)->setFont(italicFont);
            }
}

void CsvImportAssistant::removeBlankColumns(){

    if(m_csvArray.empty())
        return;

    std::vector<std::vector<std::string>> buffer2d;
    std::vector<std::string> buffer1d;
    std::vector<int> to_be_removed;

    size_t nRows = m_csvArray.size();
    size_t nCols = m_csvArray[0].size();

    if(!hasEqualLengthLines(m_csvArray)){
        throw Exceptions::NotImplementedException("All inner vectors should have the same length already.");
    }

    //traverse the array columnwise -- this may be inneficient.
    for(size_t j = 0; j < nCols; j++){
        buffer1d.clear();
        for(size_t i = 0; i < nRows; i++){
            buffer1d.push_back(m_csvArray[i][j]);
        }
        if(QString::fromStdString(accumulate(buffer1d.begin(), buffer1d.end(), std::string(""))).trimmed() == "")
            continue;

        buffer2d.push_back(buffer1d);
    }

    if(buffer2d.empty()){
        m_csvArray.clear();
        return;
    }

    //now buffer2d has the original array, without blank columns, transposed.
    nCols = buffer2d.size();
    nRows = buffer2d[0].size();

    //Save the modified array --i.e. transpose buffer2d
    m_csvArray.clear();
    for(size_t i = 0; i < nRows; i++){
        buffer1d.clear();
        for(size_t j = 0; j < nCols; j++){
            buffer1d.push_back(buffer2d[j][i]);
        }
        m_csvArray.push_back(buffer1d);
    }
}

char CsvImportAssistant::separator() const{
    char separator;
    QString tmpstr = m_separatorField->text();
    if(tmpstr.size() < 1){
        separator = guessSeparator();
        m_separatorField->setText(QString(QChar::fromLatin1(separator)));
    }
    else{
        separator = tmpstr.at(0).toLatin1();
    }
    return separator;
}

char CsvImportAssistant::guessSeparator() const{
    int frequencies[127] = {0};

    //The actual characters that may be realistically
    //used as separators are only a handfull...
    //And this list seems already exagerated.
    std::vector<char> preferredSeparators;
    preferredSeparators.push_back(' ');
    preferredSeparators.push_back(',');
    preferredSeparators.push_back(';');
    preferredSeparators.push_back('|');
    preferredSeparators.push_back(':');
    preferredSeparators.push_back('\t');
    preferredSeparators.push_back('/');
    preferredSeparators.push_back('\\');
    preferredSeparators.push_back('_');
    preferredSeparators.push_back('\'');
    preferredSeparators.push_back('\"');


    //count number of occurences of each char in the file:
    char c;
    std::ifstream is(m_fileName.toStdString());
    while (is.get(c)){
        if(unsigned(c) < 127)
            frequencies[unsigned(c)]++;
    }
    is.close();

    //set the guessed separator as the most frequent among the
    //preferred separators. -- Some unavoidable hieararchy is
    //present: characters with lower ascii code are preferred.
    char guessedSep = ' ';
    int freq = 0;
    for(char i = 0; i< 127 ; i++){
        if( std::find(preferredSeparators.begin(), preferredSeparators.end(), i) != preferredSeparators.end())
            if(frequencies[int(i)] > freq){
                freq = frequencies[int(i)];
                guessedSep = i;
            }
    }

    //We don't like tabs, as we cannot write them in the GUI.
    //The rest of the CsvImportAssistant and CsvReader should be already aware of this.
    if(guessedSep == '\t')
        guessedSep = ' ';

    return guessedSep;
}

void CsvImportAssistant::setHeaders(){
    //Reset header labels
    QStringList headers;

    for(int j = 0; j < m_tableWidget->columnCount(); j++)
        headers.append(QString::number(j + 1));

    m_tableWidget->setHorizontalHeaderLabels(headers);
}

unsigned CsvImportAssistant::firstLine() const{
    return unsigned(m_firstDataRowSpinBox->value());
}

unsigned CsvImportAssistant::lastLine() const{
    return unsigned(m_lastDataRowSpinBox->value());
}

unsigned CsvImportAssistant::maxLines() const{
    return unsigned(m_lastDataRowSpinBox->maximum());
}

void CsvImportAssistant::onColumnRightClick(const QPoint position)
{
    auto item = m_tableWidget->itemAt(position);
    if(!item) return;
    auto row = item->row();
    auto col = item->column();
    if(row*col < 0) return;

    QMenu menu;

    //Action "select from this row"
    QAction selectFromThisRowOn("Set as first data row",nullptr);
    menu.addAction(&selectFromThisRowOn);
    connect(&selectFromThisRowOn,&QAction::triggered,this,[this](){setFirstRow();});

    //Action "select until this row"
    QAction selectUntilThisRow("Set as last data row",nullptr);
    menu.addAction(&selectUntilThisRow);
    connect(&selectUntilThisRow,&QAction::triggered,this,[this](){setLastRow();});

    menu.addSeparator();


    //Set column as "Intensity".
    m_setAsIntensity->setDisabled(m_intensityCol>0);
    menu.addAction(m_setAsIntensity);
    connect(m_setAsIntensity,&QAction::triggered,this, [this](){setColumnAsIntensity();});
    //.connect(m_setAsIntensity,&QAction::triggered,this, m_setAsIntensityColumnAsIntensity());


    //Coordinate menu disabled if a coordinate column is already set.
    QMenu *coordMenu = menu.addMenu("Set as coordinate column...");
    coordMenu->setDisabled(m_coordinateCol>0);


    //Set column as "Theta".
    coordMenu->addAction(m_setAsTheta);
    connect(m_setAsTheta,&QAction::triggered,this, [this](){setColumnAsCoordinate(_theta_);});


    //Set column as "2Theta".
    coordMenu->addAction(m_setAs2Theta);
    connect(m_setAs2Theta,&QAction::triggered,this, [this](){setColumnAsCoordinate(_2theta_);});


    //Set column as "q".
    coordMenu->addAction(m_setAsQ);
    connect(m_setAsQ,&QAction::triggered,this, [this](){setColumnAsCoordinate(_q_);});

    menu.addSeparator();

    //Action "reset"
    QAction resetAction("reset",nullptr);
    menu.addAction(&resetAction);
    connect(&resetAction,&QAction::triggered, this, [this](){reset(); Reload();});

    menu.exec(m_tableWidget->mapToGlobal(position));
}

bool CsvImportAssistant::hasEqualLengthLines(std::vector<std::vector<std::string>> &dataArray){
    auto tf =  all_of( begin(dataArray), end(dataArray), [dataArray](const std::vector<std::string>& x) {
        return x.size() == dataArray.front().size();
    });
    return tf;
}

void CsvImportAssistant::showErrorMessage(std::string message){
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(message));
    msgBox.setIcon(msgBox.Critical);
    msgBox.exec();
}

void CsvImportAssistant::populateUnitsComboBox(int coord){
    m_coordinateUnitsSelector->clear();
    switch(coord){

    case _theta_:
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::DEGREES]);
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::RADIANS]);
        break;

    case _2theta_:
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::DEGREES]);
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::RADIANS]);
        break;

    case _q_:
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::QSPACE]);
        break;

    default:
        m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::NBINS]);
        break;
    }
}

void CsvImportAssistant::setColumnAsCoordinate(int coord){
    auto selectedRanges = m_tableWidget->selectedRanges();
    if (selectedRanges.empty())
        return;
    auto front = selectedRanges.front();
    auto col = front.leftColumn();

    m_tableWidget->setHorizontalHeaderItem( col, new QTableWidgetItem( HeaderLabels[coord]) );
    m_coordinateCol = unsigned(col+1);
    m_coordinateName = m_tableWidget->horizontalHeaderItem(col)->text();
    populateUnitsComboBox(coord);
    if(m_coordinateCol == m_intensityCol){
        m_intensityCol=0;
    }
    Reload();
}

void CsvImportAssistant::setColumnAsIntensity() {
    //get selected column
    auto selectedRanges = m_tableWidget->selectedRanges();
    if (selectedRanges.empty())
        return;
    auto front = selectedRanges.front();
    auto col = front.leftColumn();

    m_tableWidget->clearSelection();
    m_tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem(HeaderLabels[_intensity_]));
    m_intensityCol = unsigned(col + 1);
    if (m_coordinateCol == m_intensityCol) {
        m_coordinateCol = 0;
    }
    Reload();
}

void CsvImportAssistant::setCoordinateUnits(){
    m_units = AxesUnits::NBINS;
    if(m_coordinateUnitsSelector->currentText() == UnitsLabels[AxesUnits::DEGREES])
        m_units = AxesUnits::DEGREES;

    if(m_coordinateUnitsSelector->currentText() == UnitsLabels[AxesUnits::RADIANS])
        m_units = AxesUnits::RADIANS;

    if(m_coordinateUnitsSelector->currentText() == UnitsLabels[AxesUnits::QSPACE])
        m_units = AxesUnits::QSPACE;
}

void CsvImportAssistant::setFirstRow(){
    //get selected column
    auto selectedRanges = m_tableWidget->selectedRanges();
    if (selectedRanges.empty())
        return;
    auto front = selectedRanges.front();
    auto row = front.topRow();
    auto currentMax = m_firstDataRowSpinBox->maximum();
    auto desiredVal = row+1;
    auto newMax = std::max(currentMax,desiredVal);
    m_firstDataRowSpinBox->setMaximum(newMax);
    m_firstDataRowSpinBox->setValue(desiredVal);
}

void CsvImportAssistant::setLastRow(){
    //get selected column
    auto selectedRanges = m_tableWidget->selectedRanges();
    if (selectedRanges.empty())
        return;
    auto front = selectedRanges.front();
    auto row = front.topRow();
    auto currentMin = m_firstDataRowSpinBox->minimum();
    auto desiredVal = row+1;
    auto newMin = std::min(currentMin,desiredVal);
    m_lastDataRowSpinBox->setMinimum(newMin);
    m_lastDataRowSpinBox->setValue(desiredVal);
}

void CsvImportAssistant::reset(){
    m_intensityCol = 0;
    m_coordinateCol = 0;
    m_coordinateName = "";
    m_firstDataRowSpinBox->setValue(0);
    m_lastDataRowSpinBox->setValue(int(maxLines()));
    setHeaders();
    m_units = AxesUnits::NBINS;
    m_coordinateUnitsSelector->clear();
    m_coordinateUnitsSelector->addItem(UnitsLabels[AxesUnits::NBINS]);
}

double CsvImportAssistant::helperDoubleParser(std::string string_to_parse){
        std::vector<double> parsed_doubles;
        parsed_doubles = DataFormatUtils::parse_doubles(string_to_parse);
        return parsed_doubles[0];
}
