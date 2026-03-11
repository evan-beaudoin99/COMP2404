#ifndef PROJECT_H
#define PROJECT_H

#include "defs.h"
#include <string>
#include "AssetArray.h"

class Project {

    private:
        string name;
        string description;
        string type;
        AssetArray assets;

    public:
        // Constructors & Destructors
        Project(const string& name, const string& description, const string& type);
        ~Project();

        string getName() const;
        bool addAsset(const Asset& asset);
        bool deleteAsset(const string& name);
        void cloneAssetsFrom(const Project& other);
        int numAssets() const;
        void print() const;
        void printAssets() const;
};

#endif