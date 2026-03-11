#ifndef PATIENT_H
#define PATIENT_H


#include "Entity.h"
#include "LabWork.h"
#include "LabWorkList.h"


class Patient: public Entity {

    private: 
        const char code;
        static int nextId;
        string medicalConditions;
        LabWorkList pendingWork;
        LabWorkList processedWork;

    public: 
        Patient(const string& name, const string& medicalConditions);

        void addLabWork(LabWork* labWork);
        LabWork* processLabWork();

        static void resetId();

        bool hasPendingLabWork() const;

        void print() const;
        void printMedicalHistory() const;
        void printPendingLabWork() const;
};

#endif