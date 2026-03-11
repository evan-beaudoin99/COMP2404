


#include "LabWorkList.h"


LabWorkList::LabWorkList() {
    head = nullptr;
    tail = nullptr;
    n = 0;
}


LabWorkList::~LabWorkList() {
    // free all heap allocated memory
    Node* currNode = head;
    
    while (currNode != nullptr) {
        Node* temp = currNode;
        currNode = currNode->next;

        delete temp->data;
        delete temp;
    }
}


void LabWorkList::add(LabWork* labwork) {
    
    Node* newNode = new Node(labwork);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    n++;
}

LabWork* LabWorkList::getNext() {
    if (isEmpty()) {
        return nullptr;
    }

    Node* temp = head;
    LabWork* result = temp->data;

    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    } 

    delete temp;
    n--;

    return result;
    
}

bool LabWorkList::isEmpty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

int LabWorkList::size() const {
    return n;
}

void LabWorkList::print() const {
    Node* currNode = head;
  
    while (currNode != nullptr) {
        currNode->data->print();
        currNode = currNode->next;;
    }
}
