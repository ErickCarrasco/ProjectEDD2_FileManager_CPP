/********************************************************************************
** Form generated from reading UI file 'displayrecords.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYRECORDS_H
#define UI_DISPLAYRECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayRecords
{
public:
    QTableWidget *tableWidget;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QFrame *frame_3;
    QPushButton *pushButton_SearchRecord;
    QPushButton *pushButton_previousPage;
    QFrame *frame_4;
    QLabel *label_NumberPage;
    QPushButton *pushButton_nextPage;
    QPushButton *pushButton_refreshTabe;

    void setupUi(QWidget *DisplayRecords)
    {
        if (DisplayRecords->objectName().isEmpty())
            DisplayRecords->setObjectName(QString::fromUtf8("DisplayRecords"));
        DisplayRecords->resize(824, 585);
        tableWidget = new QTableWidget(DisplayRecords);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 70, 781, 461));
        frame = new QFrame(DisplayRecords);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 831, 61));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame->setPalette(palette);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 10, 121, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("ISOCPEUR"));
        font.setPointSize(26);
        font.setItalic(true);
        label->setFont(font);
        frame_2 = new QFrame(DisplayRecords);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 60, 831, 531));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(106, 106, 106, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        frame_2->setPalette(palette2);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(60, 480, 711, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush4(QColor(0, 136, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        frame_3->setPalette(palette3);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_SearchRecord = new QPushButton(frame_3);
        pushButton_SearchRecord->setObjectName(QString::fromUtf8("pushButton_SearchRecord"));
        pushButton_SearchRecord->setGeometry(QRect(30, 10, 75, 23));
        pushButton_previousPage = new QPushButton(frame_3);
        pushButton_previousPage->setObjectName(QString::fromUtf8("pushButton_previousPage"));
        pushButton_previousPage->setGeometry(QRect(210, 10, 41, 23));
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(270, 0, 91, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame_4->setPalette(palette4);
        frame_4->setAutoFillBackground(true);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_NumberPage = new QLabel(frame_4);
        label_NumberPage->setObjectName(QString::fromUtf8("label_NumberPage"));
        label_NumberPage->setGeometry(QRect(20, 10, 51, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        label_NumberPage->setFont(font1);
        label_NumberPage->setAlignment(Qt::AlignCenter);
        pushButton_nextPage = new QPushButton(frame_3);
        pushButton_nextPage->setObjectName(QString::fromUtf8("pushButton_nextPage"));
        pushButton_nextPage->setGeometry(QRect(380, 10, 41, 23));
        pushButton_refreshTabe = new QPushButton(frame_3);
        pushButton_refreshTabe->setObjectName(QString::fromUtf8("pushButton_refreshTabe"));
        pushButton_refreshTabe->setGeometry(QRect(550, 10, 75, 23));
        frame_2->raise();
        tableWidget->raise();
        frame->raise();

        retranslateUi(DisplayRecords);

        QMetaObject::connectSlotsByName(DisplayRecords);
    } // setupUi

    void retranslateUi(QWidget *DisplayRecords)
    {
        DisplayRecords->setWindowTitle(QApplication::translate("DisplayRecords", "Form", nullptr));
        label->setText(QApplication::translate("DisplayRecords", "Records", nullptr));
        pushButton_SearchRecord->setText(QApplication::translate("DisplayRecords", "Search", nullptr));
        pushButton_previousPage->setText(QApplication::translate("DisplayRecords", "Prev", nullptr));
        label_NumberPage->setText(QApplication::translate("DisplayRecords", "-", nullptr));
        pushButton_nextPage->setText(QApplication::translate("DisplayRecords", "Next", nullptr));
        pushButton_refreshTabe->setText(QApplication::translate("DisplayRecords", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayRecords: public Ui_DisplayRecords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYRECORDS_H
