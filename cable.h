#ifndef CABLE_H
#define CABLE_H

#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QColor>

class Cable
{
public:
    Cable(QPoint startPos, QColor cableColor);
    void mousePressed(QImage&, const QPoint &mousePos);
    void mouseReleased(QImage&, const QPoint &mousePos);
    void mouseMoved(QImage&, const QPoint &mousePos);

private:
    QPoint cableEndPos;
    QColor cableColor;
    QColor cableEndPosColor;
    QList<QPoint> path;
    bool canDraw;
    void drawLine();
    QPoint mapToImageCoordinates(const QPoint &point, int scaleFactor);
};

#endif // CABLE_H
