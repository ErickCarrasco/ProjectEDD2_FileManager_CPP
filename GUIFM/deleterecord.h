#ifndef DELETERECORD_H
#define DELETERECORD_H

#include <QDialog>
#include "file.h"
#include "linkedlist.h"

namespace Ui {
class deleteRecord;
}

class deleteRecord : public QDialog
{
    Q_OBJECT

public:
    explicit deleteRecord(QWidget *parent = nullptr);
    void setFile(File*);
    ~deleteRecord();

private slots:
    void on_pushButton_loadData_DeleteRecord_clicked();

    void on_pushButton_DeleteActualRecord_clicked();

private:
    Ui::deleteRecord *ui;
    File* file;
    bool dataLoaded;
    List<string> record;
    int indexRecord;
};

#endif // DELETERECORD_H
