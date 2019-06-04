/********************************************************************************
** Form generated from reading UI file 'modrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODRECORD_H
#define UI_MODRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_modRecord
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QTableWidget *tableWidget;
    QFrame *frame_3;
    QSpinBox *spinBox;
    QPushButton *pushButton_ModActualRecord;
    QPushButton *pushButton_loadData_modRecordData;

    void setupUi(QDialog *modRecord)
    {
        if (modRecord->objectName().isEmpty())
            modRecord->setObjectName(QString::fromUtf8("modRecord"));
        modRecord->resize(577, 308);
        frame = new QFrame(modRecord);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 581, 51));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame->setPalette(palette);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 10, 151, 21));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("ISOCPEUR"));
        font.setPointSize(18);
        font.setItalic(true);
        label->setFont(font);
        frame_2 = new QFrame(modRecord);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 50, 581, 261));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush3(QColor(163, 163, 163, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        frame_2->setPalette(palette2);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        tableWidget = new QTableWidget(frame_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 20, 451, 121));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(110, 180, 351, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame_3->setPalette(palette3);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(frame_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 10, 41, 21));
        pushButton_ModActualRecord = new QPushButton(frame_3);
        pushButton_ModActualRecord->setObjectName(QString::fromUtf8("pushButton_ModActualRecord"));
        pushButton_ModActualRecord->setGeometry(QRect(240, 10, 75, 23));
        pushButton_loadData_modRecordData = new QPushButton(frame_3);
        pushButton_loadData_modRecordData->setObjectName(QString::fromUtf8("pushButton_loadData_modRecordData"));
        pushButton_loadData_modRecordData->setGeometry(QRect(130, 10, 75, 23));

        retranslateUi(modRecord);

        QMetaObject::connectSlotsByName(modRecord);
    } // setupUi

    void retranslateUi(QDialog *modRecord)
    {
        modRecord->setWindowTitle(QApplication::translate("modRecord", "Dialog", nullptr));
        label->setText(QApplication::translate("modRecord", "Modify Record", nullptr));
        pushButton_ModActualRecord->setText(QApplication::translate("modRecord", "Modify", nullptr));
        pushButton_loadData_modRecordData->setText(QApplication::translate("modRecord", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modRecord: public Ui_modRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODRECORD_H
