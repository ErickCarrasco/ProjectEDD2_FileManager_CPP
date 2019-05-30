/********************************************************************************
** Form generated from reading UI file 'ventanacampos.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANACAMPOS_H
#define UI_VENTANACAMPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VentanaCampos
{
public:
    QListView *listFields;
    QPushButton *pushButton;

    void setupUi(QDialog *VentanaCampos)
    {
        if (VentanaCampos->objectName().isEmpty())
            VentanaCampos->setObjectName(QString::fromUtf8("VentanaCampos"));
        VentanaCampos->resize(400, 300);
        listFields = new QListView(VentanaCampos);
        listFields->setObjectName(QString::fromUtf8("listFields"));
        listFields->setGeometry(QRect(40, 60, 256, 192));
        pushButton = new QPushButton(VentanaCampos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 40, 75, 23));

        retranslateUi(VentanaCampos);

        QMetaObject::connectSlotsByName(VentanaCampos);
    } // setupUi

    void retranslateUi(QDialog *VentanaCampos)
    {
        VentanaCampos->setWindowTitle(QApplication::translate("VentanaCampos", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("VentanaCampos", "Listo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaCampos: public Ui_VentanaCampos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACAMPOS_H
