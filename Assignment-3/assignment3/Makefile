all: a3 a3test

objects = main.o Control.o View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o
testobjects = test.o TestControl.o  View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o


a3: $(objects)
	g++ -g -o a3 $(objects) 

a3test: $(testobjects) 
	g++ -g -o a3test $(testobjects) 

main.o: main.cc Control.h 
	g++ -g -c main.cc 

test.o: test.cc TestControl.h
	g++ -g -c test.cc

Control.o: Control.h Control.cc
	g++ -g -c Control.cc

TestControl.o: TestControl.cc TestControl.h
	g++ -g -c TestControl.cc
	
View.o: View.cc View.h
	g++ -g -c View.cc
	
Lab.o: Lab.cc Lab.h
	g++ -g -c Lab.cc

Entity.o: Entity.cc Entity.h
	g++ -g -c Entity.cc

LabWorkList.o: LabWorkList.h LabWorkList.cc
	g++ -g -c LabWorkList.cc

LabWork.o: LabWork.h LabWork.cc
	g++ -g -c LabWork.cc

LabTech.o: LabTech.cc LabTech.h Entity.h
	g++ -g -c LabTech.cc 

Patient.o: Patient.cc Patient.h 
	g++ -g -c Patient.cc

Tester.o: Tester.cc Tester.h
	g++ -g -c Tester.cc
	

clean:
	rm -f a3 a3test *.o