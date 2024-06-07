#pragma once
#include <unordered_map>
#include <array>
#include <cassert>
#include "constants.h"
#include "types.h"


typedef std::pair<std::array<Entity, MAX_ENTITIES>::iterator, std::array<Entity, MAX_ENTITIES>::iterator> EntityArrayIterator;


class EntityArray {

    private:
        std::array<Entity, MAX_ENTITIES> arr;
        std::unordered_map<Entity, std::size_t> entityToIndex;
        std::unordered_map<std::size_t, Entity> indexToEntity;
        std::size_t mSize;

    public:
        EntityArray();        
        std::array<Entity, MAX_ENTITIES>::iterator begin();
        std::array<Entity, MAX_ENTITIES>::iterator end();
        void insert(Entity e);
        void erase(Entity e);
        void clear();
        std::size_t size() const;
        bool empty() const;

};