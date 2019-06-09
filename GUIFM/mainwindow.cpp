#include "mainwindow.h"
#include "qfiledialog.h"
#include "file.h"
#include "ui_mainwindow.h"
#include "addfield.h"
#include "deletefield.h"
#include "modfield.h"
#include "addrecord.h"
#include "deleterecord.h"
#include "modrecord.h"
#include "displayrecords.h"
#include <QMessageBox>
#include "ventanacampos.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){
    ui.setupUi(this);
    ui.label_5->setText("");
    ui.label_6->setText("");
    ui.label_7->setText("");
    ui.label_8->setText("");
    RefreshMenuBar();



}

void MainWindow::openFile(){
  file.closeFile();
  QString path = QFileDialog::getSaveFileName(this, "New File", QDir::currentPath(), tr("TXT Files (*.txt)"));
  if (!path.isEmpty() && !path.isNull()) {
    remove(path.toStdString().c_str());
    remove(string(path.toStdString() + ".index").c_str());
    file.openFile(path.toStdString());
    ui.label_mainPath->setText(path);
    ui.label_5->setText("Instructions field: Crear, modificar, eliminar, y listar campos \n *En caso de no estar disponible, el archivo esta bloqueado y no podra agregar "
                        "mas campos*");
    ui.label_6->setText("Instructios Record: Agregar, modificar, eliminar y visualizar registros. Agregue registros una vez que haya creado los campos. ");
    ui.label_7->setText("Instructions Index: Crear una indexacion para la busqueda de registros");
    ui.label_8->setText("Instructions Export: Exportar a Excel o XMS");
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

void MainWindow::addRecords(){
    addRecord* addR = new addRecord();
    addR->setFile(&file);
    addR->addFields();
    addR->show();
}

void MainWindow::deleteARecord(){
    deleteRecord* delRec = new deleteRecord();
    delRec->setFile(&file);
    delRec->show();
}

void MainWindow::modifyRecord(){
    modRecord* modRec = new modRecord();
    modRec->setFile(&file);
    modRec->show();
}

void MainWindow::showRecords(){
    DisplayRecords* disRec = new DisplayRecords();
    disRec->setFile(&file);
    //disRec->refreshTableData();
    disRec->show();
}

void MainWindow::saveFile(){
    if(file){
        file.setLock();
        RefreshMenuBar();
        file.flush();

    }
}

void MainWindow::closeFile(){
    if(file){
        file.closeFile();
        ui.label_5->setText("");
        ui.label_6->setText("");
        ui.label_7->setText("");
        ui.label_8->setText("");

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
            ui.label_5->setText("Instructions field: Crear, modificar, eliminar, y listar campos. \n *En caso de no estar disponible, el archivo esta bloqueado y no podra agregar "
                                "mas campos*");
            ui.label_6->setText("Instructios Record: Agregar, modificar, eliminar y visualizar registros. \n Agregue registros una vez que haya creado los campos. ");
            ui.label_7->setText("Instructions Index: Crear una indexacion para la busqueda de registros");
            ui.label_8->setText("Instructions Export: Exportar a Excel o XMS");

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

void MainWindow::on_actionAdd_Record_triggered(){
    addRecords();
}

void MainWindow::on_actionDelete_Record_triggered(){
    deleteARecord();
}

void MainWindow::on_actionModify_Record_triggered(){
    modifyRecord();
}

void MainWindow::on_actionDisplay_Records_triggered(){
    showRecords();
}
void MainWindow::on_actionCreate_Index_triggered(){
    file.buildIndex();
    file.saveIndex();
    QMessageBox::about(this, "Success", "Index has been saved");

}

void MainWindow::on_actionExport_as_Excel_triggered(){
    QString path = QFileDialog::getSaveFileName(this, "Exportar a CSV", QDir::currentPath(), tr("CSV Files (*.csv)"));
    file.exportCSV(path.toStdString());

}

void MainWindow::on_actionExit_triggered(){
    MainWindow::close();
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


void MainWindow::on_actionGenerate_File_triggered(){
    //GENERATE FILES
    string generatePath;

    //Crear archivo de personas
    generatePath = "PersonFile.txt";
    remove(generatePath.c_str());
    remove(string(generatePath+ ".index").c_str());
    file.closeFile();
    file.openFile(generatePath);

    //Agregar campos al file
    file.addField(0, "PersonID",6, true);
    file.addField(1, "PersonName",20);
    file.addField(0, "PersonAge", 3);
    file.addField(0, "CityID",2);

    file.setLock();
    //Agregar Records
    for(int i =1; i<=10000;i++){
        List<string> nRecord;
        nRecord.insert(to_string(i));

        //GENERADOR DE NOMBRES CON RANDOMS
        int opName = 1;
        int opLName = 1;
        opName = rand()% 30+1;
        opLName = rand()% 30+1;
        string name="";
        //Nombres
        switch(opName){
        case 1:
            name+="Joseph";
            break;
         case 2:
            name+="Rodrigo";
            break;
         case 3:
            name+="Erick";
            break;
         case 4:
            name+="Richard";
            break;
         case 5:
            name+="Carlos";
            break;
         case 6:
            name+="Sarah";
            break;
         case 7:
            name+="Daniel";
            break;
         case 8:
            name+="Josue";
            break;
         case 9:
            name+="Melvin";
            break;
         case 10:
            name+="Juan Luis";
            break;
         case 11:
            name+="Luis";
            break;
         case 12:
            name+="Ricardo";
            break;
         case 13:
            name+="Eneldo";
            break;
         case 14:
            name+="Alejandra";
            break;
         case 15:
            name+="Michell";
            break;
         case 16:
            name+="David";
            break;
         case 17:
            name+="Iliana";
            break;
         case 18:
            name+="Cesar";
            break;
         case 19:
            name+="Stephanie";
            break;
         case 20:
            name+="Leo";
            break;
         case 21:
            name+="Justin";
            break;
         case 22:
            name+="Diego";
            break;
         case 23:
            name+="Michael";
            break;
         case 24:
            name+="Francisco";
            break;
         case 25:
            name+="Andrea";
            break;
         case 26:
            name+="Viktor";
            break;
         case 27:
            name+="Elmer";
            break;
         case 28:
            name+="Gerardo";
            break;
         case 29:
            name+="Chepe";
            break;
         case 30:
            name+="Angel";
            break;

        }

        //Apellidos
        switch(opLName){
        case 1:
            name+=" Moscoso";
            break;
         case 2:
            name+=" Velasquez";
            break;
         case 3:
            name+=" Carrasco";
            break;
         case 4:
            name+=" Padgett";
            break;
         case 5:
            name+=" Varela";
            break;
         case 6:
            name+=" Zelaya";
            break;
         case 7:
            name+=" Suazo";
            break;
         case 8:
            name+=" Moreno";
            break;
         case 9:
            name+=" Vargas";
            break;
         case 10:
            name+=" Guevara";
            break;
         case 11:
            name+=" Sanchez";
            break;
         case 12:
            name+=" Pinto";
            break;
         case 13:
            name+=" Estrada";
            break;
         case 14:
            name+=" Mejia";
            break;
         case 15:
            name+=" Mendoza";
            break;
         case 16:
            name+=" Pejuan";
            break;
         case 17:
            name+=" Rodriguez";
            break;
         case 18:
            name+=" Giron";
            break;
         case 19:
            name+=" Borjas";
            break;
         case 20:
            name+=" Deras";
            break;
         case 21:
            name+=" Santos";
            break;
         case 22:
            name+=" Matamoros";
            break;
         case 23:
            name+=" Martinez";
            break;
         case 24:
            name+=" Gonzales";
            break;
         case 25:
            name+=" Enamorado";
            break;
         case 26:
            name+=" Segura";
            break;
         case 27:
            name+=" Curio";
            break;
         case 28:
            name+=" Torres";
            break;
         case 29:
            name+=" Pereira";
            break;
         case 30:
            name+=" Risso";
            break;

        }

        nRecord.insert(name);
        nRecord.insert(to_string(rand()% 100+1));
        nRecord.insert(to_string(rand()% 100));

        //Agregar Record al file
        file.addRecord(nRecord);
        //Flush
        if (i%file.getBlockSize() == 0) {
            file.flush();
        }

    }

    qDebug() << "Test file " << generatePath.c_str() << " created successfully.";

    // Generar CityFile

    //Crea el archivo de ciudades
    generatePath="CityFile.txt";
    remove(generatePath.c_str());
    remove(string(generatePath+ ".index").c_str());
    file.closeFile();
    file.openFile(generatePath);

    //Agregar campos al archivo
    file.addField(0, "CityId", 2);
    file.addField(1,"CityName",30);

    file.setLock();

    //Agregar Records
    for(int i=1; i<=10000;i++){
        List<string> nRecord;
        nRecord.insert(to_string(rand()%99));

        //GENERADOR DE NOMBRES DE CIUDADES
        int opName =1;
        int opExt = 1;
        opName = rand()% 30+1;
        opExt = rand()% 6+1;
        string name="";
        //Nombres
        switch(opName){
        case 1:
            name+="Joseph";
            break;
         case 2:
            name+="Rodrigo";
            break;
         case 3:
            name+="Erick";
            break;
         case 4:
            name+="Richard";
            break;
         case 5:
            name+="Carlos";
            break;
         case 6:
            name+="Sarah";
            break;
         case 7:
            name+="Daniel";
            break;
         case 8:
            name+="Josue";
            break;
         case 9:
            name+="Melvin";
            break;
         case 10:
            name+="Juan Luis";
            break;
         case 11:
            name+="Luis";
            break;
         case 12:
            name+="Ricardo";
            break;
         case 13:
            name+="Eneldo";
            break;
         case 14:
            name+="Alejandra";
            break;
         case 15:
            name+="Michell";
            break;
         case 16:
            name+="David";
            break;
         case 17:
            name+="Iliana";
            break;
         case 18:
            name+="Cesar";
            break;
         case 19:
            name+="Stephanie";
            break;
         case 20:
            name+="Leo";
            break;
         case 21:
            name+="Justin";
            break;
         case 22:
            name+="Diego";
            break;
         case 23:
            name+="Michael";
            break;
         case 24:
            name+="Francisco";
            break;
         case 25:
            name+="Andrea";
            break;
         case 26:
            name+="Viktor";
            break;
         case 27:
            name+="Elmer";
            break;
         case 28:
            name+="Gerardo";
            break;
         case 29:
            name+="Nuke";
            break;
         case 30:
            name+="Angel";
            break;

        }

        switch (opExt) {
        case 1:
            name+=" City";
            break;
        case 2:
            name+="polis";
            break;
        case 3:
            name+="land";
            break;
        case 4:
            name+=" Sula";
            break;
        case 5:
            name+=" D.C.";
            break;
        case 6:
            name+=" Town";
            break;
        }


        nRecord.insert(name);

        //Agregar Record al file
        file.addRecord(nRecord);
        //Flush
        if (i%file.getBlockSize() == 0) {
            file.flush();
        }
    }
    qDebug() << "Test file " << generatePath.c_str() << " created successfully.";
    file.closeFile();
    QMessageBox::about(this,"Success","Test Files created successfully!");


}
