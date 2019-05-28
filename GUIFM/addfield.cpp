#include "addfield.h"
#include "ui_addfield.h"

addField::addField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addField)
{
    ui->setupUi(this);
}

addField::~addField(){
    delete ui;
}

void addField::setFile(File* con){
    file = con;
}

void addField::on_pb_addField_to_file_clicked(){

}
