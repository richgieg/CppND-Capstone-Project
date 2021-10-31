#ifndef _SCARFY
#define _SCARFY

#include "Entity.h"

class Scarfy : public Entity {
public:
    Scarfy();
    void update(float deltaSeconds) override;
};

#endif
