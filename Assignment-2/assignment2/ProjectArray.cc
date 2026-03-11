
#include "ProjectArray.h"

ProjectArray::ProjectArray(){
	numProjects = 0;
	projects = new Project*[MAX_ARRAY];
}

ProjectArray::~ProjectArray(){
	delete [] projects;
}


bool ProjectArray::add(Project* s){
	if (isFull()) return false;
	projects[numProjects++] = s;
	return true;
}

Project* ProjectArray::remove(const string& name){
	int index = 0;

	while (index < numProjects){
		if (projects[index]->getName() == name){ break; }
		++index;
	}

	if (index >= numProjects) return NULL;

	Project* goner;
	goner = projects[index];

	while (index < numProjects-1){
		projects[index] = projects[index+1];
		++index;
	}
	--numProjects;
	return goner;
}

Project* ProjectArray::remove(int i){
	if (i < 0 || i >= numProjects) return nullptr;
	Project* goner = projects[i];

	while (i < numProjects-1){
		projects[i] = projects[i+1];
		++i;
	}
	--numProjects;
	return goner;
}

Project* ProjectArray::get(const string& name) const{
	for (int i = 0; i < numProjects; ++i){
		if (projects[i]->getName() == name){
			return projects[i];
		}
	}
	return NULL;
}

Project* ProjectArray::get(int i) const {
	if (i < 0 || i >= numProjects) return nullptr;
	return projects[i];
}

bool ProjectArray::isFull() const{
	return numProjects >= MAX_ARRAY;
}

int ProjectArray::size() const{
	return numProjects;
}
