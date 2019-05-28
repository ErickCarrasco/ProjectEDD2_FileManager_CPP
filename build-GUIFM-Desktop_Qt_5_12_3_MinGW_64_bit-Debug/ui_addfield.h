/********************************************************************************
** Form generated from reading UI file 'addfield.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFIELD_H
#define UI_ADDFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_addField
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QComboBox *comboBox_type;
    QRadioButton *radioButton_isprimarykey;
    QPushButton *pb_addField_to_file;

    void setupUi(QDialog *addField)
    {
        if (addField->objectName().isEmpty())
            addField->setObjectName(QString::fromUtf8("addField"));
        addField->resize(355, 413);
        frame = new QFrame(addField);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 361, 71));
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
        label->setGeometry(QRect(120, 10, 111, 41));
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
        font.setFamily(QString::fromUtf8("Bahnschrift"));
        font.setPointSize(22);
        font.setItalic(false);
        label->setFont(font);
        frame_2 = new QFrame(addField);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 80, 331, 321));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame_2->setPalette(palette2);
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 61, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        label_2->setFont(font1);
        lineEdit_name = new QLineEdit(frame_2);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(30, 40, 231, 21));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 61, 16));
        label_3->setFont(font1);
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 110, 231, 22));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 150, 61, 16));
        label_4->setFont(font1);
        comboBox_type = new QComboBox(frame_2);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
        comboBox_type->setGeometry(QRect(30, 180, 231, 21));
        radioButton_isprimarykey = new QRadioButton(frame_2);
        radioButton_isprimarykey->setObjectName(QString::fromUtf8("radioButton_isprimarykey"));
        radioButton_isprimarykey->setGeometry(QRect(30, 220, 221, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        radioButton_isprimarykey->setFont(font2);
        pb_addField_to_file = new QPushButton(frame_2);
        pb_addField_to_file->setObjectName(QString::fromUtf8("pb_addField_to_file"));
        pb_addField_to_file->setGeometry(QRect(120, 262, 91, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pb_addField_to_file->setPalette(palette3);
        pb_addField_to_file->setFont(font1);

        retranslateUi(addField);

        QMetaObject::connectSlotsByName(addField);
    } // setupUi

    void retranslateUi(QDialog *addField)
    {
        addField->setWindowTitle(QApplication::translate("addField", "Dialog", nullptr));
        label->setText(QApplication::translate("addField", "Add Field", nullptr));
        label_2->setText(QApplication::translate("addField", "Name", nullptr));
        label_3->setText(QApplication::translate("addField", "Size", nullptr));
        label_4->setText(QApplication::translate("addField", "Type", nullptr));
        comboBox_type->setItemText(0, QApplication::translate("addField", "Integer", nullptr));
        comboBox_type->setItemText(1, QApplication::translate("addField", "String", nullptr));
        comboBox_type->setItemText(2, QApplication::translate("addField", "Char", nullptr));

        radioButton_isprimarykey->setText(QApplication::translate("addField", "Primary Key", nullptr));
        pb_addField_to_file->setText(QApplication::translate("addField", "Add ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addField: public Ui_addField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFIELD_H
