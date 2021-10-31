// TextureManager
//
// Singleton that manages the loading and caching of textures.
//

#ifndef _TEXTURE_MANAGER
#define _TEXTURE_MANAGER

#include <memory>
#include <unordered_map>
#include <string>
#include "Texture2DHandle.h"

class TextureManager {
public:
    // Returns the TextureManager singleton.
    static TextureManager& getInstance();
    // Finds a texture in cache and returns it.
    // If not loaded yet then it is loaded, stored in the cache, and returned.
    std::shared_ptr<Texture2DHandle> getTexture(std::string file);
private:
    std::unordered_map<std::string, std::shared_ptr<Texture2DHandle>> textureHandleMap;
};

#endif
