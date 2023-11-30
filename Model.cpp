#include "Model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{
    levelView = new QImage(32,32, QImage::Format_ARGB32);
    Cable* c = new Cable(QPoint(0,0), Qt::red);
    cables.append(c);
    currCable = c;
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
        this->currCable->mousePressed(*levelView, event->pos());
    }

    if(event->type() == QEvent::MouseButtonRelease){
        this->currCable->mouseReleased(*levelView, event->pos());
    }

    if(event->type() == QEvent::MouseMove){
        this->currCable->mouseMoved(event->pos());
    }

    emit invalidate(*levelView);

}

