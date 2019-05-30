#ifndef DELETEFIELD_H
#define DELETEFIELD_H

#include <QDialog>
#include "file.h"

namespace Ui {
class DeleteField;
}

class DeleteField : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteField(QWidget *parent = nullptr);
    ~DeleteField();
    void setFile(File*);
    void updateComboBox();

private slots:
    void on_pB_deletefieldButton_clicked();

private:
    Ui::DeleteField *ui;
    File* file;
};

#endif // DELETEFIELD_H
