#pragma once
#include <queue>
#include <cassert>
#include "constants.h"
#include "types.h"


class EntityManager {

    private:
        std::queue<Entity> entities;
        std::size_t mSize;
    
    public:
        EntityManager();

        Entity entity_create();

        void entity_destroy(Entity e);

        void clear();

        std::size_t size() const;

};