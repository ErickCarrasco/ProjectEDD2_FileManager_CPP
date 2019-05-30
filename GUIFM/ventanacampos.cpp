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

void VentanaCampos::setFields(File* file){

    ui->Field_Table->setRowCount(file->getFields().size);
    for (int i = 1;i<=file->getFields().size;i++) {

        //ui->Field_Table->setItem(i-1,0, new QTableWidgetItem(QString::fromStdString(file->getFields().get(i).getName())));
        if(file->getFields().get(i).getType()==0){
            ui->Field_Table->setItem(i-1,0, new QTableWidgetItem("Integer"));
        }else if(file->getFields().get(i).getType()==1){
            ui->Field_Table->setItem(i-1,0, new QTableWidgetItem("String"));
        }else if (file->getFields().get(i).getType()==2) {
            ui->Field_Table->setItem(i-1,0, new QTableWidgetItem("Character"));
        }
        ui->Field_Table->setItem(i-1,1, new QTableWidgetItem(QString::fromStdString(file->getFields().get(i).getName())));
        ui->Field_Table->setItem(i-1,2, new QTableWidgetItem(QString::number(file->getFields().get(i).getSize())));
        if(file->getFields().get(i).getIsPrimaryKey()){
            ui->Field_Table->setItem(i-1,3, new QTableWidgetItem("Yes"));
        }else{
            ui->Field_Table->setItem(i-1,3, new QTableWidgetItem("No"));
        }

    }
    file=0;
    delete file;

}

void VentanaCampos::on_pushButton_clicked()
{
    VentanaCampos::close();
}
