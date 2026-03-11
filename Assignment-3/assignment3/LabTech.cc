
#include "LabTech.h"

int LabTech::nextId = 1;

LabTech::LabTech(const string& name) 
    : code('T'), 
    Entity('T', nextId++, name)
{   
}

void LabTech::addLabWork(LabWork* labWork) {
    processedWork.add(labWork);
}


void LabTech::resetId() {
    nextId = 1;
}

void LabTech::print() const {
    cout << "LabTechs Info \n------------------" << endl;
    Entity::print(); // prints LabTech metadata
    cout  << "\nProcessed: " << processedWork.size() << "\n" << endl;
}

void LabTech::printLabWork() const {
    Entity::print();
    processedWork.print();
}
