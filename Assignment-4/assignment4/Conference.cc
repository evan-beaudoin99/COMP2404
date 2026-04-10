

#include "Conference.h"

Conference::Conference(const string& name, const string& description)
    : name(name), 
      description(description)
{}

Conference::~Conference() {
    for (int i = 0; i < talkList.getSize(); i++) {
        delete talkList[i];
    }
}

bool Conference::operator==(const string& name) const {
    return this->name == name;
}

Talk* Conference::getTalk(int index) const {
    return talkList[index];
}

void Conference::print(ostream& ost) const {
    // prints metadata
    ost << "\nConference Details: \n-------------------\n" << "Name: " << name << "\nDesription: " << description << endl;

}
void Conference::printWithTalks(ostream& ost) const {
    // prints metadata
    print(ost);

    ost << "\nTalks: \n-----------------" << endl;
    // Prints talk list contents
    for (int i = 0; i < getSize(); i++) {
        ost << *talkList[i] << endl;
    }
}

void Conference::add(Talk* newTalk) {
    talkList+=newTalk;
}

ostream& operator<<(ostream& ost, const Conference& conf) {
    conf.print(ost);
    return ost;
}