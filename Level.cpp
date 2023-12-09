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
        gates.append(new NotGate(10, 10));
        gates.append(new InGate(4,10, Qt::red));
        gates.append(new InGate(4,20, Qt::green));
        gates.append(new OutGate(29, 15));
        gates.append(new AndGate(18, 15));
        break;

    case 5:
        gates.append(new NotGate(8, 5));
        gates.append(new InGate(3,5, Qt::red));
        gates.append(new InGate(3,12,Qt::green));
        gates.append(new InGate(3,17,Qt::red));
        gates.append(new OutGate(30, 12));
        gates.append(new AndGate(14, 8));
        gates.append(new AndGate(22, 13));
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
        gates. append(new NotGate(9, 25));
        gates.append(new NotGate(13, 28));
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,30, Qt::red));
        gates.append(new InGate(1,13, Qt::red));
        gates.append(new InGate(1,23, Qt::red));
        gates.append(new InGate(1,18, Qt::red));
        gates.append(new InGate(1,27, Qt::red));
        gates.append(new OutGate(31, 15));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(24, 15));
        gates.append(new AndGate(20, 26));
        gates.append(new OrGate(15, 13));
        gates.append(new OrGate(15, 22));
        gates.append(new OrGate(20, 7));
        break;

    case 9:
        gates.append(new InGate(1,1, Qt::red));
        gates.append(new InGate(1,3, Qt::red));
        gates.append(new InGate(1,5, Qt::red));
        gates.append(new InGate(1,7, Qt::red));
        gates.append(new InGate(1,9, Qt::red));
        gates.append(new InGate(1,11, Qt::red));
        gates.append(new InGate(1,13, Qt::red));
        gates.append(new InGate(1,15, Qt::red));
        gates.append(new InGate(1,17, Qt::red));
        gates.append(new InGate(1,19, Qt::red));
        gates.append(new InGate(1,21, Qt::red));
        gates.append(new InGate(1,24, Qt::red));
        gates.append(new InGate(1,27, Qt::red));
        gates.append(new InGate(1,30, Qt::red));
        gates.append(new AndGate(9, 2));
        gates.append(new AndGate(9, 7));
        gates.append(new AndGate(9, 12));
        gates.append(new AndGate(9, 17));
        gates.append(new AndGate(17, 23));
        gates.append(new AndGate(22, 9));
        gates.append(new AndGate(25, 26));
        gates.append(new AndGate(24, 18));
        gates.append(new OrGate(8, 21));
        gates.append(new OrGate(9, 25));
        gates.append(new OrGate(8, 29));
        gates.append(new OrGate(17, 4));
        gates.append(new OrGate(17, 13));
        gates.append(new NotGate(14, 29));
        gates.append(new OutGate(31, 15));
        break;
    }
}
