#include <iostream>
#include "raylib.h"
#include "TextureManager.h"

std::shared_ptr<Texture2DHandle> TextureManager::get(std::string file) {
    auto iterator = textureHandleMap.find(file);
    if (iterator != textureHandleMap.end()) { // already in map
        std::cout << "already in map: " << file << "\n";
        return iterator->second;
    } else { // load and add to map
        std::cout << "adding to map: " << file << "\n";
        auto handle = std::make_shared<Texture2DHandle>(file);
        textureHandleMap.emplace(file, handle);
        return handle;
    }
}

// Global TextureManager singleton
TextureManager textureManager;
