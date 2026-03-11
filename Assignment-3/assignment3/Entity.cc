


#include "Entity.h"

Entity::Entity(char code, int num, string name) : name(name), id(code + to_string(num))
{
}

string Entity::getId() const {
    return id;
}

void Entity::print() const {
    cout << "Name: " << name << "\nID: " << id << endl;
}