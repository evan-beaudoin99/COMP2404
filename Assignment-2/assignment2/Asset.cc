
#include "Asset.h"

Asset::Asset(const string& name, 
             const string& description, 
             const string& icon)
        : name(name),
          description(description),
          icon(icon)
{
}

// Getters
string Asset::getName() const {
    return name;
}

// Print
void Asset::print() const {
    cout << "\nName: " << name << "\nDescription: " << description << endl;
}
void Asset::printWithIcon() const {
    cout << "\nName: " << name 
         << "\nDescription: " << description 
         << "\nIcon: " << icon << endl;
}
