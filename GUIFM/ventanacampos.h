#ifndef VENTANACAMPOS_H
#define VENTANACAMPOS_H

#include <QDialog>

namespace Ui {
class VentanaCampos;
}

class VentanaCampos : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaCampos(QWidget *parent = nullptr);
    ~VentanaCampos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VentanaCampos *ui;
};

#endif // VENTANACAMPOS_H
