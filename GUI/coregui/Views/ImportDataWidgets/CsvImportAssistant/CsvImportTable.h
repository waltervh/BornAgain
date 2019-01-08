// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/CsvImportAssistant/CsvImportTable.h
//! @brief     Defines class CsvImportTable
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef CSVIMPORTTABLE_H
#define CSVIMPORTTABLE_H

#include "CsvDataColumn.h"
#include "CsvNamespace.h"
#include <QTableWidget>
#include <set>

class BA_CORE_API_ CsvImportData : public QObject
{
public:
    // FIXME: move DATA_TYPE enumeration to csv namespace
    enum DATA_TYPE {Intensity, Coordinate };

    CsvImportData(QObject* parent = nullptr);

    void setData(csv::DataArray data);
    //! sets _type_ to a column _col_. Returns the
    //! column number previously set to the type
    int setColumnAs(int col, csv::ColumnType type);
    void setMultiplier(DATA_TYPE type, double value);
    void setFirstRow(int row);
    void setLastRow(int row);

    // static methods
    // FIXME: move to csv namespace or utilities
    static std::vector<DATA_TYPE> availableTypes();
    // accessors
    const csv::DataArray& data() const;
    int column(DATA_TYPE type) const;
    csv::DataColumn values(int col) const;
    csv::DataColumn multipliedValues(DATA_TYPE type) const;
    double multiplier(DATA_TYPE type) const;
    QString columnLabel(DATA_TYPE type) const;
    size_t nCols() const;
    size_t nRows() const;

    std::set<std::pair<int, int>> checkData();

private:
    //! Checks if selected data is suitable for import.
    //! All values must be convertible to doubles, positive and
    //! sorted in ascending order if _check_ordering_ is set to true.
    //! Returns a set of rows where the check failed.
    std::set<int> checkFormat(const csv::DataColumn& values, bool check_ordering);

    std::unique_ptr<const csv::DataArray> m_data;
    std::map<DATA_TYPE, CsvCoordinateColumn> m_selected_cols;
    size_t m_n_header; //!< number of header rows
    size_t m_n_footer; //!< number of footer rows
    std::set<int> m_discarded_rows;
};

class CsvImportTable_ : public QTableWidget
{
    Q_OBJECT
public:
    CsvImportTable_(QWidget* parent = nullptr);

    void setData(csv::DataArray data);
    void setColumnAs(int col, csv::ColumnType type);

    // accessors
    int intensityColumn() const { return m_import_data->column(CsvImportData::Intensity); }
    int coordinateColumn() const { return m_import_data->column(CsvImportData::Coordinate); }
    double intensityMultiplier() const
    {
        return m_import_data->multiplier(CsvImportData::Intensity);
    }
    double coordinateMultiplier() const
    {
        return m_import_data->multiplier(CsvImportData::Coordinate);
    }

signals:
    void dataSanityChanged();

private:
    void updateSelection();
    void setHeaders();
    void updateSelectedCols(); // replacement for applyMultipliers
    void setMultiplierFields();
    bool checkData();
    void resetColumn(int col);
    int rowOffset() const { return 1; } // this comes from the multipliers in the first row

    void markCell(int i, int j, Qt::GlobalColor color);

    CsvImportData* m_import_data;
    bool m_data_is_suitable;
};

class CsvImportTable : public QTableWidget
{
    Q_OBJECT
public:
    CsvImportTable(QWidget* parent = nullptr);

    int selectedRow() const;
    std::set<int> selectedRows() const;
    int selectedColumn() const;
    int intensityColumn() const { return m_intensityCol->columnNumber(); }
    int coordinateColumn() const { return m_coordinateCol->columnNumber(); }
    int firstRow() { return int(m_firstRow) + rowOffset(); }
    int lastRow() { return int(m_lastRow) + rowOffset(); }
    double intensityMultiplier() const { return m_intensityCol->multiplier(); }
    double coordinateMultiplier() const { return m_coordinateCol->multiplier(); }
    std::set<int> rowsToDiscard() const { return m_rowsToDiscard; }
    csv::ColumnType coordinateName() const { return m_coordinateCol->name(); }
    AxesUnits coordinateUnits() const { return m_coordinateCol->units(); }
    bool dataLooksGood() const { return m_dataLooksGood; }

    void setData(const csv::DataArray data);
    void updateSelection();
    void applyMultipliers();
    void setColumnAs(int col, csv::ColumnType CoordOrInt, double multiplier = 1.0);
    void setFirstRow(size_t row);
    void setLastRow(size_t row);
    void discardRows(std::set<int> rows);
    void setCoordinateName(const csv::ColumnType coordName)
    {
        m_coordinateCol->setName(coordName);
        setHeaders();
    }
    void setMultiplierFields();

signals:
    void dataSanityChanged();

private:
    bool isRowDiscarded(const int row) const ;
    void runSanityChecks();
    bool runIntensitySanityChecks();
    bool runCoordinateSanityChecks();
    void greyoutDataToDiscard();
    void greyoutCell(int i, int j, bool yes, Qt::GlobalColor color = Qt::white);
    bool needsGreyout(const int iRow, const int jCol) const;
    void multiplyColumn(const CsvIntensityColumn& col);
    void restoreColumnValues(int col, csv::DataColumn colvals);
    csv::DataColumn valuesFromColumn(int col);
    void setHeaders();
    int rowOffset() const { return 1; } // this comes from the multipliers in the first row

    std::unique_ptr<CsvCoordinateColumn> m_intensityCol;
    std::unique_ptr<CsvCoordinateColumn> m_coordinateCol;
    size_t m_firstRow;
    size_t m_lastRow;
    std::set<int> m_rowsToDiscard;
    bool m_dataLooksGood;
};

#endif // CSVIMPORTTABLE_H
