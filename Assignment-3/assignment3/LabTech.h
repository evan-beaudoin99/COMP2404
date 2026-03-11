#ifndef LABTECH_H
#define LABTECH_H

#include "Entity.h"
#include "LabWork.h"
#include "LabWorkList.h"


class LabTech: public Entity {

    private: 
        const char code;
        static int nextId;
        LabWorkList processedWork;

    public: 
        LabTech(const string& name);

        void addLabWork(LabWork* labWork);

        static void resetId();

        void print() const;
        void printLabWork() const;
};

#endif