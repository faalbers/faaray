#include "GUI.hpp"
#include "MainWindow.hpp"
#include <QApplication>

int GUI(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
