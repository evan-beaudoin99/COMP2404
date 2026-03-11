#ifndef LAB_H
#define LAB_H

#include "Patient.h"
#include "LabTech.h"

#include <vector>
#include <iostream>

class Lab {

    private: 
        vector<Patient*> patients;
        vector<LabTech*> labtechs;
    public:

        Lab();
        ~Lab();

        void addLabTech(const string& name);
        void addPatient(const string& name, const string& medicalConditions);

        void addLabWork(const string& patientId, LabWorkCode work, double cost);
        void processLabWork(const string& labTechId, const string& patientId);

        Patient* getPatient(const string& id);
        const Patient* getPatient(const string& id) const;

        LabTech* getLabTech(const string& id);
        const LabTech* getLabTech(const string& id) const;

        void resetIds();

        // Print functions
        void printLabTechs() const;
        void printPatients() const;
        void printLabTechLabWork(const string& id) const;

        void printPatientPendingLabWork(const string& id) const;
        void printPatientMedicalHistory(const string& id) const;

};

#endif