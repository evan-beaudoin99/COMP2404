#ifndef ENTITY_H
#define ENTITY_H


#include <string>
#include <iostream>
using namespace std;

class Entity {
    protected: 
        string name;
        string id;

    public:
        Entity(char code, int num, string name);

        string getId() const;

        void print() const;
};

#endif