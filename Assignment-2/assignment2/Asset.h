#ifndef ASSET_H
#define ASSET_H

#include "defs.h"
#include <string>
#include <iostream>


using namespace std;

class Asset {

    private:         
        string name;
        string description;
        string icon;

    public:
        // Constructors
        Asset(const string& name, const string& description, const string& icon);
        Asset(const Asset&) = default;
        // Getters
        string getName() const;

        // Print
        void print() const;
        void printWithIcon() const;
};

#endif