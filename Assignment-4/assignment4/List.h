#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class List {

	public:
		//constructor
		List();
				
		//destructor
		~List();
		
		//other
        List& operator+=(const T&);
        List& operator-=(const T&);

        const T& operator[](int) const;
        T& operator[](int);

		void clear();


		int getSize() const;
		bool isFull() const;
	
	
	private:
		int numElements;
		T* elements;
};

template <class T>
List<T>::List(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
List<T>::~List(){
	delete [] elements;
}

template <class T>
List<T>& List<T>::operator+=(const T& s){
	if (numElements >= MAX_ARRAY)   return *this;
  	elements[numElements++] = s;
	return *this;
}

template <class T>
List<T>& List<T>::operator-=(const T& s) {

	// find element and delete it
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			delete elements[index];
			--numElements;
			break;
		}
		++index;
	}


	// shift elements
	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <class T>
int List<T>::getSize() const{
	return numElements;
}

template <class T>
bool List<T>::isFull() const {
	return numElements >= MAX_ARRAY;
}

template <class T>
const T& List<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"List index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template <class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr<<"List index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
void List<T>::clear() {
	numElements = 0;
}




#endif