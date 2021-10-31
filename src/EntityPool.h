// EntityPool
//
// Manages a pool of entities.
//

#ifndef _ENTITY_POOL
#define _ENTITY_POOL

#include <vector>

template<typename T>
class EntityPool {
public:
    EntityPool(unsigned int size): entities{size} {}
    void update(float deltaSeconds) {
        for (auto& entity : entities) {
            entity.update(deltaSeconds);
        }
    }
    void draw() {
        for (auto& entity : entities) {
            entity.draw();
        }
    }
private:
    std::vector<T> entities;
};

#endif
