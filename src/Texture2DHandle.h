#ifndef _TEXTURE_2D_HANDLE
#define _TEXTURE_2D_HANDLE

#include <string>
#include "raylib.h"

class Texture2DHandle {
public:
    Texture2DHandle(std::string file);
    Texture2DHandle(const Texture2DHandle&) = delete;
    Texture2DHandle& operator=(const Texture2DHandle&) = delete;
    Texture2DHandle(Texture2DHandle&&) = delete;
    Texture2DHandle& operator=(Texture2DHandle&&) = delete;
    ~Texture2DHandle();
    const Texture2D texture;
};

#endif
