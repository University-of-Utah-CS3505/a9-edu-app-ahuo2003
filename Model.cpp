#include "Model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{
    levelView = new QImage(32,32, QImage::Format_ARGB32);
    levelView->fill(Qt::transparent);
    Cable* c = new Cable(QPoint(0,0), Qt::red);
    cables.append(c);
    currCable = c;
    scaleFactor = 20; // Default scaleFactor
}

void Model::loadLevel(int levelNum)
{
    currLevel.loadLevelData(levelNum);
}

void Model::mouseEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        this->currCable->mousePressed(*levelView, mapToImageCoordinates(event->pos(), scaleFactor));
    }

    if(event->type() == QEvent::MouseButtonRelease){
        this->currCable->mouseReleased(*levelView);
    }

    if(event->type() == QEvent::MouseMove){
        this->currCable->mouseMoved(*levelView, mapToImageCoordinates(event->pos(), scaleFactor));
    }

    emit invalidate(*levelView);

}

void Model::setAndLevel(int levelSelect)
{
    levelView->fill(Qt::transparent);
    loadLevel(levelSelect);
    currLevel.renderLevel(*levelView);
}


QPoint Model::mapToImageCoordinates(const QPoint &point, int scaleFactor){
    return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}

