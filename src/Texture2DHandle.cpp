#include "raylib.h"
#include "Texture2DHandle.h"

Texture2DHandle::Texture2DHandle(std::string file):
    texture{LoadTexture(file.c_str())} {}

Texture2DHandle::~Texture2DHandle() {
    UnloadTexture(texture);
}
