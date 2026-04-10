#ifndef SUMMITSTREAM_H
#define SUMMITSTREAM_H


#include "Conference.h"
#include "List.h"
#include "Search.h"

class SummitStream {

    private:
        List<Conference*> conferences;

    public:
        SummitStream();
        ~SummitStream();

        void addConference(Conference* conference) {conferences+=conference;}
        bool addTalk(Talk*, const string&);

        const List<Conference*>& getConferences() const {return this->conferences;}

        Conference* getConference(int index) const {return conferences[index];}
        Conference* getConference(const string& c_name) const;

        void getTalks(const Search& talk_search, List<Talk*>& talkList);
};

#endif