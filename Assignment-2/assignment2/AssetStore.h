#ifndef ASSETSTORE_H
#define ASSETSTORE_H

#include "AssetArray.h"
#include <iostream>

class AssetStore {
    private:
        AssetArray assets;
    public:
        // Constructors & Destructors
        AssetStore();
        ~AssetStore();

        // Crud functions
        bool addAsset(const string& name, const string& description, const string& icon);

        void deleteAsset(int index);

        Asset* getAsset(int index) const;

        void printAssets() const;
        void printAssetDetails(int index) const;
};

#endif