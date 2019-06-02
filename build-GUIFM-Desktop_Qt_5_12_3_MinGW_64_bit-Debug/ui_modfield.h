/********************************************************************************
** Form generated from reading UI file 'modfield.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODFIELD_H
#define UI_MODFIELD_H

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

class Ui_modField
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QFrame *frame_3;
    QComboBox *comboBox_modField;
    QLabel *label_2;
    QLineEdit *lineEdit_modName;
    QLabel *label_3;
    QSpinBox *spinBox_modSize;
    QLabel *label_4;
    QComboBox *comboBox_modType;
    QRadioButton *radioButton_isPrimaryKey;
    QLabel *label_5;
    QPushButton *pushButton_saveChanges;

    void setupUi(QDialog *modField)
    {
        if (modField->objectName().isEmpty())
            modField->setObjectName(QString::fromUtf8("modField"));
        modField->resize(709, 292);
        frame = new QFrame(modField);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 711, 61));
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
        label->setGeometry(QRect(260, 10, 181, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Impact"));
        font.setPointSize(24);
        label->setFont(font);
        frame_2 = new QFrame(modField);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 60, 711, 231));
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
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(30, 10, 651, 201));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame_3->setPalette(palette3);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        comboBox_modField = new QComboBox(frame_3);
        comboBox_modField->setObjectName(QString::fromUtf8("comboBox_modField"));
        comboBox_modField->setGeometry(QRect(10, 10, 221, 22));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 47, 13));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Leelawadee UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        lineEdit_modName = new QLineEdit(frame_3);
        lineEdit_modName->setObjectName(QString::fromUtf8("lineEdit_modName"));
        lineEdit_modName->setGeometry(QRect(10, 70, 161, 20));
        QPalette palette4;
        QBrush brush5(QColor(150, 150, 150, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        QBrush brush6(QColor(158, 158, 158, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(156, 156, 156, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        lineEdit_modName->setPalette(palette4);
        lineEdit_modName->setAutoFillBackground(false);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 110, 47, 13));
        label_3->setFont(font1);
        spinBox_modSize = new QSpinBox(frame_3);
        spinBox_modSize->setObjectName(QString::fromUtf8("spinBox_modSize"));
        spinBox_modSize->setGeometry(QRect(200, 70, 101, 22));
        QPalette palette5;
        QBrush brush8(QColor(141, 141, 141, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush8);
        QBrush brush9(QColor(135, 135, 135, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush9);
        QBrush brush10(QColor(130, 130, 130, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        spinBox_modSize->setPalette(palette5);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 110, 61, 21));
        label_4->setFont(font1);
        comboBox_modType = new QComboBox(frame_3);
        comboBox_modType->addItem(QString());
        comboBox_modType->addItem(QString());
        comboBox_modType->addItem(QString());
        comboBox_modType->setObjectName(QString::fromUtf8("comboBox_modType"));
        comboBox_modType->setGeometry(QRect(340, 70, 131, 22));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush11(QColor(148, 148, 148, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush11);
        QBrush brush12(QColor(112, 112, 112, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush12);
        QBrush brush13(QColor(102, 102, 102, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        comboBox_modType->setPalette(palette6);
        comboBox_modType->setAutoFillBackground(false);
        radioButton_isPrimaryKey = new QRadioButton(frame_3);
        radioButton_isPrimaryKey->setObjectName(QString::fromUtf8("radioButton_isPrimaryKey"));
        radioButton_isPrimaryKey->setGeometry(QRect(530, 70, 82, 17));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 110, 101, 21));
        label_5->setFont(font1);
        pushButton_saveChanges = new QPushButton(frame_3);
        pushButton_saveChanges->setObjectName(QString::fromUtf8("pushButton_saveChanges"));
        pushButton_saveChanges->setGeometry(QRect(240, 150, 151, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        font2.setItalic(true);
        pushButton_saveChanges->setFont(font2);

        retranslateUi(modField);

        QMetaObject::connectSlotsByName(modField);
    } // setupUi

    void retranslateUi(QDialog *modField)
    {
        modField->setWindowTitle(QApplication::translate("modField", "Dialog", nullptr));
        label->setText(QApplication::translate("modField", "Modify Fields", nullptr));
        label_2->setText(QApplication::translate("modField", "Name", nullptr));
        lineEdit_modName->setText(QApplication::translate("modField", "InsertName", nullptr));
        label_3->setText(QApplication::translate("modField", "Size", nullptr));
        label_4->setText(QApplication::translate("modField", "Type", nullptr));
        comboBox_modType->setItemText(0, QApplication::translate("modField", "Integer", nullptr));
        comboBox_modType->setItemText(1, QApplication::translate("modField", "String", nullptr));
        comboBox_modType->setItemText(2, QApplication::translate("modField", "Character", nullptr));

        radioButton_isPrimaryKey->setText(QApplication::translate("modField", "Primary Key", nullptr));
        label_5->setText(QApplication::translate("modField", "Primary Key", nullptr));
        pushButton_saveChanges->setText(QApplication::translate("modField", "Save Changes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modField: public Ui_modField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODFIELD_H
