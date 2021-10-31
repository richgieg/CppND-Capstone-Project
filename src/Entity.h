// Entity
//
// Base class for game entities (player, enemies, etc.).
//

#ifndef _ENTITY
#define _ENTITY

#include <string>
#include <memory>
#include "raylib.h"
#include "Texture2DHandle.h"

class Entity {
public:
    Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet);
    float getWidth() const;
    float getX() const;
    void setX(float pixels);
    void setVelocityX(float pixelsPerSecond);
    void setJumpVelocity(float pixelsPerSecond);
    bool getActive() const;
    void setActive(bool value);
    void jump();
    bool collidesWith(const Entity& other) const;
    virtual void update(float deltaSeconds);
    void draw() const;
private:
    std::shared_ptr<Texture2DHandle> texturePtr;
    Rectangle source;
    Vector2 position;
    Vector2 velocity;
    float jumpVelocity;
    int framesInSpritesheet;
    int currentFrame;
    bool isInAir;
    float runningTime;
    bool active;
};

#endif
