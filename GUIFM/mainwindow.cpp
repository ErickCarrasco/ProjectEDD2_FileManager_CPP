#include "mainwindow.h"
#include "qfiledialog.h"
#include "file.h"
#include "ui_mainwindow.h"
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
  }else{
    qDebug() << "File path is empty or null. Aborting.";
  }
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
