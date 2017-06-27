#include <QtTest>
#include "AutosaveController.h"
#include "projectdocument.h"
#include "ApplicationModels.h"
#include "InstrumentModel.h"
#include "InstrumentItem.h"
#include "RealDataModel.h"
#include "RealDataItem.h"
#include "IntensityDataItem.h"
#include "JobItemUtils.h"
#include "GUIHelpers.h"
#include "SaveService.h"
#include "ProjectUtils.h"
#include "test_utils.h"
#include <QSignalSpy>
#include <QDebug>

class TestSaveService : public QObject
{
    Q_OBJECT

private:
    // helper method to modify something in a model
    void modify_models(ApplicationModels* models)
    {
        auto instrument = models->instrumentModel()->instrumentItem();
        instrument->setItemValue(InstrumentItem::P_IDENTIFIER, GUIHelpers::createUuid());
    }

private slots:
    void test_autoSaveController();
    void test_saveService();
    void test_saveServiceWithData();
    void test_autosaveEnabled();
//    void test_autoSaveIncludingData();
};

inline void TestSaveService::test_autoSaveController()
{
    const QString projectDir("test_autoSaveController");
    TestUtils::create_dir(projectDir);

    const QString projectFileName("test_autoSaveController/document.pro");

    const int autosave_time(100);

    ApplicationModels models;
    ProjectDocument* document = new ProjectDocument;
    document->setApplicationModels(&models);
    document->save(projectFileName);

    // Setting up autosave
    AutosaveController autosave;
    autosave.setAutosaveTime(autosave_time);
    autosave.setDocument(document);

    QCOMPARE(autosave.autosaveDir(), QString("test_autoSaveController/autosave"));
    QCOMPARE(autosave.autosaveName(), QString("test_autoSaveController/autosave/document.pro"));

    QSignalSpy spyAutosave(&autosave, SIGNAL(autosaveRequest()));

    // modify document once and check
    modify_models(&models);
    QVERIFY(document->isModified() == true);
    QVERIFY(spyAutosave.wait(autosave_time * 3.0));
    QCOMPARE(spyAutosave.count(), 1);

    QDir autosaveDir(autosave.autosaveDir());
    QVERIFY(autosaveDir.exists());

    // saving document and checking that autosave is not triggered
    document->save(projectFileName);
    QVERIFY(document->isModified() == false);
    QCOMPARE(spyAutosave.count(), 1);

    // modify several times and check
    for (size_t i = 0; i < 10; ++i)
        modify_models(&models);

    QVERIFY(spyAutosave.wait(autosave_time * 3.0));
    QCOMPARE(spyAutosave.count(), 2);

    // remove autosave dir
    autosave.removeAutosaveDir();
    QVERIFY(autosaveDir.exists() == false);
}


inline void TestSaveService::test_saveService()
{
    TestUtils::create_dir("test_saveService");
    const QString projectFileName("test_saveService/document.pro");

    ApplicationModels models;
    ProjectDocument* document = new ProjectDocument;
    document->setApplicationModels(&models);

    QVERIFY(ProjectUtils::exists(projectFileName) == false);

    SaveService service;
    QSignalSpy spySaveService(&service, SIGNAL(projectSaved()));

    service.setDocument(document);
    service.save(projectFileName);

    QCOMPARE(spySaveService.count(), 1);
    QVERIFY(ProjectUtils::exists(projectFileName) == true);
}

inline void TestSaveService::test_saveServiceWithData()
{
    TestUtils::create_dir("test_saveServiceWithData");
    const QString projectFileName("test_saveServiceWithData/document.pro");

    ApplicationModels models;
    RealDataItem* realData = dynamic_cast<RealDataItem*>(
        models.realDataModel()->insertNewItem(Constants::RealDataType));
    Q_ASSERT(realData);
    IntensityDataItem* intensityItem = realData->intensityDataItem();
    JobItemUtils::createDefaultDetectorMap(intensityItem,
                                           models.instrumentModel()->instrumentItem());
    intensityItem->setItemValue(IntensityDataItem::P_FILE_NAME, "realdata.int.gz");

    ProjectDocument* document = new ProjectDocument;
    document->setApplicationModels(&models);

    QVERIFY(ProjectUtils::exists(projectFileName) == false);

    SaveService service;
    QSignalSpy spySaveService(&service, SIGNAL(projectSaved()));

    service.setDocument(document);
    service.save(projectFileName);

    spySaveService.wait(100); // waiting saving in a thread is complete

    QCOMPARE(spySaveService.count(), 1);
    QVERIFY(ProjectUtils::exists(projectFileName) == true);
    QVERIFY(document->isModified() == false);
}

inline void TestSaveService::test_autosaveEnabled()
{
    TestUtils::create_dir("test_autosaveEnabled");
    const int autosave_time(100);
    const QString projectFileName("test_autosaveEnabled/document.pro");

    ApplicationModels models;
    ProjectDocument* document = new ProjectDocument;
    document->setApplicationModels(&models);

    SaveService service;
    QSignalSpy spySaveService(&service, SIGNAL(projectSaved()));

    service.setAutosaveEnabled(true);
    service.setAutosaveTime(autosave_time);
    service.setDocument(document);
    service.save(projectFileName);

//    spySaveService.wait(100); // waiting saving in a thread is complete
    QCOMPARE(spySaveService.count(), 1);
    QVERIFY(document->isModified() == false);

    // modify several times and check
    for (size_t i = 0; i < 10; ++i)
        modify_models(&models);

    QVERIFY(document->isModified() == true);

//    QVERIFY(spySaveService.wait(autosave_time * 3.0));
//    QCOMPARE(spyAutosave.count(), 2);


}



//inline void TestAutosave::test_autoSaveIncludingData()
//{
//    const int autosave_time(100);
//    ApplicationModels models;

//    RealDataItem* realData = dynamic_cast<RealDataItem*>(
//        models.realDataModel()->insertNewItem(Constants::RealDataType));
//    Q_ASSERT(realData);
//    IntensityDataItem* intensityItem = realData->intensityDataItem();
//    JobItemUtils::createDefaultDetectorMap(intensityItem,
//                                           models.instrumentModel()->instrumentItem());
//    intensityItem->setItemValue(IntensityDataItem::P_FILE_NAME, "realdata.int.gz");

//    const QString projectDir("test_autoSave");
//    const QString projectFileName("test_autoSave/document.pro");
//    GUIHelpers::createSubdir(".", projectDir);

//    ProjectDocument* document = new ProjectDocument;
//    document->setApplicationModels(&models);
//    document->save(projectFileName);

//    // Setting up auto save
//    AutosaveService autosave;
//    autosave.setAutosaveTime(autosave_time);
//    autosave.setDocument(document);

//    QSignalSpy spyAutosave(&autosave, SIGNAL(autosaved()));

//    // modify document once and check
//    modify_models(&models);
//    QVERIFY(spyAutosave.wait(autosave_time * 3.0));
//    QCOMPARE(spyAutosave.count(), 1);

//    QFileInfo info("test_autoSave/autosave/document.pro");
//    QVERIFY(info.exists());

//    info.setFile("test_autoSave/autosave/realdata.int.gz");
//    QVERIFY(info.exists());
//}
