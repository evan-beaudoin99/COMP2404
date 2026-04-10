

#include "Search.h"

// ostream& operator<<(ostream& ost, const Talk& t) {
//     t.print(ost);
//     return ost;
// }

// S_Search Implementation

S_Search::S_Search(const string& speaker) {
    this->speaker = speaker;
}

bool S_Search::matches(const Talk* talk) const {
    return talk->getSpeaker() == this->speaker;
}

void S_Search::print(ostream& ost) const {
    ost << "Talk given by: " << speaker << endl;
}

// K_Search Implementation

K_Search::K_Search(const string& keyword) {
    this->keyword = keyword;
}

bool K_Search::matches(const Talk* talk) const {
    return talk->contains(this->keyword);
}

void K_Search::print(ostream& ost) const {
    ost << "Matches talks whose keywords contain: " << keyword << endl;
}

// SK_Search Implementation

SK_Search::SK_Search(const string& speaker, const string& keyword)
    : S_Search(speaker), K_Search(keyword) {}

bool SK_Search::matches(const Talk* talk) const {
    return S_Search::matches(talk) || K_Search::matches(talk);
}

void SK_Search::print(ostream& ost) const {
    ost << "Matches talks with speaker \"" << speaker
        << "\" or keywords containing \"" << keyword << "\"" << endl;
}