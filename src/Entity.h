#ifndef _ENTITY
#define _ENTITY

#include "raylib.h"

class Entity {
public:
    Entity();
    ~Entity();
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
    int frame;
    bool isInAir;
    float runningTime;
};

#endif
