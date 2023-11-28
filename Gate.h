#ifndef GATE_H
#define GATE_H

#include <QColor>

class Gate{
private:
    int pos_x;
    int pos_y;
    bool truth;
    QColor cableColor;

protected:
    void virtual draw();
};

#endif // GATE_H
