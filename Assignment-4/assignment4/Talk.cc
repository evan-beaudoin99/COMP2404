
#include "Talk.h"

Talk::Talk(const string& title, const string& speaker, const string& keywords, const string& audio, const string& videoFile)
    : title(title), 
      speaker(speaker),
      keywords(keywords),
      audio(audio),
      videoFile(videoFile) {}

Talk::~Talk() {}

bool Talk::contains(const string& target) const {

    string lowerTarget = target;
    for (size_t i = 0; i < lowerTarget.length(); ++i) {
        lowerTarget[i] = static_cast<char>(tolower(static_cast<unsigned char>(lowerTarget[i])));
    }

    string lowerKeywords = keywords;
    for (size_t i = 0; i < lowerKeywords.size(); ++i) {
        lowerKeywords[i] = static_cast<char>(tolower(static_cast<unsigned char>(lowerKeywords[i])));
    }

    return lowerKeywords.find(lowerTarget) != string::npos;
}

ostream& operator<<(ostream& ost, const Talk& t) {
    t.print(ost);
    return ost;
}

void Talk::print(ostream& ost) const {
    ost << "\nSpeaker: " << speaker << "\nTitle: " << title << "\nKeywords: " << keywords << endl;
}