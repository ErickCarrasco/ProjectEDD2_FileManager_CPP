#include "ventanacampos.h"
#include "ui_ventanacampos.h"

VentanaCampos::VentanaCampos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaCampos)
{
    ui->setupUi(this);
}

VentanaCampos::~VentanaCampos()
{
    delete ui;
}

void VentanaCampos::on_pushButton_clicked()
{
    VentanaCampos::close();
}
