// TextureManager
//
// Facilitates the loading, caching, and reuse of textures.
//

#ifndef _TEXTURE_MANAGER
#define _TEXTURE_MANAGER

#include <memory>
#include <unordered_map>
#include <string>
#include "Texture2DHandle.h"

class TextureManager {
public:
    // Finds a texture in cache and returns it.
    // If not loaded yet then it is loaded, stored in the cache, and returned.
    std::shared_ptr<Texture2DHandle> getTexture(std::string file);
private:
    std::unordered_map<std::string, std::shared_ptr<Texture2DHandle>> textureHandleMap;
};

extern TextureManager textureManager;

#endif
