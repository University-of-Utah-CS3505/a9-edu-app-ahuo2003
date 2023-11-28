#ifndef CABLE_H
#define CABLE_H

#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QColor>
#include <QPainter>

class Cable
{
public:
    /**
     * @brief Cable
     * @param startPos
     * @param cableColor
     */
    Cable(QPoint startPos, QColor cableColor);

    /**
     * @brief mousePressed
     * @param mousePos
     */
    void mousePressed(QImage&, const QPoint& mousePos);

    /**
     * @brief mouseReleased
     * @param mousePos
     */
    void mouseReleased(QImage&, const QPoint& mousePos);

    /**
     * @brief mouseMoved
     * @param mousePos
     */
    void mouseMoved(const QPoint &mousePos);

    /**
     * @brief changeScaleFactor
     * @param newScaleFactor
     */
    void changeScaleFactor(int newScaleFactor);


protected:
    const QPoint* cableEndPos;
    QColor cableColor;
    QColor cableEndPosColor;
    QList<QPoint> path;
    QPainter painter;
    bool canDraw;
    int scaleFactor;

private:
    /**
     * @brief drawLine
     * @param startPoint
     * @param endPoint
     */
    void drawLine(const QPoint& startPoint, const QPoint& endPoint);

    /**
     * @brief appendToPath
     * @param startPoint
     * @param endPoint
     * @param dy
     * @param dx
     */
    void appendToPath(const QPoint& startPoint, const QPoint& endPoint, int& dy, int& dx);

    /**
     * @brief mapToImageCoordinates
     * @param point
     * @param scaleFactor
     * @return
     */
    QPoint mapToImageCoordinates(const QPoint& point, int scaleFactor);
};

#endif // CABLE_H
