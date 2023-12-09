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
        gates.append(new InGate(5,5, true, Qt::green));
        gates.append(new InGate(5,15, true, Qt::green));
        gates.append(new OutGate(30,10));
        break;

    case 2:
        gates.append(new OrGate(15, 10));
        gates.append(new InGate(5,5, false, Qt::red));
        gates.append(new InGate(5,15, true, Qt::green));
        gates.append(new OutGate(30,10));
        break;

    case 3:
        gates.append(new NotGate(15, 10));
        gates.append(new InGate(5,10, false,  Qt::red));
        gates.append(new OutGate(30,10));
        break;

    case 4:
        gates.append(new NotGate(10, 10));
        gates.append(new InGate(4,10,false, Qt::red));
        gates.append(new InGate(4,20,true, Qt::green));
        gates.append(new OutGate(29, 15));
        gates.append(new AndGate(18, 15));
        break;

    case 5:
        gates.append(new NotGate(8, 5));
        gates.append(new InGate(3,5,false, Qt::red));
        gates.append(new InGate(3,12,true, Qt::green));
        gates.append(new InGate(3,17,false, Qt::red));
        gates.append(new OutGate(30, 12));
        gates.append(new AndGate(14, 8));
        gates.append(new AndGate(22, 13));
        break;
    case 6:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates.append(new InGate(1,1,true, Qt::green));
        gates.append(new InGate(1,5,false, Qt::red));
        gates.append(new InGate(1,9,true, Qt::green));
        gates.append(new InGate(1,13,false, Qt::red));
        gates.append(new OutGate(31, 7));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 7));
        gates.append(new OrGate(12, 11));
        break;

    case 7:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates.append(new InGate(1,5,false, Qt::red));
        gates.append(new InGate(1,10,false, Qt::red));
        gates.append(new InGate(1,15,true, Qt::green));
        gates.append(new InGate(1,20,true, Qt::green));
        gates.append(new OutGate(31, 7));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 7));
        gates.append(new OrGate(12, 11));
        gates.append(new OrGate(15, 20));
        break;

    case 8:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(12, 25));
        gates.append(new NotGate(20, 28));
        gates.append(new InGate(1,1, true, Qt::green));
        gates.append(new InGate(1,30, true, Qt::green));
        gates.append(new InGate(1,13,false, Qt::red));
        gates.append(new InGate(1,23,false, Qt::red));
        gates.append(new OutGate(31, 15));
        gates.append(new AndGate(12, 3));
        gates.append(new OrGate(18, 13));
        gates.append(new OrGate(20, 22));
        break;

    case 9:
        gates.append(new NotGate(6, 1));
        gates.append(new NotGate(6, 9));
        gates.append(new NotGate(24, 7));
        gates.append(new NotGate(12, 25));
        gates.append(new NotGate(20, 28));
        gates.append(new InGate(1,1, false, Qt::red));
        gates.append(new InGate(1,5, false, Qt::red));
        gates.append(new InGate(1,30, true, Qt::green));
        gates.append(new InGate(1,13, false, Qt::red));
        gates.append(new InGate(1,23, true, Qt::green));
        gates.append(new OutGate(31, 15));
        gates.append(new AndGate(12, 3));
        gates.append(new AndGate(18, 13));
        gates.append(new OrGate(20, 22));
        break;
    }
}

void Level::connectGates(Gate *andOrNotOut, Gate *input)
{
    // When we connect the gates, we just add the input gate to the inputGates QList of each And/Or/Not/Out gates || TODO: Handle disconnection
    andOrNotOut->addInputGate(input);
    // Then we recompute the truth values of all gates to ensure that it is constantly updated to the latest.
    refreshTruthValues();
    refreshTruthValues();
    //Change the cable color depending on signal
    if (andOrNotOut->getTruthValue()){
        andOrNotOut->setCableColor(Qt::green);
    }
    else{
        andOrNotOut->setCableColor(Qt::red);
    }

}

void Level::disconnectGates(Gate *andOrNotOut, Gate *input)
{
    andOrNotOut->removeInputGate(input);

    refreshTruthValues();
    //Change the cable color depending on signal
    if (andOrNotOut->getTruthValue()){
        andOrNotOut->setCableColor(Qt::green);
    }
    else{
        andOrNotOut->setCableColor(Qt::red);
    }
}
void Level::checkConnections() {
    for (Gate* gate : gates) {
        // Create a list to track currently connected input gates
        QList<Gate*> currentConnectedInputs;

        // Identify and handle connections
        updateGateConnections(gate, currentConnectedInputs);

        // Identify and handle disconnections
        for (Gate* existingInputGate : gate->getInputGates()) {
            if (!currentConnectedInputs.contains(existingInputGate)) {
                disconnectGates(gate, existingInputGate);
            }
        }

        // Update the gate's input gates to reflect current connections
        gate->setInputGates(currentConnectedInputs);
    }

    // After updating all connections, refresh truth values
    refreshTruthValues();
}

void Level::updateGateConnections(Gate* gate, QList<Gate*>& connectedInputs) {
    for (Gate* inGate : gates) {
        if (gate != inGate) {
            // Check specific gate types for their input positions
            if (AndGate* andGate = dynamic_cast<AndGate*>(gate)) {
                checkAndAddInput(inGate, andGate, andGate->getInput1(), connectedInputs);
                checkAndAddInput(inGate, andGate, andGate->getInput2(), connectedInputs);
            } else if (OrGate* orGate = dynamic_cast<OrGate*>(gate)) {
                checkAndAddInput(inGate, orGate, orGate->getInput1(), connectedInputs);
                checkAndAddInput(inGate, orGate, orGate->getInput2(), connectedInputs);
            } else if (NotGate* notGate = dynamic_cast<NotGate*>(gate)) {
                checkAndAddInput(inGate, notGate, notGate->getInput(), connectedInputs);
            } else if (OutGate* outGate = dynamic_cast<OutGate*>(gate)) {
                checkAndAddInput(inGate, outGate, outGate->getInput(), connectedInputs);
            }
        }
    }
}

void Level::checkAndAddInput(Gate* inGate, Gate* gate, const QPoint& inputPos, QList<Gate*>& connectedInputs) {
    if (*(inGate->getCable()->getCableEndPos()) == inputPos) {
        connectedInputs.append(inGate);
        connectGates(gate, inGate);
    }
}



void Level::refreshTruthValues()
{
    bool hasChanged;
    do {
        hasChanged = false;

        // Iterate through all gates
        for (Gate* g : gates) {
            bool currentTruthValue = g->getTruthValue();
            bool newTruthValue = g->computeTruthValue();

            if (currentTruthValue != newTruthValue) {
                g->setTruthValue(newTruthValue);
                hasChanged = true; // A change has occurred, so another pass is needed
            }
        }

        // Repeat until no more changes occur
    } while (hasChanged);
}
