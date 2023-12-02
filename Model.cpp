#include "Model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{
    levelView = new QImage(32,32, QImage::Format_ARGB32);
    Cable* c = new Cable(QPoint(0,0), Qt::red);
    cables.append(c);
    currCable = c;
    scaleFactor = 16; // Default scaleFactor
}

void Model::loadLevel(int levelNum)
{
    currLevel.loadLevelData(levelNum);
}

void Model::mouseEvent(QMouseEvent *event)
{
    qDebug() << event->pos();
    if(event->type() == QEvent::MouseButtonPress){
//        for(Cable *c : cables){
//            //Take care of scale factor
//            if(event->pos() == *(c->getCableEndPos()))
//                currCable = c;
//        }
        this->currCable->mousePressed(*levelView, mapToImageCoordinates(event->pos(), scaleFactor));
    }

    if(event->type() == QEvent::MouseButtonRelease){
        this->currCable->mouseReleased(*levelView, mapToImageCoordinates(event->pos(), scaleFactor));
    }

    if(event->type() == QEvent::MouseMove){
        this->currCable->mouseMoved(mapToImageCoordinates(event->pos(), scaleFactor));
    }

    emit invalidate(*levelView);

}

QPoint Model::mapToImageCoordinates(const QPoint &point, int scaleFactor){
    return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}
