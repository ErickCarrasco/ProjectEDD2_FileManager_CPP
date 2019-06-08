#ifndef DISPLAYRECORDS_H
#define DISPLAYRECORDS_H

#include <QWidget>
#include "file.h"

namespace Ui {
class DisplayRecords;
}

class DisplayRecords : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayRecords(QWidget *parent = nullptr);
    void setFile(File*);
    void refreshTableData();
    ~DisplayRecords();

private slots:
    void on_pushButton_refreshTabe_clicked();

    void on_pushButton_previousPage_clicked();

    void on_pushButton_nextPage_clicked();

    void on_pushButton_SearchRecord_clicked();

private:
    Ui::DisplayRecords *ui;
    File* file;
};

#endif // DISPLAYRECORDS_H
