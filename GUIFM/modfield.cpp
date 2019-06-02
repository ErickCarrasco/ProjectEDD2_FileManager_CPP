#include "modfield.h"
#include "ui_modfield.h"

modField::modField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modField){
    ui->setupUi(this);
}

modField::~modField(){
    delete ui;
}

void modField::setFile(File* nFile){
    file = nFile;
}

void modField::fillElements(){
    ui->comboBox_modField->clear();
    QStringList items;
    for(int i = 1; i <= file->getFields().size; i++){
        items<<QString::fromStdString(file->getFields().get(i).getName());
    }
    ui->comboBox_modField->addItems(items);
}



void modField::on_pushButton_saveChanges_clicked(){
    if(!file->getLocked()){//Checks if file is not locked
        if(ui->lineEdit_modName->text()!=""){//Must contain name
            file->getFieldsLocation()->getPointer(ui->comboBox_modField->currentIndex()+1)->setName(ui->lineEdit_modName->text().toStdString());
        }
        if(ui->spinBox_modSize->value()!=file->getFields().get(ui->comboBox_modField->currentIndex()+1).getSize()){//Must have a size to save
            file->getFieldsLocation()->getPointer(ui->comboBox_modField->currentIndex()+1)->setSize(ui->spinBox_modSize->value());
        }
        if(ui->comboBox_modType->currentIndex()!=file->getFields().get(ui->comboBox_modField->currentIndex()+1).getType()){//Must have a type
            file->getFieldsLocation()->getPointer(ui->comboBox_modField->currentIndex()+1)->setType(ui->comboBox_modField->currentIndex());

        }
        if(ui->radioButton_isPrimaryKey->isChecked()!=file->getFields().get(ui->comboBox_modField->currentIndex()+1).getIsPrimaryKey()){
            if(!file->hasPrimaryKey()){
                file->getFieldsLocation()->getPointer(ui->comboBox_modField->currentIndex()+1)->setPrimaryKey(true);
            }else{
                QMessageBox::warning(this,"Warning!", "Can't have multiple primary keys");
            }
        }

    }else{
        QMessageBox::warning(this,"Warning!", "File is blocked, can't edit data");
    }
    fillElements();

}

void modField::on_comboBox_modField_currentIndexChanged(int index){//Helps loading the data into the elements
    qDebug()<<"Loaded";
    if(index>=0){
        ui->lineEdit_modName->setText(QString::fromStdString(file->getFields().get(index+1).getName()));
        if(file->getFields().get(index + 1).getIsPrimaryKey()){
            ui->radioButton_isPrimaryKey->setChecked(true);
        }else{
            ui->radioButton_isPrimaryKey->setChecked(false);
        }
        ui->spinBox_modSize->setValue(file->getFields().get(index + 1).getSize());

        if(file->getFields().get(index + 1).getType()==0){//Type integer
            ui->comboBox_modType->setCurrentIndex(0);
        }else if(file->getFields().get(index + 1).getType()==1){//Type String
            ui->comboBox_modType->setCurrentIndex(1);
        }else{//Type Character
            ui->comboBox_modType->setCurrentIndex(2);
        }
    }
}
