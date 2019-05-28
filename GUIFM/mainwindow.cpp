#include "mainwindow.h"
#include "qfiledialog.h"
#include "file.h"
#include "ui_mainwindow.h"
#include "addfield.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    ui.setupUi(this);

    //connect(ui.pB_OpenFile, SIGNAL(()), this, SLOT(openFile()));


}

void MainWindow::openFile(){
  file.closeFile();
  QString path = QFileDialog::getSaveFileName(this, "Nuevo Archivo", QDir::currentPath(), tr("TXT Files (*.txt)"));

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

/*
MainWindow::~MainWindow()
{
    delete ui;
}
*/

void MainWindow::on_pB_NewFile_clicked(){
    openFile();

}
