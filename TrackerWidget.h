#ifndef TRACKERWIDGET_H
#define TRACKERWIDGET_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

class TrackerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrackerWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

public slots:
    void updateWorld();
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
