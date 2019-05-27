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
    //void closeFile();
    //void saveFile();
    //void loadFile();

    void on_pB_NewFile_clicked();

public:
    MainWindow(QWidget* parent = 0);
    //~MainWindow();
    File* getFile();
};

#endif // MAINWINDOW_H
