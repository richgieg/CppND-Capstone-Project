// Enemy
//
// Implements the game's enemy entity.
//

#ifndef _ENEMY
#define _ENEMY

#include "Entity.h"

class Enemy : public Entity {
public:
    Enemy();
    void update(float deltaSeconds) override;
};

#endif
