#ifndef ADDFIELD_H
#define ADDFIELD_H

#include <QDialog>
#include "file.h"

namespace Ui {
class addField;
}

class addField : public QDialog
{
    Q_OBJECT

public:
    explicit addField(QWidget *parent = nullptr);
    void setFile(File*);
    ~addField();

private slots:
    void on_pb_addField_to_file_clicked();

private:
    Ui::addField *ui;
    File* file;
};

#endif // ADDFIELD_H
