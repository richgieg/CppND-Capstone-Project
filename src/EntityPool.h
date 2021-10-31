// EntityPool
//
// Manages a pool of entities.
//
// NOTE: Method definitions are in this header because this is a template class.
//

#ifndef _ENTITY_POOL
#define _ENTITY_POOL

#include <vector>
#include <algorithm>

template<typename T>
class EntityPool {

public:

    EntityPool(unsigned int size): entities{size} {}

    typename std::vector<T>::iterator begin() {
        return entities.begin();
    }

    typename std::vector<T>::iterator end() {
        return entities.end();
    }

    // Returns an iterator which points to the first inactive entity in the pool.
    // If all entities are currently active then the iterator will be equal to end().
    typename std::vector<T>::iterator getFirstInactive() {
        return std::find_if(entities.begin(), entities.end(), [](T& entity) {
            return !entity.getActive();
        });
    }

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
