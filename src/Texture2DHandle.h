// Texture2DHandle
//
// Handle to a Texture2D structure loaded by Raylib.
// Uses RAII (constructor acquires resource and destructor frees the resource).
//
// An instance of Texture2DHandle cannot be copied or moved.
// Designed to be managed by a smart pointer.
//

#ifndef _TEXTURE_2D_HANDLE
#define _TEXTURE_2D_HANDLE

#include <string>
#include "raylib.h"

class Texture2DHandle {
public:
    Texture2DHandle(std::string file);
    // Cannot be copied or moved. Meant to be managed by a smart pointer.
    Texture2DHandle(const Texture2DHandle&) = delete;
    Texture2DHandle& operator=(const Texture2DHandle&) = delete;
    Texture2DHandle(Texture2DHandle&&) = delete;
    Texture2DHandle& operator=(Texture2DHandle&&) = delete;
    ~Texture2DHandle();
    const Texture2D texture;
};

#endif
