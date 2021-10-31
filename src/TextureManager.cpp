#include "raylib.h"
#include "TextureManager.h"

std::shared_ptr<Texture2DHandle> TextureManager::getTexture(std::string file) {
    auto iterator = textureHandleMap.find(file);
    if (iterator != textureHandleMap.end()) { // already in map
        return iterator->second;
    } else { // load and add to map
        auto handle = std::make_shared<Texture2DHandle>(file);
        textureHandleMap.emplace(file, handle);
        return handle;
    }
}

TextureManager textureManager;
