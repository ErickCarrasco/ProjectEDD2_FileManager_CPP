#include "addrecord.h"
#include "ui_addrecord.h"
#include "linkedlist.h"
#include "file.h"
#include "QTableWidgetItem"
#include <QMessageBox>

addRecord::addRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRecord)
{
    ui->setupUi(this);
    ui->tableWidget_addRecords->insertRow(ui->tableWidget_addRecords->rowCount());
}

addRecord::~addRecord(){
    delete ui;
}

void addRecord::setFile(File* nFile){
    file = nFile;
}

void addRecord::addFields(){
    ui->tableWidget_addRecords->setRowCount(file->getFields().size);
    for(int i =1; i<=file->getFields().size; i++){
        ui->tableWidget_addRecords->setItem(i-1, 0, new QTableWidgetItem(QString::fromStdString(file->getFields().get(i).getName())));
        //ui->tableWidget_addRecords->setItem(i-1, 1, new  QTableWidgetItem(QString::number(file->getFields().get(i).getSize())));
        if(file->getFields().get(i).getType()==0){
            ui->tableWidget_addRecords->setItem(i-1, 1, new QTableWidgetItem("Integer"));
        }else if(file->getFields().get(i).getType()==1){
            ui->tableWidget_addRecords->setItem(i-1, 1, new QTableWidgetItem("String"));
        }else{
            ui->tableWidget_addRecords->setItem(i-1, 1, new QTableWidgetItem("Character"));
        }
    }
}


void addRecord::on_pushButton_addRecord_to_file_clicked(){
    QMessageBox::StandardButton answer = QMessageBox::Yes;
    bool dataSaved=true;
    if(!file->getLocked()){//If file is not locked, it must be saved to add records
        answer = QMessageBox::question(this, "Update", "Do you want to save the file? Doing so will block the fields", QMessageBox::Yes|QMessageBox::No);
    }
    if(answer == QMessageBox::Yes){//If the file is locked, records can be added
        if(file->getFields().size>0){//Fields should exist

            List<string> values;
            QString singleV;
            QTableWidgetItem* item;
            string itemValueString;
            for (int i = 1;i<=file->getFields().size;i++) {
                item = ui->tableWidget_addRecords->takeItem(i-1,2);
                singleV = item->text();
                itemValueString=(singleV.toStdString());
                if(file->getFields().get(i).getType()==0 && !validateTypeInteger(item->text())){
                    QMessageBox::warning(this,"ERROR", "Could not add record, check that the entered data matches its type");
                    dataSaved=false;
                    break;
                }

                /*
                if(file->getFields().get(i).getIsPrimaryKey()){
                    for (int j = 1;j<=file->getRecordSize();j++) {
                        List<string> recordComparer;
                        recordComparer= file->getRecord(j);
                        string keyComparison="";
                        for(int k = 1; k<=file->getFields().size;i++){
                            if(file->getFields().get(k).getIsPrimaryKey()){
                                keyComparison = recordComparer.get(k);
                                qDebug()<<"keyComparison: "<<QString::fromStdString(keyComparison);
                            }
                            while(int(itemValueString.length())<primaryKeySize){
                                qDebug()<<"Executing data";
                                itemValueString+=" ";
                            }
                            qDebug()<<"Executing data";
                            if(keyComparison==itemValueString){
                                qDebug()<<"Executing data";
                                QMessageBox::warning(this,"ERROR", "Could not add record, check that the entered data matches its type");
                                qDebug()<<"Executing data";
                                dataSaved=false;
                                break;
                            }
                        }

                    }
                }
                */
                //qDebug()<<"Value: "<<i<<": "<<singleV;
                values.insert(singleV.toStdString());
            }
            if(dataSaved){
                QMessageBox::about(this, "Process Completed", "Data has been saved");
                for (int i = 1; i<=values.size;i++) {
                    string out = values.get(i);
                    //qDebug()<<"Value: "<<i<< "Data: "<<QString::fromStdString(out);
                }
                file->addRecord(values);
                file->flush();
            }


        }

    }

}

bool addRecord::validateTypeInteger(QString intString){
    for (int i = 0;i< intString.size(); i++) {
        if(intString[i]<48||intString[i]>57){
            return false;
        }
    }
    return true;
}
