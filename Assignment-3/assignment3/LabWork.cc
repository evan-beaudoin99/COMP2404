
#include "LabWork.h"

const string LabWork::LABTESTS[NUM_LABTESTS] = {
    "Blood Test",
    "Urine Test",
    "X-Ray",
    "MRI",
    "CT Scan",
    "Ultrasound",
    "Biopsy",
    "Genetic Test",
    "Allergy Test",
    "COVID-19 Test"
};

const string LabWork::NOTCOMPLETE = "not complete";


LabWork::LabWork(LabWorkCode labWorkCode, double cost) {
    this->labWorkCode = labWorkCode;
    this->cost = cost;
    labTechId = NOTCOMPLETE;
}

LabWork::LabWork(const LabWork& other) {
    labWorkCode = other.labWorkCode;
    cost = other.cost;
    labTechId = other.labTechId;
}

bool LabWork::isComplete() const {
        if (labTechId == NOTCOMPLETE) return false;
        return true;
} 

void LabWork::completeLabWork(const string& labTechId) {
    this->labTechId = labTechId; 
}

void LabWork::print() const {
    cout << "-> Work: " << LABTESTS[labWorkCode] << ", Cost: " << cost << ", Completed by: " << labTechId << endl;   
}
