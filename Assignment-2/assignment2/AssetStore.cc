

#include "AssetStore.h"

AssetStore::AssetStore() {}

AssetStore::~AssetStore() {
    for (int i = 0; i < assets.size(); i++) {
        delete assets.get(i);
    }
}

bool AssetStore::addAsset(const string& name,
                          const string& description,
                          const string& icon) {

    Asset* newAsset = new Asset(name, description, icon);

    if (!assets.add(newAsset)) {
        cout << "Error: AssetStore is full." << endl;
        delete newAsset;   // prevent memory leak
        return false;
    }

    cout << "Asset " << name << " added" << endl;

    return true;
}

void AssetStore::deleteAsset(int index) {

    Asset* a = assets.get(index);

    if (a == nullptr) {
        cout << "Error: No Asset exists at index " << index << endl;
        return;
    }

    delete a;                 // free memory
    assets.remove(index);     // remove pointer from array
}

Asset* AssetStore::getAsset(int index) const {
    return assets.get(index);
}

void AssetStore::printAssets() const {

    cout << "\nAssets: " << endl; 
    for (int i = 0; i < assets.size(); i++) {
        cout << i << ": ";
        assets.get(i)->print();
        cout << endl;
    }
}

void AssetStore::printAssetDetails(int index) const {

    Asset* a = assets.get(index);

    if (a == nullptr) {
        cout << "Error: No Asset exists at index " << index << endl;
        return;
    }

    a->printWithIcon();
}