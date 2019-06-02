#ifndef MODFIELD_H
#define MODFIELD_H

#include <QDialog>
#include "file.h"

namespace Ui {
class modField;
}

class modField : public QDialog
{
    Q_OBJECT

public:
    explicit modField(QWidget *parent = nullptr);
    void setFile(File*);
    void fillElements();
    ~modField();

private slots:
    void on_pushButton_saveChanges_clicked();

    void on_comboBox_modField_currentIndexChanged(int index);

private:
    Ui::modField *ui;
    File* file;
};

#endif // MODFIELD_H
