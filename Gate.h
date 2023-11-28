#ifndef GATE_H
#define GATE_H

#include <QColor>
#include <QPainter>
#include <QImage>
#include <QPoint>

class Gate{
protected:
    void virtual draw(QImage &image);
    int pos_x;
    int pos_y;
    bool truth;
    QColor cableColor;
    QPainter painter;
};

#endif // GATE_H
