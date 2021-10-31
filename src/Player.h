// Player
//
// Implements the game's player entity.
//

#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    void update(float deltaSeconds) override;
};

#endif
