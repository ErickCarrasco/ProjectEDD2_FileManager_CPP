#include "modrecord.h"
#include "ui_modrecord.h"

modRecord::modRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modRecord)
{
    ui->setupUi(this);
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    dataLoaded=false;
}

modRecord::~modRecord(){
    delete ui;
}

void modRecord::setFile(File* nFile){
    file = nFile;
    ui->tableWidget->setColumnCount(file->getFields().size);
    ui->tableWidget->setRowCount(1);
    QStringList headers;
    for(int i=1; i<=file->getFields().size; i++){
         headers<<QString::fromStdString(file->getFields().get(i).getName());
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void modRecord::on_pushButton_loadData_modRecordData_clicked(){
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

void modRecord::on_pushButton_ModActualRecord_clicked(){
    if(dataLoaded){
        if(indexRecord!=0){
            file->deleteRecord(indexRecord);//Deletes current modified field
            List<string> overwrite;//List to overwrite the data
            for (int i=1; i<=file->getFields().size; i++){//Extracting new data
                QString extractedData = ui->tableWidget->takeItem(0,i-1)->text();

                if(extractedData.isNull()){//If it is null, a char will be added instead
                    overwrite.insert("-");
                }else{//Otherwise it saves the data extracted
                    overwrite.insert(extractedData.toStdString());
                }
            }
            if(file->addRecord(overwrite)){
                QMessageBox::about(this,"Update","Record has been modified");
                for(int i=1; i<=file->getFields().size; i++){ //Deletes any change made on the table
                    ui->tableWidget->setItem(0,i-1, new QTableWidgetItem(""));
                }
                file->flush();
            }else{
                QMessageBox::warning(this, "Error", "Record could not be edited");
            }
            indexRecord = 0;

        }
    }
}
