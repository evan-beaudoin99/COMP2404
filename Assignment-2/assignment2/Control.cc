
#include "Control.h"
#include "ProjectManager.h"
#include <limits>
#include <vector>

using namespace std;
#define NUM_PROJECTS 4
#define NUM_TYPE 5
extern const  string DESCRIPTION[NUM_PROJECTS];
extern const  string TYPE[NUM_TYPE];
extern const string projectNames[5];
extern int description[5];
extern int type[5];
extern const string assetNames[10];
extern const string descriptions[10];
extern const string icons[10];



void Control::launch(){

    vector<string> menu ={
        "Print assets",
        "Print projects",
        "Print project assets",
        "Add assets to project", 
        "Delete asset",
        "Delete project",
        "Clone project"
    };

    initAssets();
    initProjects();
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printAssets(); break;
            case 2: printProjects(); break;
            case 3: printProjectDetails(); break;
            case 4: addAssetsToProject(); break;
            case 5: deleteAsset(); break;
            case 6: deleteProject(); break;
            case 7: cloneProject(); break;
        }
    }
    cout<<"exiting program!!!"<<endl;
}

void Control::initAssets(){
    cout<<"Initializing assets..."<<endl;
    for (int i = 0; i < 10; ++i){
        assetStore.addAsset(assetNames[i], descriptions[i], icons[i]);
    }
    cout<<"Assets initialized!"<<endl;
}

void Control::initProjects(){
    cout<<"Initializing projects..."<<endl;
    for (int i = 0; i < 5; ++i){
        projectManager.addProject(projectNames[i], DESCRIPTION[description[i]], TYPE[type[i]]);
    }
    cout<<"Projects initialized!"<<endl;
}

void Control::printAssets(){
    cout<<"Printing assets..."<<endl;
    assetStore.printAssets();
    cout<<"Assets printed!"<<endl;
}

void Control::printProjects(){
    cout<<"Printing projects..."<<endl;
    projectManager.printProjects();
    cout<<"Projects printed!"<<endl;
}

void Control::printAssetDetails(){
    printAssets();
    int index;
    view.getNumber(index);
    cout<<"Printing asset details..."<<endl;
    assetStore.printAssetDetails(index);
}

void Control::printProjectDetails(){
    int index;

    cout << "Enter project index: ";
    cin >> index;

    Project* p = projectManager.getProject(index);

    if (p == nullptr) {
        cout << "Error: Project does not exist." << endl;
        return;
    }

    p->printAssets();   // prints metadata + assets
}

void Control::addAssetsToProject(){
    cout << "Choose project to install on:" << endl;

    // Print projects
    projectManager.printProjects();

    cout << "Please make a selection: ";
    int projectIndex;
    cin >> projectIndex;

    Project* project = projectManager.getProject(projectIndex);

    if (project == nullptr) {
        cout << "Error: Project does not exist." << endl;
        return;
    }

    cout << "How many assets are you installing?" << endl;
    cout << "Please make a selection: ";

    int numAssets;
    cin >> numAssets;

    for (int i = 0; i < numAssets; i++) {

        assetStore.printAssets();

        cout << "Please make a selection: ";
        int assetIndex;
        cin >> assetIndex;

        Asset* asset = assetStore.getAsset(assetIndex);

        if (asset == nullptr) {
            cout << "Error: Asset does not exist." << endl;
            continue;  
        }

        cout << "Adding asset to project..." << endl;

        if (!project->addAsset(*asset)) {
            cout << "Error: Project is full." << endl;
        }
    }
}

void Control::deleteAsset(){
    int index;

    cout << "Enter asset index to delete: ";
    cin >> index;

    assetStore.deleteAsset(index);
}

void Control::deleteProject() {
    int index;

    cout << "Enter project index to delete: ";
    cin >> index;

    projectManager.deleteProject(index);
}

void Control::cloneProject() {
    int fromIndex, toIndex;

    cout << "Clone FROM project index: ";
    cin >> fromIndex;

    cout << "Clone TO project index: ";
    cin >> toIndex;

    projectManager.cloneProject(toIndex, fromIndex);

}

#define NUM_PROJECTS 4
#define NUM_TYPE 5

const  string DESCRIPTION[NUM_PROJECTS]={"My attempt at 3D", "Aliens invading Earth", "Work in progress", "RPG perhaps?"};
const  string TYPE[NUM_TYPE] = {"Generic 3D", "Generic 2D", "FPS", "Platformer", "Rogue-like"};

const string projectNames[5] = {"My 3D Game", "Alien Attack", "Learning To Make Games", "Paladin!", "Dog Catcher Simulator"};
int description[5] = {0, 1, 3, 2, 2};
int type[5] = {0, 1, 2, 3, 4};

const string assetNames[10] = {"Cat", "Dog", "Car", "Truck", "Rocket", "Airplane", "Fish", "Bird", "House", "Phone"};
const string descriptions[10] = {"A cute cat asset", "A friendly dog asset", "A fast car asset", "A big truck asset", "A powerful rocket asset", "A sleek airplane asset", "A colorful fish asset", "A chirpy bird asset", "A cozy house asset", "A smart phone asset"};

const string icons[10] = {
R"(
 /\_/\ 
( o.o )
 > ^ <
)", // cat

R"(
 /^ ^\
/ 0 0 \
V\ Y /V
 / - \
 |    \
 || (__V
)", // dog

R"(
  ______
 //  ||\ \
_____||_\___
 )  _          \
 |_/ \_________|
___\_/_________/
)", // car

R"(
 ___________
|  _ _ _   |
| | | | |  |
|_|_|_|_|__|
   O     O
)", // truck

R"(
    /\
   /  \
   |  |
   |  |
  /____\
    ||
    ||
)", // rocket

R"(
     __|__
--o--(_)--o--
)", // airplane

R"(
   ><(((('>
)", // fish

R"(
  \\
 (o>
 //\
 V_/_
)", // bird

R"(
   /\ 
  /  \
 /____\
 | [] |
 |____|
)", // house

R"(
  ______
 |  __ |
 | |__||
 |______|
   |  |
)", // phone
};