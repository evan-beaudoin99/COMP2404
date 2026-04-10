
#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include "Talk.h"

using namespace std;

class Search {
    public:
        virtual bool matches(const Talk*) const = 0;
        virtual void print(ostream&) const = 0;
        virtual ~Search() = default;
};


class S_Search : virtual public Search {
    protected:
        string speaker;
    public:
        S_Search(const string&);
        bool matches(const Talk*) const override;
        void print(ostream&) const override;
};

class K_Search : virtual public Search {
    protected:
        string keyword;
    public:
        K_Search(const string&);
        bool matches(const Talk*) const override;
        void print(ostream&) const override;
};

class SK_Search : public S_Search, public K_Search {
    public:
        SK_Search(const string& speaker, const string& keyword);
        bool matches(const Talk*) const override;
        void print(ostream&) const override;
};

inline ostream& operator<<(ostream& ost, const Search& s) {
    s.print(ost);
    return ost;
}

#endif