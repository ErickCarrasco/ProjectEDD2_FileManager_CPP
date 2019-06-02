#include "mainwindow.h"
#include "qfiledialog.h"
#include "file.h"
#include "ui_mainwindow.h"
#include "addfield.h"
#include "deletefield.h"
#include "modfield.h"
#include <QMessageBox>
#include "ventanacampos.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    ui.setupUi(this);
    RefreshMenuBar();
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
    RefreshMenuBar();
  }else{
    qDebug() << "File path is empty or null. Aborting.";
  }
}

void MainWindow::createField(){
    addField* addF = new addField();
    addF->setFile(&file);
    addF->show();

}

void MainWindow::deleteFieldD(){
    DeleteField* deleteF = new DeleteField();
    deleteF->setFile(&file);
    deleteF->updateComboBox();
    deleteF->show();
}

void MainWindow::modifyField(){
    modField* modF = new modField();
    modF->setFile(&file);
    modF->fillElements();
    modF->show();
}

void MainWindow::saveFile(){
    if(file){
        file.setLock();
        file.flush();
        RefreshMenuBar();
    }
}

void MainWindow::closeFile(){
    if(file){
        file.closeFile();

        ui.label_mainPath->setText("File closed");
        RefreshMenuBar();
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
            RefreshMenuBar();
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

void MainWindow::on_actionDelete_Field_triggered(){
    deleteFieldD();
}

void MainWindow::on_actionList_Fields_triggered(){
    VentanaCampos* window_lec = new VentanaCampos();
    window_lec->setFields(&file);
    window_lec->show();
}

void MainWindow::on_actionModify_Field_triggered(){
    modifyField();
}

void MainWindow::RefreshMenuBar(){
    if(!file){//No loaded file
        //Blocks main functions
        ui.menuField->setEnabled(false);//Fields Blocked
        ui.menuRecord->setEnabled(false);//Records Blocked
        ui.menuIndex->setEnabled(false);//Index Blocked
        ui.menuExport->setEnabled(false);//Export Blocked
    }else{//If a file is loaded
        if(file.getLocked()){//If the file it's locked
            //Unblocks some functions
            ui.menuField->setEnabled(false);//Fields blocked
            ui.menuRecord->setEnabled(true);//Unblocks Record functions
            ui.menuIndex->setEnabled(true);//Unblocks Index functions
            ui.menuExport->setEnabled(true);//Unblocks Export functions
        }else{
            //Unblocks all functions
            ui.menuField->setEnabled(true);//Unblocks field
            ui.menuRecord->setEnabled(true);//Unblocks Record functions
            ui.menuIndex->setEnabled(true);//Unblocks Index functions
            ui.menuExport->setEnabled(true);//Unblocks Export functions
        }
    }
}





