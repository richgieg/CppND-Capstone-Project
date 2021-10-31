#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    void update(float deltaSeconds) override;
};

#endif
