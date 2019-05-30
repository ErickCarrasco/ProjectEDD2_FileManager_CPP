#include "mainwindow.h"
#include "qfiledialog.h"
#include "file.h"
#include "ui_mainwindow.h"
#include "addfield.h"
#include <QMessageBox>
#include "ventanacampos.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    ui.setupUi(this);

    //connect(ui.pB_OpenFile, SIGNAL(()), this, SLOT(openFile()));


}

void MainWindow::openFile(){
  file.closeFile();
  QString path = QFileDialog::getSaveFileName(this, "New File", QDir::currentPath(), tr("TXT Files (*.txt)"));

  if (!path.isEmpty() && !path.isNull()) {
    remove(path.toStdString().c_str());
    remove(string(path.toStdString() + ".index").c_str());
    file.openFile(path.toStdString());
    ui.label_mainPath->setText(path);
    ui.Frame_Principal->hide();
  }else{
    qDebug() << "File path is empty or null. Aborting.";
  }
}

void MainWindow::createField(){
    addField* addF = new addField();
    addF->setFile(&file);
    addF->show();

}

void MainWindow::saveFile(){
    if(file){
        file.setLock();
        file.flush();
    }
}

//void MainWindow::listarField(){
    /*addField* addF = new addField();
    addF->setFile(&file);
    addF->show();*/

//}

void MainWindow::closeFile(){
    if(file){
        file.closeFile();

        ui.label_mainPath->setText("File closed");
        ui.Frame_Principal->show();

    }
}

void MainWindow::loadFile(){
    QString path = QFileDialog::getOpenFileName(this, "Load File", QDir::currentPath(), tr("TXT Files (*.txt)"));
    if(!path.isEmpty() && !path.isNull()){
        if(file.openFile(path.toStdString())){
            QMessageBox::warning(this,"Attention", "Loading file..");
            ui.Frame_Principal->hide();
            file.setLock();
            ui.label_mainPath->setText(path);
        }
    }else{
        QMessageBox::warning(this,"Attention", "Process Killed..");
        qDebug()<<"Couldn't find file. Killing process..";
    }
}


void MainWindow::on_pB_NewFile_clicked(){
    openFile();

}

void MainWindow::on_actionSave_File_triggered(){
    saveFile();
}

void MainWindow::on_actionAdd_Field_triggered(){
    createField();
}

void MainWindow::on_actionClose_File_triggered(){
    closeFile();
}

void MainWindow::on_pB_OpenFile_clicked(){
    loadFile();
}

void MainWindow::on_actionOpen_File_triggered(){
    loadFile();
}

void MainWindow::on_actionList_Fields_triggered()
{
    VentanaCampos* window_lec = new VentanaCampos();
    window_lec->setFields(&file);
    window_lec->show();
}

