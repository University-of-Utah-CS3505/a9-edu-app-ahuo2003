#include "Canvas.h"
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Canvas canvas;
    Model model;
    MainWindow w(canvas, model);
    w.show();
    return a.exec();
}
