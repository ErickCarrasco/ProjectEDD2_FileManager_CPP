#include "displayrecords.h"
#include "ui_displayrecords.h"

DisplayRecords::DisplayRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayRecords)
{

    ui->setupUi(this);
}

DisplayRecords::~DisplayRecords(){
    delete ui;
}

void DisplayRecords::setFile(File* nFile){
    file = nFile;
    //file->flush();
    //file->recSeek();
}

void DisplayRecords::refreshTableData(){
    //file->flush();
    //file->recSeek();
    ui->tableWidget->setColumnCount(file->fieldQuantity());//Column quantity according to the field quantity
    for(int i =0;i< file->getBlockSize();i++){
        int index = ((file->getCurrentBlock()-1)*file->getBlockSize()) + i + 1;
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(to_string(index).c_str()));
    }
    List<Field> fields = file->getFields();
    if(fields.size>0){
        for(int i = 1; i<=fields.size;i++){
            ui->tableWidget->setHorizontalHeaderItem(i-1, new QTableWidgetItem(QString::fromStdString(fields.get(i).getName())));
        }

        if(file->getLocked()){
            List<List<string>> records = file->data();//Extraer los records del bloque actual de file

            if(records.size<=0){
                ui->tableWidget->setRowCount(1);
            }else{
                ui->tableWidget->setRowCount(records.size);
            }

            if(records.size>0){
                for(int i =1; i<=records.size;i++){
                    for(int j =1; j<= fields.size;i++){
                        if(records[i][1][0]=='*'){
                            ui->tableWidget->setItem(i-1, j-1, new QTableWidgetItem("EMPTY"));
                        }else{
                            ui->tableWidget->setItem(i-1, j-1, new QTableWidgetItem(records[i][j].c_str()));
                        }
                    }
                }

                //Actualizar label de pagina
                QString page;
                page+=to_string(file->getCurrentBlock()).c_str();
                page+="/";
                page+=to_string(file->blockQuantity()).c_str();
                ui->label_NumberPage->setText(page);
            }

        }
    }
}

void DisplayRecords::on_pushButton_refreshTabe_clicked(){
    refreshTableData();
}
