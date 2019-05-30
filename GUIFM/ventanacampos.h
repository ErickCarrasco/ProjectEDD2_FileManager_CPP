#ifndef VENTANACAMPOS_H
#define VENTANACAMPOS_H

#include <QDialog>
#include <QString>
#include "file.h"

namespace Ui {
class VentanaCampos;
}

class VentanaCampos : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaCampos(QWidget *parent = nullptr);
    void setFields(File*);
    ~VentanaCampos();

private slots:
    //void
    void on_pushButton_clicked();

private:
    Ui::VentanaCampos *ui;
    File* file;
};

#endif // VENTANACAMPOS_H
