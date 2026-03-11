
#include "Patient.h"

int Patient::nextId = 1;

Patient::Patient(const string& name, const string& medicalConditions) 
    : code('P'), 
    Entity('P', nextId++, name), 
    medicalConditions(medicalConditions)
{   
}

void Patient::addLabWork(LabWork* labWork) {
    pendingWork.add(labWork);
}

LabWork* Patient::processLabWork() {
    LabWork* processed = pendingWork.getNext();
    if (processed == nullptr) {
        return nullptr;
    }
    processedWork.add(processed);
    return processed;
}

void Patient::resetId() {
    nextId = 1;
}


bool Patient::hasPendingLabWork() const {
    if (pendingWork.isEmpty()) {
        return false;
    }
    return true;
}

void Patient::print() const {
    cout << "Patient Details:  \n------------------" << endl;
    Entity::print(); // prints patient metadata
    cout << "Condition: " << medicalConditions << endl;
    cout << "\nMedical History: " << endl;
    cout << "Pending Work: " << pendingWork.size() <<
    "\nProcessed Work: " << processedWork.size() << "\n" << endl;
}

void Patient::printMedicalHistory() const {
    cout << "\nPatient: " << endl;
    Entity::print();
    cout << "Condition: " << medicalConditions << endl;
    processedWork.print();
}

void Patient::printPendingLabWork() const {
    cout << "\nPatient: " << endl;
    Entity::print();
    cout << "Condition: " << medicalConditions << endl;
    cout << "\nLab Work: " << endl;
    pendingWork.print();
    cout << endl;
}