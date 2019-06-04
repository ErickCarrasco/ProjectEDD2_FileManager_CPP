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
    if(!file->getLocked()){
        if(ui->lineEdit_name->text()!=""){
            if(ui->radioButton_isprimarykey->isChecked()&&file->hasPrimaryKey()){
                QMessageBox::warning(this,"WARNING!", "Primary Key Already exists..");
            }else{
                int type;
                //type=0;
                QString nametext = ui->lineEdit_name->text();
                if(ui->comboBox_type->currentText()=="Character"){
                    type=2;
                }else if (ui->comboBox_type->currentText()=="String") {
                    type=1;
                }else{
                    type=0;
                }
                file->addField(type,nametext.toStdString(),ui->spinBox->value(), ui->radioButton_isprimarykey->isChecked());
                QMessageBox::about(this,"Success", "A new field was added");
                ui->lineEdit_name->setText("");
                ui->spinBox->setValue(0);
                ui->radioButton_isprimarykey->setChecked(false);
                ui->comboBox_type->setCurrentIndex(0);

            }
        }

    }else{
        QMessageBox::warning(this,"WARNING!", "Archivo bloqueado");
    }
}
