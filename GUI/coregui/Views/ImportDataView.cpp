// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/ImportDataView.cpp
//! @brief     Implements class ImportDataView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ImportDataView.h"
#include "mainwindow.h"
#include "ImportDataToolBar.h"
#include "ItemSelectorWidget.h"
#include "RealDataModel.h"
#include "mainwindow_constants.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QDebug>

ImportDataView::ImportDataView(MainWindow *mainWindow)
    : QWidget(mainWindow)
    , m_toolBar(new ImportDataToolBar)
    , m_splitter(new QSplitter)
    , m_selectorWidget(new ItemSelectorWidget)
    , m_stackedWidget(new ItemStackPresenter<RealDataEditorWidget>)
    , m_realDataModel(mainWindow->realDataModel())
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    m_stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_selectorWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    m_stackedWidget->setSizeHint(QSize(1024, 1024));

    m_splitter->addWidget(m_selectorWidget);
    m_splitter->addWidget(m_stackedWidget);
    m_splitter->setCollapsible(0, false);
    m_splitter->setCollapsible(1, false);

    m_splitter->setSizes(QList<int>() << Constants::ITEM_SELECTOR_WIDGET_WIDTH
                         << Constants::ITEM_SELECTOR_WIDGET_WIDTH*8);

    mainLayout->addWidget(m_toolBar);
    mainLayout->addWidget(m_splitter);

    setLayout(mainLayout);

    setupConnections();

    m_selectorWidget->setModel(mainWindow->realDataModel());
    m_stackedWidget->setModel(mainWindow->realDataModel());
    m_toolBar->setModel(mainWindow->realDataModel());
    m_toolBar->setSelectionModel(m_selectorWidget->selectionModel());

}

void ImportDataView::onSelectionChanged(SessionItem *item)
{
    if(!item) return;

    bool isNew(false);
    m_stackedWidget->setItem(item, isNew);
    if(isNew) {
        RealDataEditorWidget *widget = m_stackedWidget->currentWidget();
        Q_ASSERT(widget);
        widget->setItem(item);
    }
}

void ImportDataView::setupConnections()
{
    connect(m_selectorWidget, SIGNAL(selectionChanged(SessionItem *)),
        this, SLOT(onSelectionChanged(SessionItem *)));

//    connect(m_realDataModel,
//            SIGNAL(modelAboutToBeReset()),
//            this,
//            SLOT(resetView())
//            );

//    connect(m_instrumentModel,
//            SIGNAL(rowsAboutToBeRemoved(QModelIndex, int,int)),
//            this,
//            SLOT(onRowsAboutToBeRemoved(QModelIndex,int,int))
//            );

}