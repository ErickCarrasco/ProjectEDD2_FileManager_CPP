#include "ventanacampos.h"
#include "ui_ventanacampos.h"

VentanaCampos::VentanaCampos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaCampos)
{
    ui->setupUi(this);
    ui->Field_Table->insertRow(ui->Field_Table->rowCount());
    //ui->Field_Table->setItem((ui->Field_Table->rowCount() - 1, 0, );
}

VentanaCampos::~VentanaCampos()
{
    delete ui;
}

void VentanaCampos::on_pushButton_clicked()
{
    VentanaCampos::close();
}
