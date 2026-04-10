#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "List.h"
#include "Talk.h"

class Conference {
    friend ostream& operator<<(ostream&, const Conference&);

    private:
        List<Talk*> talkList;
        string name, description;

    public:
        Conference(const string& name, const string& description);
        ~Conference();

        bool operator==(const string& name) const;

        Talk* getTalk(int index) const;
        const string& getName() const {return this->name;}
        int getSize() const {return this->talkList.getSize();}

        void print(ostream&) const; 
        void printWithTalks(ostream& ost) const;

        void add(Talk* newTalk);

};

#endif