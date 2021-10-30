#ifndef _SCARFY
#define _SCARFY

#include "raylib.h"

class Scarfy {
public:
    Scarfy();
    ~Scarfy();
    float getWidth();
    float getHeight();
    void setPosition(float x, float y);
    void update(float deltaSeconds);
    void draw();
private:
    Texture2D texture;
    Rectangle source;
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    int frame;
    bool isInAir;
    float runningTime;
};

#endif
