#include "SummitStream.h"

#include <iostream>

SummitStream::SummitStream() = default;

SummitStream::~SummitStream() {
    for (int i = 0; i < conferences.getSize(); i++) {
        delete conferences[i];
    }
}

bool SummitStream::addTalk(Talk* talk, const string& c_name) {
    for (int i = 0; i < conferences.getSize(); i++) {
        if (*conferences[i] == c_name) {
            conferences[i]->add(talk);
            return true;
        }
    }
    cout << "Error: no conference named \"" << c_name << "\"" << endl;
    return false;
}        


Conference* SummitStream::getConference(const string& c_name) const {
    for (int i = 0; i < conferences.getSize(); i++) {
        if (*conferences[i] == c_name) {
            return conferences[i];
        }
    }
    cout << "Error: no conference named \"" << c_name << "\"" << endl;
    exit(1);
}

void SummitStream::getTalks(const Search& talk_search, List<Talk*>& talkList) {

    for (int i = 0; i < conferences.getSize(); i++) {
        for (int j = 0; j < conferences[i]->getSize(); j++) {

            if (talk_search.matches(conferences[i]->getTalk(j))) {
                talkList+=conferences[i]->getTalk(j);
            }
        }
    }


}
