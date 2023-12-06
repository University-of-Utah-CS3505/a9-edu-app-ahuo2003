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
    void mouseReleased(QImage&);

    /**
     * @brief mouseMoved lets the user draw in the image if the mouse is pressed and moving, and
     * if they started drawing from the end of a cable.
     * @param mousePos position of the mouse.
     */
    void mouseMoved(QImage&, const QPoint &mousePos);

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
    bool moveHorizontal;
    bool moveVertical;
    bool canDraw;
    int scaleFactor;

private:
    /**
     * @brief appendToPath gets all the points generated between 2 points in an image, and appends them to the path list.
     * @param image where the line is drawn.
     * @param startPoint the starting point of a line.
     * @param endPoint the ending point of a line.
     */
    void appendToPath(QImage& image, const QPoint& startPoint, const QPoint& endPoint);

    /**
     * @brief deleteFromPath removes all the points between 2 points in an image if they exist in the path.
     * @param image where the line is erased.
     * @param startPoint the starting point of a line.
     * @param endPoint the ending point of a line.
     */
    void deleteFromPath(QImage& image, const QPoint& startPoint, const QPoint& endPoint);
};

#endif // CABLE_H
