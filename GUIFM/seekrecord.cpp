#include "seekrecord.h"
#include "ui_seekrecord.h"

seekRecord::seekRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seekRecord)
{
    ui->setupUi(this);
}

seekRecord::~seekRecord()
{
    delete ui;
}

void seekRecord::setFile(File* nfile){
    fileS = nfile;
}



void seekRecord::on_pushButton_clicked(){
    if(fileS->RecordSeeker(ui->lineEdit_keyData->text().toStdString())){
        QMessageBox::about(this,"Located", "Record located. Refresh table");
    }else{
        QMessageBox::about(this,"Not found", "Couldn't found record");
    }

}
