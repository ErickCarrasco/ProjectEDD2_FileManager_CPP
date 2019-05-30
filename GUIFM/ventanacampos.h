#ifndef VENTANACAMPOS_H
#define VENTANACAMPOS_H

#include <QDialog>
#include <QString>
namespace Ui {
class VentanaCampos;
}

class VentanaCampos : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaCampos(QWidget *parent = nullptr);
    ~VentanaCampos();
    /*int getType();
    int getSize();
    int isPrimary();
    QString getNombre();*/

private slots:
    void on_pushButton_clicked();

private:
    Ui::VentanaCampos *ui;
};

#endif // VENTANACAMPOS_H
