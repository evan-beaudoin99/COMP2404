#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <iostream>
#include "ProjectArray.h"
#include "Project.h"

class ProjectManager {
    private:
        ProjectArray projects;

    public:
        // Constructors & Destructors
        ProjectManager();

        ~ProjectManager();

        // Crud functions
        bool addProject(const string& name, const string& description, const string& type);

        void deleteProject(int index);

        // Getters and setters
        Project* getProject(int index) const;

        void cloneProject(int cloneTo, int cloneFrom);

        // Print functions
        void printProjects() const;
        void printProjectDetails(int index) const;
};

#endif