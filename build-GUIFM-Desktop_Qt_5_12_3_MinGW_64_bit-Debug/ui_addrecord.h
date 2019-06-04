/********************************************************************************
** Form generated from reading UI file 'addrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECORD_H
#define UI_ADDRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_addRecord
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QTableWidget *tableWidget_addRecords;
    QPushButton *pushButton_addRecord_to_file;
    QFrame *frame_3;
    QLabel *label_2;

    void setupUi(QDialog *addRecord)
    {
        if (addRecord->objectName().isEmpty())
            addRecord->setObjectName(QString::fromUtf8("addRecord"));
        addRecord->resize(789, 531);
        frame = new QFrame(addRecord);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 791, 81));
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
        label->setGeometry(QRect(270, 20, 211, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        frame_2 = new QFrame(addRecord);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 80, 791, 451));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame_2->setPalette(palette2);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        tableWidget_addRecords = new QTableWidget(frame_2);
        if (tableWidget_addRecords->columnCount() < 3)
            tableWidget_addRecords->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_addRecords->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_addRecords->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_addRecords->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_addRecords->setObjectName(QString::fromUtf8("tableWidget_addRecords"));
        tableWidget_addRecords->setGeometry(QRect(10, 10, 761, 371));
        tableWidget_addRecords->horizontalHeader()->setDefaultSectionSize(240);
        pushButton_addRecord_to_file = new QPushButton(frame_2);
        pushButton_addRecord_to_file->setObjectName(QString::fromUtf8("pushButton_addRecord_to_file"));
        pushButton_addRecord_to_file->setGeometry(QRect(630, 410, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("ISOCPEUR"));
        font1.setPointSize(16);
        font1.setItalic(true);
        pushButton_addRecord_to_file->setFont(font1);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 400, 461, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(158, 158, 158, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        frame_3->setPalette(palette3);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 10, 371, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("ISOCPEUR"));
        font2.setPointSize(12);
        font2.setItalic(true);
        label_2->setFont(font2);

        retranslateUi(addRecord);

        QMetaObject::connectSlotsByName(addRecord);
    } // setupUi

    void retranslateUi(QDialog *addRecord)
    {
        addRecord->setWindowTitle(QApplication::translate("addRecord", "Dialog", nullptr));
        label->setText(QApplication::translate("addRecord", "Add Record", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_addRecords->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addRecord", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_addRecords->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addRecord", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_addRecords->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("addRecord", "Insert Data", nullptr));
        pushButton_addRecord_to_file->setText(QApplication::translate("addRecord", "Accept", nullptr));
        label_2->setText(QApplication::translate("addRecord", "Ingresar los datos a guardar en la columna \"Insert Data\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addRecord: public Ui_addRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECORD_H
