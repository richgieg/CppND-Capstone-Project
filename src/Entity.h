#ifndef _ENTITY
#define _ENTITY

#include <string>
#include "raylib.h"

class Entity {
public:
    Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet);
    ~Entity();
    void setX(float pixels);
    void setJumpVelocity(float pixelsPerSecond);
    void update(float deltaSeconds);
    void draw();
private:
    Texture2D texture;
    Rectangle source;
    Vector2 position;
    Vector2 velocity;
    float jumpVelocity;
    int framesInSpritesheet;
    int currentFrame;
    bool isInAir;
    float runningTime;
};

#endif
