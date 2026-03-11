#include "ProjectManager.h"

ProjectManager::ProjectManager() 
    : projects()
{
}

ProjectManager::~ProjectManager() {
    for (int i = 0; i < projects.size(); i++) {
        delete projects.get(i);
    }
}

// Crud functions
bool ProjectManager::addProject(const string& name, const string& description, const string& type)
{
    if (projects.isFull()) {
        cout << "Error: Project list is full.\n";
        return false;
    }

    Project* p = new Project(name, description, type);
    projects.add(p);

    cout << "Project " << name << " added" << endl;

    return true;
}


void ProjectManager::deleteProject(int index)
{
    Project* removed = projects.remove(index);

    if (removed == nullptr) {
        cout << "Error: No project exists at index "
             << index << ".\n";
        return;
    }

    delete removed;   // free memory
}

// Getters & Setters
Project* ProjectManager::getProject(int index) const {
    return projects.get(index);
}

void ProjectManager::cloneProject(int cloneTo, int cloneFrom) {
    Project* from = projects.get(cloneFrom);
    Project* to   = projects.get(cloneTo);

    if (from == nullptr) {
        cout << "Error: Source project does not exist.\n";
        return;
    }

    if (to == nullptr) {
        cout << "Error: Destination project does not exist.\n";
        return;
    }

    to->cloneAssetsFrom(*from);
}

void ProjectManager::printProjects() const {

    cout << "\nProjects: " << endl;
    for (int i = 0; i < projects.size(); i++) {
        cout << i << ": ";
        projects.get(i)->print();
        cout << endl;
    }
}

void ProjectManager::printProjectDetails(int index) const {
    Project* p = projects.get(index);

    if (p == nullptr) {
        cout << "Error: No project exists at index "
             << index << ".\n";
        return;
    }

    p->printAssets();
}