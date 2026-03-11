#ifndef LABWORKLIST_H
#define LABWORKLIST_H


#include "LabWork.h"

class LabWorkList {
    private:
        class Node {
        public: 
            LabWork* data;
            Node* next;

            Node(LabWork* lw) : data(lw), next(nullptr) {}

        };

        Node* head;
        Node* tail;

        int n;

    public:
        LabWorkList();
        ~LabWorkList();

        void add(LabWork* labwork);
        LabWork* getNext();

        bool isEmpty() const;

        int size() const;

        void print() const;
};

#endif