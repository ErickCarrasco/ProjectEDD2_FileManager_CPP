#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDebug>
#include "file.h"

/*
namespace Ui {
class MainWindow;
}
*/
class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    Ui::MainWindow ui;
    File file;

private slots:
    void openFile();
    void closeFile();
    void saveFile();
    void loadFile();

    //void listarField();
    void createField();
    void deleteFieldD();
    void modifyField();

    void on_pB_NewFile_clicked();

    void on_actionSave_File_triggered();

    void on_actionAdd_Field_triggered();

    void on_actionClose_File_triggered();

    void on_pB_OpenFile_clicked();

    void on_actionOpen_File_triggered();

    void on_actionList_Fields_triggered();

    void on_actionDelete_Field_triggered();

    void on_actionModify_Field_triggered();

public:
    MainWindow(QWidget* parent = 0);
    //~MainWindow();
    void RefreshMenuBar();
    File* getFile();

};

#endif // MAINWINDOW_H
