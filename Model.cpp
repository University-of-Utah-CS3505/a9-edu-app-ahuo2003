#include "Model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{
    levelView = new QImage(32,32, QImage::Format_ARGB32);
    levelView->fill(Qt::transparent);
    currCable = nullptr;
    scaleFactor = 20; // Default scaleFactor
}

void Model::loadLevel(int levelNum)
{
    currLevel.loadLevelData(levelNum);
}

void Model::mouseEvent(QMouseEvent *event)
{
    QPoint mousePos = mapToImageCoordinates(event->pos(), scaleFactor);
    changeCurrentCable(mousePos);
    if (currCable){
        if (!(currLevelCables.contains(currCable))){
            currLevelCables.append(currCable);
        }
        if(event->type() == QEvent::MouseButtonPress){
            this->currCable->mousePressed(*levelView, mousePos);
        }

        if(event->type() == QEvent::MouseButtonRelease){
            this->currCable->mouseReleased(*levelView);
            currLevel.checkConnections();
            currCable = nullptr;

            //Redraws all the cables in case a connection made any change colors
            for(Cable* c : currLevelCables){
                c->redrawCable(*levelView);
            }
        }

        if(event->type() == QEvent::MouseMove){
            this->currCable->mouseMoved(*levelView, mousePos);
        }
    }
    currLevel.renderLevel(*levelView);
    emit invalidate(*levelView);
}

void Model::changeCurrentCable(QPoint mousePos){
    //Retrieve the currently used cable
    for(auto gate : currLevel.gates){
        QPoint* cablePos = gate->getCable()->getCableEndPos();
        if (mousePos == *cablePos) {
            currCable = gate->getCable();
        }
    }
}

void Model::setAndLevel(int levelSelect)
{
    levelView->fill(Qt::transparent);
    currCable = nullptr;
    currLevelCables.clear();
    loadLevel(levelSelect);
    currLevel.renderLevel(*levelView);
    emit invalidate(*levelView);
}

void Model::checkWinningCondition()
{
    for(Gate* gate : currLevel.gates){
        if (!(gate->isConnected()) || (currLevel.gates.back()->getTruthValue() != currLevel.winCondition)){
            return;
        }
    }
    emit wonLevel();
}


QPoint Model::mapToImageCoordinates(const QPoint &point, int scaleFactor){
    return QPoint(point.x() / scaleFactor, point.y() / scaleFactor);
}
