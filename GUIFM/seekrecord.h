#ifndef SEEKRECORD_H
#define SEEKRECORD_H

#include <QDialog>
#include "file.h"

namespace Ui {
class seekRecord;
}

class seekRecord : public QDialog
{
    Q_OBJECT

public:
    explicit seekRecord(QWidget *parent = nullptr);
    void setFile(File*);
    ~seekRecord();

private slots:
    void on_pushButton_clicked();

private:
    Ui::seekRecord *ui;
    File* fileS;
};

#endif // SEEKRECORD_H
