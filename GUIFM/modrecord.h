#ifndef MODRECORD_H
#define MODRECORD_H

#include <QDialog>
#include "file.h"
#include "linkedlist.h"

namespace Ui {
class modRecord;
}

class modRecord : public QDialog
{
    Q_OBJECT

public:
    explicit modRecord(QWidget *parent = nullptr);
    void setFile(File*);
    ~modRecord();

private slots:
    void on_pushButton_loadData_modRecordData_clicked();

    void on_pushButton_ModActualRecord_clicked();

private:
    Ui::modRecord *ui;
    File* file;
    bool dataLoaded;
    List<string> record;
    int indexRecord;
};

#endif // MODRECORD_H
