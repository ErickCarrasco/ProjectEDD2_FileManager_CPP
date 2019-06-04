#include "deleterecord.h"
#include "ui_deleterecord.h"
#include <QMessageBox>

deleteRecord::deleteRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteRecord)
{
    ui->setupUi(this);
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    dataLoaded=false;
}

deleteRecord::~deleteRecord()
{
    delete ui;
}

void deleteRecord::setFile(File* nFile){
    file = nFile;
    ui->tableWidget->setColumnCount(file->getFields().size);
    ui->tableWidget->setRowCount(1);
    QStringList headers;
    for(int i=1; i<=file->getFields().size; i++){
         headers<<QString::fromStdString(file->getFields().get(i).getName());
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);


}



void deleteRecord::on_pushButton_loadData_DeleteRecord_clicked(){
    dataLoaded=true;//Boolean that allows the deletion to be completed
    indexRecord = ui->spinBox->value();//Gets the record indicated by the user
    if(indexRecord!=0){
        record = file->getRecord(indexRecord);
        for (int i = 1; i<=file->getFields().size; i++) {//Fills the table with the record data
            qDebug()<<QString::fromStdString(record.get(i));
            ui->tableWidget->setItem(0,i-1, new QTableWidgetItem(QString::fromStdString(record.get(i))));
        }
        record.clear();
    }

}

void deleteRecord::on_pushButton_DeleteActualRecord_clicked(){
    if(dataLoaded){//Just for user safety
        QMessageBox::StandardButton answer = QMessageBox::question(this,"Attention!","Delete the following record?", QMessageBox::Yes | QMessageBox::No);
        if(answer == QMessageBox::Yes){
            file->deleteRecord(ui->spinBox->value());
            QMessageBox::about(this, "Success","Record deletion completed");
            for(int i=1; i<=file->getFields().size; i++){
                ui->tableWidget->setItem(0,i-1, new QTableWidgetItem(""));
            }
        }
    }else{
        QMessageBox::warning(this,"","It is risky to delete a record without knowing the data");
    }

}
