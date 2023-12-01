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
     * @brief Cable constructor for the cable class.
     * @param startPos position of the initial cable.
     * @param cableColor color of the cable.
     */
    Cable(QPoint startPos, QColor cableColor);

    /**
     * @brief mousePressed checks if the user is at the end of a cable, and it is, lets the user extend(or draw) the cable.
     * @param mousePos position of the mouse.
     */
    void mousePressed(QImage&, const QPoint& mousePos);

    /**
     * @brief mouseReleased stops extending the cable when the user releases the mouse button that was pressed.
     * @param mousePos position of the mouse.
     */
    void mouseReleased(QImage&, const QPoint& mousePos);

    /**
     * @brief mouseMoved lets the user draw in the image if the mouse is pressed and moving, and
     * if they started drawing from the end of a cable.
     * @param mousePos position of the mouse.
     */
    void mouseMoved(const QPoint &mousePos);

    /**
     * @brief changeScaleFactor changes the scale factor to the desired scaleFactor.
     * @param newScaleFactor the new scale factor.
     */
    void changeScaleFactor(int newScaleFactor);



    QPoint *getCableEndPos() const;

protected:
    QPoint* cableEndPos;
    QColor cableColor;
    QColor cableEndPosColor;
    QList<QPoint> path;
    QPainter painter;
    bool canDraw;
    int scaleFactor;

private:
    /**
     * @brief drawLine draws a horizontal or vertical line between 2 points.
     * @param startPoint the starting point of a line.
     * @param endPoint the ending point of a line.
     */
    void drawLine(const QPoint& startPoint, const QPoint& endPoint);

    /**
     * @brief appendToPath gets all the points generated between 2 points in an image, and appends them to the path list.
     * @param startPoint the starting point of a line.
     * @param endPoint the ending point of a line.
     * @param dy change in y between the 2 points.
     * @param dx change in x between the 2 points.
     */
    void appendToPath(const QPoint& startPoint, const QPoint& endPoint, int& dy, int& dx);
};

#endif // CABLE_H
