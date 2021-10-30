#ifndef _ENTITY
#define _ENTITY

#include <string>
#include "raylib.h"

class Entity {
public:
    Entity(std::string spritesheetFile, int spritesheetRows, int spritesheetColumns, int spritesheetFrames);
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
    int currentFrame;
    bool isInAir;
    float runningTime;
};

#endif
