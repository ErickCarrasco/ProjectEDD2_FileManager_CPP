#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QDialog>
#include "file.h"

namespace Ui {
class addRecord;
}

class addRecord : public QDialog
{
    Q_OBJECT

public:
    explicit addRecord(QWidget *parent = nullptr);
    void setFile(File*);
    void addFields();
    ~addRecord();
    bool validateTypeInteger(QString);

private slots:
    void on_pushButton_addRecord_to_file_clicked();

private:
    Ui::addRecord *ui;
    File* file;
};

#endif // ADDRECORD_H
