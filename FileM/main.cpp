#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *label = new QLabel("File Manager");
    label->setWindowTitle("File Manager EDDII");
    label->resize(400, 400);

    label->show();

    return a.exec();
}
