#ifndef TRACKERWIDGET_H
#define TRACKERWIDGET_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

/**
 * @brief The TrackerWidget class provides a custom widget class
 * which can be used to store a simple Box2d program which interacts with
 * our Model class.
 */
class TrackerWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief TrackerWidget Constructor for the TrackerWidget
     * @param parent a QWidget parent parameter
     */
    explicit TrackerWidget(QWidget *parent = nullptr);

    /**
     * @brief paintEvent Updates the widget with current events
     */
    void paintEvent(QPaintEvent *);

public slots:
    /**
     * @brief updateWorld Updates the internals of the widget with current events
     */
    void updateWorld();

    /**
     * @brief createBouncingBox Creates a new bouncing box and adds it to the widget.
     * @param x x-coordinate
     * @param y y-coordinate
     * @param w width
     * @param h height
     * @param d density
     * @param f friction
     * @param r restitution
     */
    void createBouncingBox(float x, float y, float w, float h, float d, float f, float r);

private:
    b2World world;
    b2Body* groundBody;
    b2Body* leftWallBody;
    b2Body* rightWallBody;
    b2Body* roofBody;
    QTimer timer;
    QImage image;
    QList<b2Body*> bodyList;
    QList<QColor> colors;
};

#endif // TRACKERWIDGET_H
