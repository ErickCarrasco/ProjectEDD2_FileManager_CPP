#include "displayrecords.h"
#include "ui_displayrecords.h"

DisplayRecords::DisplayRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayRecords)
{

    ui->setupUi(this);
    //QHeaderView* header = ui->tableWidget->horizontalHeader();
    //header->setSectionResizeMode(QHeaderView::Stretch);
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

    List<Field> fieldsEx = file->getFields();
    if(fieldsEx.size>0){
        for(int i = 1; i<=fieldsEx.size;i++){
            ui->tableWidget->setHorizontalHeaderItem(i-1, new QTableWidgetItem(QString::fromStdString(fieldsEx.get(i).getName())));
        }

        if(file->getLocked()){
            qDebug()<<"On progress";

            List<List<string>> records = file->data();//Extraer los records del bloque actual de file

            if(records.size<=0){
                ui->tableWidget->setRowCount(1);
            }else{
                ui->tableWidget->setRowCount(records.size);
            }

            if(records.size>0){

                for(int i =1; i<=records.size;i++){
                    qDebug()<<"On progress by Record ";
                    for(int j =1; j<= fieldsEx.size;j++){
                        qDebug()<<"On progress per field";
                        if(records[i][1][0]=='*'){

                            ui->tableWidget->setItem(i-1, j-1, new QTableWidgetItem("-"));
                        }else{
                            ui->tableWidget->setItem(i-1, j-1, new QTableWidgetItem(records[i][j].c_str()));
                            qDebug()<<QString::fromStdString(records[i][j].c_str());
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
