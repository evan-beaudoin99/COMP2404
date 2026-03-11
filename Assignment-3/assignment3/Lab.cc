#include "Lab.h"
#include "LabWork.h"

Lab::Lab() {}

Lab::~Lab() {
    for (Patient* patient: patients) {
        delete patient;
    }
    for (LabTech* labtech: labtechs) {
        delete labtech;
    }

}

void Lab::addLabTech(const string& name) {
    labtechs.push_back(new LabTech(name));
}
void Lab::addPatient(const string& name, const string& medicalConditions) {
    patients.push_back(new Patient(name, medicalConditions));
}

void Lab::addLabWork(const string& patientId, LabWorkCode work, double cost) {
    Patient* patient = getPatient(patientId);

    if (patient == nullptr) {
        cout << "Error: Patient does not exist by given id." << endl;
        return;
    }

    LabWork* newWork = new LabWork(work, cost);

    patient->addLabWork(newWork);


}
void Lab::processLabWork(const string& labTechId, const string& patientId) {
    Patient* patient = getPatient(patientId);
    LabTech* tech = getLabTech(labTechId);

    if (patient == nullptr || tech == nullptr) {
        cout << "Error: Patient or Lab Tech does not exist by given id." << endl;
        return;
    }

    if (!patient->hasPendingLabWork()) {
        cout << "No Pending Work for Patient: " << patientId << endl;
        return;
    }

    LabWork* labWork = new LabWork(*(patient->processLabWork()));
    if (labWork == nullptr) {
        cout << "No Pending Work for Patient: " << patientId << endl;
        return;
    }
    labWork->completeLabWork(labTechId);
    tech->addLabWork(labWork);

}

Patient* Lab::getPatient(const string& id) {
    if (patients.empty()) {
        return nullptr;
    }

    for (int i = 0; i < patients.size(); i++) {
        if (patients[i]->getId() == id) {
            return patients[i];
        }
    }
    return nullptr;
}

const Patient* Lab::getPatient(const string& id) const {
    if (patients.empty()) {
        return nullptr;
    }

    for (int i = 0; i < patients.size(); i++) {
        if (patients[i]->getId() == id) {
            return patients[i];
        }
    }
    return nullptr;
}

LabTech* Lab::getLabTech(const string& id) {
    if (labtechs.empty()) {
        return nullptr;
    }

    for (int i = 0; i < labtechs.size(); i++) {
        if (labtechs[i]->getId() == id) {
            return labtechs[i];
        }
    }
    return nullptr;

}

const LabTech* Lab::getLabTech(const string& id) const {
    if (labtechs.empty()) {
        return nullptr;
    }

    for (int i = 0; i < labtechs.size(); i++) {
        if (labtechs[i]->getId() == id) {
            return labtechs[i];
        }
    }
    return nullptr;
}

void Lab::resetIds() {
    Patient::resetId();
    LabTech::resetId();    
}

// Print functions
void Lab::printLabTechs() const {
    for (int i = 0; i < labtechs.size(); i++) {
        labtechs[i]->print();
    }
}
void Lab::printPatients() const {
    for (int i = 0; i < patients.size(); i++) {
        patients[i]->print();
    }
}
void Lab::printLabTechLabWork(const string& id) const {
    const LabTech* labTech = getLabTech(id);
    if (labTech == nullptr) {
        cout << "Error: Lab Tech does not exist by given id." << endl;
        return;
    }
    const_cast<LabTech*>(labTech)->printLabWork();
}

void Lab::printPatientPendingLabWork(const string& id) const {
    const Patient* patient = getPatient(id);
    if (patient == nullptr) {
        cout << "Error: Patient does not exist by given id." << endl;
        return;
    }
    const_cast<Patient*>(patient)->printPendingLabWork();
}

void Lab::printPatientMedicalHistory(const string& id) const {
    const Patient* patient = getPatient(id);
    if (patient == nullptr) {
        cout << "Error: Patient does not exist by given id." << endl;
        return;
    }
    const_cast<Patient*>(patient)->printMedicalHistory();
}