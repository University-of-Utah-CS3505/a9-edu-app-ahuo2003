#include "Level.h"

Level::Level()
{

}

Level::~Level()
{
    qDeleteAll(gates);
    gates.clear();
}

void Level::addGate(Gate* gate, int x, int y)
{
    //gate->setPos(x,y);
    gates.append(gate);
}

void Level::renderLevel(QImage &image)
{
    for (Gate* gate: gates) gate->draw(image);
}

void Level::loadLevelData(int levelNumber)
{
//    switch (levelNumber) {
//    case 1:
//        Gate* orGate = new OrGate();
//    }
}
