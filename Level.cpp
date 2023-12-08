#include "Level.h"
#include "AndGate.h"
#include "InGate.h"
#include "OutGate.h"
#include "OrGate.h"
#include "NotGate.h"

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
    gate->setPos(x,y);
    gates.append(gate);
}

void Level::renderLevel(QImage &image)
{
    for (Gate* gate: gates) gate->draw(image);
}

void Level::loadLevelData(int levelNumber)
{
    gates.clear();

    switch (levelNumber) {
    case 1:
        gates.append(new AndGate(15, 10));
        gates.append(new InGate(5,5, Qt::red));
        gates.append(new InGate(5,15, Qt::red));
        gates.append(new OutGate(30,10));
        break;

    case 2:
        gates.append(new OrGate(15, 10));
        gates.append(new InGate(5,5, Qt::red));
        gates.append(new InGate(5,15, Qt::red));
        gates.append(new OutGate(30,10));
        break;

    case 3:
        gates.append(new NotGate(15, 10));
        gates.append(new InGate(5,5, Qt::red));
        gates.append(new InGate(5,15, Qt::red));
        gates.append(new OutGate(30,10));
        break;

    case 4:
        gates.append(new NotGate(7, 1));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new OutGate(25, 3));
        gates.append(new AndGate(15, 3));
        break;

    case 5:
        gates.append(new NotGate(6, 1));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,9, Qt::red));
        gates.append(new OutGate(30, 5));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(22, 5));
        break;
    case 6:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,9, Qt::red));
        gates.append(new InGate(1,13, Qt::red));
        gates.append(new OutGate(31, 7));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 7));
        gates.append(new OrGate(12, 11));
        break;

    case 7:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,10, Qt::red));
        gates.append( new InGate(1,15, Qt::red));
        gates.append(new InGate(1,20, Qt::red));
        gates.append(new OutGate(31, 7));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 7));
        gates.append(new OrGate(12, 11));
        gates.append(new OrGate(15, 20));
        break;

    case 8:
        gates.append(new NotGate(6, 1));
        gates. append(new NotGate(12, 25));
        gates.append(new NotGate(20, 28));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,30, Qt::red));
        gates.append(new InGate(1,13, Qt::red));
        gates.append(new InGate(1,23, Qt::red));
        gates.append(new OutGate(31, 15));
        gates.append(new AndGate(12, 3));
        gates.append(new OrGate(18, 13));
        gates.append(new OrGate(20, 22));
        break;

    case 9:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates. append(new NotGate(12, 25));
        gates.append(new NotGate(20, 28));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,30, Qt::red));
        gates.append(new InGate(1,13, Qt::red));
        gates.append(new InGate(1,23, Qt::red));
        gates.append(new OutGate(31, 15));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 13));
        gates.append(new OrGate(20, 22));
        break;
    }
}
