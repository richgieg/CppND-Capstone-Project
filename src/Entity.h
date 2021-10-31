#ifndef _ENTITY
#define _ENTITY

#include <string>
#include <memory>
#include "raylib.h"
#include "Texture2DHandle.h"

class Entity {
public:
    Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet);
    Entity(const Entity&) = delete; // disallow copy construction
    Entity& operator=(const Entity&) = delete; // disallow copy assignment
    Entity(Entity&&); // move constructor
    Entity& operator=(Entity&&); // move assignment
    ~Entity();
    void setX(float pixels);
    void setJumpVelocity(float pixelsPerSecond);
    void jump();
    virtual void update(float deltaSeconds);
    void draw();
private:
    std::unique_ptr<Texture2DHandle> texturePtr;
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
