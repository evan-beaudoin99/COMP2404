
#include "Project.h"

Project::Project(const string& name,
                 const string& description,
                 const string& type)
    : name(name),
      description(description),
      type(type),
      assets()   // default construct AssetArray
{
}

Project::~Project(){
    // Delete all assets owned by this project
    for (int i = 0; i < assets.size(); i++) {
        delete assets.get(i);
    }
}

// Crud functions
bool Project::addAsset(const Asset& asset) {
    if (assets.isFull()) return false;

    Asset* copy = new Asset(asset);
    assets.add(copy);

    return true;
}


bool Project::deleteAsset(const string& name) {
    Asset* removed = assets.remove(name);

    if (removed != nullptr) {
        delete removed;   // prevent memory leak
        return true;
    }

    return false;
}

// Getters & Setters
string Project::getName() const {
    return name;
}

int Project::numAssets() const {
    return assets.size();
}

void Project::cloneAssetsFrom(const Project& sourceProject) {

    if (this == &sourceProject) { // prevents a self copy
        cout << "Error: Self Copy not allowed" << endl;
        return;
    }

    // Delete current assets
    while (assets.size() > 0) {
        Asset* temp = assets.get(0);
        assets.remove(temp->getName());
        delete temp;
    }

    // Deep copy from other
    for (int i = 0; i < sourceProject.assets.size(); i++) {
        Asset* copy = new Asset(*(sourceProject.assets.get(i)));
        assets.add(copy);
    }
}

void Project::print() const {
    cout << "\nName:             " << name << 
            "\nDescription:      " << description << 
            "\nTYPE:             " << type <<
            "\nAssets:           " << numAssets() << endl;
}

void Project::printAssets() const {

    print(); // Prints metadata for this project

    // Prints all assets
    for (int i = 0; i < assets.size(); i++) {
        assets.get(i)->print();
    }
}