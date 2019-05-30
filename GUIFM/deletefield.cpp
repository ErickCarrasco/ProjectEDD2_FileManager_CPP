#include "deletefield.h"
#include "ui_deletefield.h"
#include <QMessageBox>

DeleteField::DeleteField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteField)
{
    ui->setupUi(this);
}

DeleteField::~DeleteField()
{
    delete ui;
}

void DeleteField::setFile(File* pFile){
    file = pFile;
}

void DeleteField::updateComboBox(){
    ui->comboBox_fields->clear();
    //Updates combo box with current fields on memory
    QStringList fieldItems;
    for (int i = 1;i <= file->getFields().size;i++) {
        fieldItems<<QString::fromStdString(file->getFields().get(i).getName());
    }
    ui->comboBox_fields->addItems(fieldItems);
    //Adds all fields to the combo box
}

void DeleteField::on_pB_deletefieldButton_clicked(){
    if(!file->getLocked()){
        QMessageBox::StandardButton answer = QMessageBox::question(this,"","Are you sure you want to delete this field?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            if(file->deleteField(ui->comboBox_fields->currentIndex()+1)){
                QMessageBox::about(this,"","Field deleted ");
                updateComboBox();
            }
        }

    }else{
        QMessageBox::warning(this,"","The file is encrypted");
    }

}
