#ifndef TALK_H
#define TALK_H

#include <string>
#include <iostream>
#include <cctype> 


using namespace std;

class Talk {

    friend ostream& operator<<(ostream&, const Talk&);

    private:
        string title;
        string speaker;
        string keywords;
        string audio;
        string videoFile;

    public:

        Talk(const string& title = "", const string& speaker = "", const string& keywords = "", const string& audio = "", const string& videoFile = "");
        ~Talk();

        const string& getTitle() const {return title;}
        const string& getSpeaker() const {return speaker;}
        const string& getKeywords() const {return keywords;}
        const string& getAudio() const {return audio;}
        const string& getVideoFile() const {return videoFile;}

        bool contains(const string& target) const;

        void print(ostream&) const;
};

#endif