
#ifndef PROJECTARRAY_H
#define PROJECTARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Project.h"
#include "defs.h"

using namespace std;

class ProjectArray {
		
	public:
		//constructor
		ProjectArray();
		
		//destructor
		~ProjectArray();
		
		//other
		bool add(Project*);
		Project* get(int) const;
		Project* get(const string&) const;
		Project* remove(const string& name);
		Project* remove(int);
		int size() const;
		bool isFull() const;
	
	private:
		int numProjects;
		Project** projects;
};
#endif
