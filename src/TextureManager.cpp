#include <iostream>
#include "raylib.h"
#include "TextureManager.h"

static TextureManager::TextureManager& getInstance() {
    static TextureManager instance; // Instantiated on first use.
    return instance;
}

std::shared_ptr<Texture2DHandle> TextureManager::getTexture(std::string file) {
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
