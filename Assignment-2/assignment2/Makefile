
objects = View.o ProjectManager.o AssetStore.o ProjectArray.o Project.o AssetArray.o Asset.o Tester.o 
CXXFLAGS = -g

all: a2 a2test

a2: main.o $(objects) Control.o
	g++ $(CXXFLAGS) -o a2 main.o $(objects) Control.o

a2test: testmain.o $(objects) TestControl.o
	g++ $(CXXFLAGS) -o a2test testmain.o $(objects) TestControl.o

testmain.o: testmain.cc
	g++ $(CXXFLAGS) -c testmain.cc

main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc 

View.o: View.h View.cc 
	g++ $(CXXFLAGS) -c View.cc

Control.o: Control.h Control.cc
	g++ $(CXXFLAGS) -c Control.cc

TestControl.o: TestControl.h TestControl.cc 
	g++ $(CXXFLAGS) -c TestControl.cc

ProjectManager.o: ProjectManager.h ProjectManager.cc 
	g++ $(CXXFLAGS) -c ProjectManager.cc

AssetStore.o: AssetStore.h AssetStore.cc
	g++ $(CXXFLAGS) -c AssetStore.cc

ProjectArray.o: ProjectArray.h ProjectArray.cc
	g++ $(CXXFLAGS) -c ProjectArray.cc

Project.o: Project.cc Project.h
	g++ $(CXXFLAGS) -c Project.cc

AssetArray.o: AssetArray.cc AssetArray.h
	g++ $(CXXFLAGS) -c AssetArray.cc
	
Asset.o: Asset.cc Asset.h 
	g++ $(CXXFLAGS) -c Asset.cc

Tester.o: Tester.cc Tester.h
	g++ $(CXXFLAGS) -c Tester.cc

clean:
	rm -f a2 a2test *.o	