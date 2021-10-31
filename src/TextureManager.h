#ifndef _TEXTURE_MANAGER
#define _TEXTURE_MANAGER

#include <memory>
#include <unordered_map>
#include <string>
#include "Texture2DHandle.h"

class TextureManager {
public:
    std::shared_ptr<Texture2DHandle> get(std::string file);
private:
    std::unordered_map<std::string, std::shared_ptr<Texture2DHandle>> textureHandleMap;
};

// Global TextureManager singleton
extern TextureManager textureManager;

#endif
