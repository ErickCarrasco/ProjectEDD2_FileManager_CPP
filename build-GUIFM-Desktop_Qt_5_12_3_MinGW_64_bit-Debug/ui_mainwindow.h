/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionClose_File;
    QAction *actionAdd_Field;
    QAction *actionModify_Field;
    QAction *actionDelete_Field;
    QAction *actionAdd_Record;
    QAction *actionSave_File;
    QAction *actionExport_as_Excel;
    QAction *actionExport_as_XML;
    QAction *actionCreate_Index;
    QAction *actionRe_indexar;
    QAction *actionModify_Record;
    QAction *actionSeek_Record;
    QAction *actionList_Record;
    QAction *actionDelete_Record;
    QAction *actionList_Fields;
    QWidget *centralWidget;
    QFrame *Frame_Principal;
    QPushButton *pB_NewFile;
    QPushButton *pB_OpenFile;
    QLabel *lb_Picture;
    QPushButton *pB_close;
    QFrame *frame_2;
    QLabel *label_mainPath;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuField;
    QMenu *menuRecord;
    QMenu *menuIndex;
    QMenu *menuExport;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(893, 629);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../MM/2939.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionClose_File = new QAction(MainWindow);
        actionClose_File->setObjectName(QString::fromUtf8("actionClose_File"));
        actionAdd_Field = new QAction(MainWindow);
        actionAdd_Field->setObjectName(QString::fromUtf8("actionAdd_Field"));
        actionModify_Field = new QAction(MainWindow);
        actionModify_Field->setObjectName(QString::fromUtf8("actionModify_Field"));
        actionDelete_Field = new QAction(MainWindow);
        actionDelete_Field->setObjectName(QString::fromUtf8("actionDelete_Field"));
        actionAdd_Record = new QAction(MainWindow);
        actionAdd_Record->setObjectName(QString::fromUtf8("actionAdd_Record"));
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QString::fromUtf8("actionSave_File"));
        actionExport_as_Excel = new QAction(MainWindow);
        actionExport_as_Excel->setObjectName(QString::fromUtf8("actionExport_as_Excel"));
        actionExport_as_XML = new QAction(MainWindow);
        actionExport_as_XML->setObjectName(QString::fromUtf8("actionExport_as_XML"));
        actionCreate_Index = new QAction(MainWindow);
        actionCreate_Index->setObjectName(QString::fromUtf8("actionCreate_Index"));
        actionRe_indexar = new QAction(MainWindow);
        actionRe_indexar->setObjectName(QString::fromUtf8("actionRe_indexar"));
        actionModify_Record = new QAction(MainWindow);
        actionModify_Record->setObjectName(QString::fromUtf8("actionModify_Record"));
        actionSeek_Record = new QAction(MainWindow);
        actionSeek_Record->setObjectName(QString::fromUtf8("actionSeek_Record"));
        actionList_Record = new QAction(MainWindow);
        actionList_Record->setObjectName(QString::fromUtf8("actionList_Record"));
        actionDelete_Record = new QAction(MainWindow);
        actionDelete_Record->setObjectName(QString::fromUtf8("actionDelete_Record"));
        actionList_Fields = new QAction(MainWindow);
        actionList_Fields->setObjectName(QString::fromUtf8("actionList_Fields"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Frame_Principal = new QFrame(centralWidget);
        Frame_Principal->setObjectName(QString::fromUtf8("Frame_Principal"));
        Frame_Principal->setGeometry(QRect(10, 20, 871, 501));
        QPalette palette;
        QBrush brush(QColor(200, 194, 200, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        Frame_Principal->setPalette(palette);
        Frame_Principal->setAutoFillBackground(true);
        Frame_Principal->setFrameShape(QFrame::StyledPanel);
        Frame_Principal->setFrameShadow(QFrame::Raised);
        pB_NewFile = new QPushButton(Frame_Principal);
        pB_NewFile->setObjectName(QString::fromUtf8("pB_NewFile"));
        pB_NewFile->setGeometry(QRect(90, 320, 211, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("8514oem"));
        font.setBold(true);
        font.setWeight(75);
        pB_NewFile->setFont(font);
        pB_OpenFile = new QPushButton(Frame_Principal);
        pB_OpenFile->setObjectName(QString::fromUtf8("pB_OpenFile"));
        pB_OpenFile->setGeometry(QRect(510, 320, 211, 91));
        pB_OpenFile->setFont(font);
        lb_Picture = new QLabel(Frame_Principal);
        lb_Picture->setObjectName(QString::fromUtf8("lb_Picture"));
        lb_Picture->setGeometry(QRect(0, 0, 391, 171));
        lb_Picture->setPixmap(QPixmap(QString::fromUtf8("../../../MM/tumblr_mlwrszqXtM1s8fcpbo2_r1_400.gif")));
        pB_close = new QPushButton(centralWidget);
        pB_close->setObjectName(QString::fromUtf8("pB_close"));
        pB_close->setGeometry(QRect(800, 550, 75, 23));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 540, 781, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush3(QColor(154, 147, 177, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        frame_2->setPalette(palette1);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_mainPath = new QLabel(frame_2);
        label_mainPath->setObjectName(QString::fromUtf8("label_mainPath"));
        label_mainPath->setGeometry(QRect(0, 10, 741, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 893, 21));
        QPalette palette2;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush5(QColor(25, 37, 200, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        QBrush brush7(QColor(120, 120, 120, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        menuBar->setPalette(palette2);
        menuBar->setAutoFillBackground(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuField = new QMenu(menuBar);
        menuField->setObjectName(QString::fromUtf8("menuField"));
        menuRecord = new QMenu(menuBar);
        menuRecord->setObjectName(QString::fromUtf8("menuRecord"));
        menuIndex = new QMenu(menuBar);
        menuIndex->setObjectName(QString::fromUtf8("menuIndex"));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuField->menuAction());
        menuBar->addAction(menuRecord->menuAction());
        menuBar->addAction(menuIndex->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionClose_File);
        menuFile->addAction(actionSave_File);
        menuField->addAction(actionAdd_Field);
        menuField->addAction(actionModify_Field);
        menuField->addAction(actionDelete_Field);
        menuField->addAction(actionList_Fields);
        menuRecord->addAction(actionAdd_Record);
        menuRecord->addAction(actionModify_Record);
        menuRecord->addAction(actionSeek_Record);
        menuRecord->addAction(actionList_Record);
        menuRecord->addAction(actionDelete_Record);
        menuIndex->addAction(actionCreate_Index);
        menuIndex->addAction(actionRe_indexar);
        menuExport->addAction(actionExport_as_Excel);
        menuExport->addAction(actionExport_as_XML);

        retranslateUi(MainWindow);
        QObject::connect(pB_close, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dart7FileMaker", nullptr));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", nullptr));
        actionClose_File->setText(QApplication::translate("MainWindow", "Close File", nullptr));
        actionAdd_Field->setText(QApplication::translate("MainWindow", "Add Field", nullptr));
        actionModify_Field->setText(QApplication::translate("MainWindow", "Modify Field", nullptr));
        actionDelete_Field->setText(QApplication::translate("MainWindow", "Delete Field", nullptr));
        actionAdd_Record->setText(QApplication::translate("MainWindow", "Add Record", nullptr));
        actionSave_File->setText(QApplication::translate("MainWindow", "Save File", nullptr));
        actionExport_as_Excel->setText(QApplication::translate("MainWindow", "Export as Excel", nullptr));
        actionExport_as_XML->setText(QApplication::translate("MainWindow", "Export as XML", nullptr));
        actionCreate_Index->setText(QApplication::translate("MainWindow", "Create Index", nullptr));
        actionRe_indexar->setText(QApplication::translate("MainWindow", "Re indexar", nullptr));
        actionModify_Record->setText(QApplication::translate("MainWindow", "Modify Record", nullptr));
        actionSeek_Record->setText(QApplication::translate("MainWindow", "Seek Record", nullptr));
        actionList_Record->setText(QApplication::translate("MainWindow", "List Record", nullptr));
        actionDelete_Record->setText(QApplication::translate("MainWindow", "Delete Record", nullptr));
        actionList_Fields->setText(QApplication::translate("MainWindow", "List Fields", nullptr));
        pB_NewFile->setText(QApplication::translate("MainWindow", "New File", nullptr));
        pB_OpenFile->setText(QApplication::translate("MainWindow", "Open File", nullptr));
        lb_Picture->setText(QString());
        pB_close->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_mainPath->setText(QApplication::translate("MainWindow", "No root on work", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuField->setTitle(QApplication::translate("MainWindow", "Field", nullptr));
        menuRecord->setTitle(QApplication::translate("MainWindow", "Record", nullptr));
        menuIndex->setTitle(QApplication::translate("MainWindow", "Index", nullptr));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
