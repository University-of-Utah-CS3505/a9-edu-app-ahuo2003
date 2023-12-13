#include "MainWindow.h"
#include <QApplication>
/*
 * Names: Hunter Keating, Hai Minh Pham, Thomas Kuhrke Limia, Andy Huo, Nam Nguyen, Emmanuel Luna
 * Assignment: A8: Sprite Editor
 * Description: This program is an educational application that teaches how basic
 * logical gates work. The application contains 3 tutorial levels that shows the
 * user how each gate works(AND/OR/NOT), followed by 6 levels that get more difficult
 * as the player progresses in the game.
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
