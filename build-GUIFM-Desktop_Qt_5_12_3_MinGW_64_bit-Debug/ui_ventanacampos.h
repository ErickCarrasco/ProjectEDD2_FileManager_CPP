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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaCampos
{
public:
    QPushButton *pushButton;
    QTableWidget *Field_Table;

    void setupUi(QDialog *VentanaCampos)
    {
        if (VentanaCampos->objectName().isEmpty())
            VentanaCampos->setObjectName(QString::fromUtf8("VentanaCampos"));
        VentanaCampos->resize(400, 300);
        pushButton = new QPushButton(VentanaCampos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 10, 75, 23));
        Field_Table = new QTableWidget(VentanaCampos);
        if (Field_Table->columnCount() < 4)
            Field_Table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Field_Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Field_Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Field_Table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Field_Table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Field_Table->setObjectName(QString::fromUtf8("Field_Table"));
        Field_Table->setGeometry(QRect(10, 50, 381, 231));

        retranslateUi(VentanaCampos);

        QMetaObject::connectSlotsByName(VentanaCampos);
    } // setupUi

    void retranslateUi(QDialog *VentanaCampos)
    {
        VentanaCampos->setWindowTitle(QApplication::translate("VentanaCampos", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("VentanaCampos", "Listo", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Field_Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("VentanaCampos", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Field_Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("VentanaCampos", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Field_Table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("VentanaCampos", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Field_Table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("VentanaCampos", "Is Primary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaCampos: public Ui_VentanaCampos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACAMPOS_H
