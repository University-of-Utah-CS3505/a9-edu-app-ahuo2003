#include "MainWindow.h"
#include "Canvas.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Canvas canvas;
    MainWindow w(canvas);
    w.show();
    return a.exec();
}
