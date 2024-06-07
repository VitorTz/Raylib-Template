#include "../include/entity_array.h"


EntityArray::EntityArray() : mSize(0) {
    entityToIndex.reserve(MAX_ENTITIES / entityToIndex.max_load_factor());
    indexToEntity.reserve(MAX_ENTITIES / indexToEntity.max_load_factor());
}


std::array<Entity, MAX_ENTITIES>::iterator EntityArray::begin() {
    return arr.begin();
}


std::array<Entity, MAX_ENTITIES>::iterator EntityArray::end() {
    return arr.begin() + mSize;
}


void EntityArray::insert(const Entity e) {
    assert(entityToIndex.find(e) == entityToIndex.end());
    entityToIndex[e] = mSize;
    indexToEntity[mSize] = e;
    arr[mSize++] = e;
}


void EntityArray::erase(const Entity e) {
    if (entityToIndex.find(e) != entityToIndex.end()) {
        const std::size_t removedIndex = entityToIndex[e];
        const std::size_t lastIndex = --mSize;
        const Entity lastIndexEntity = arr[lastIndex];
    
        arr[removedIndex] = lastIndexEntity;

        entityToIndex[lastIndexEntity] = removedIndex;
        indexToEntity[removedIndex] = lastIndexEntity;
    
        entityToIndex.erase(e);
        indexToEntity.erase(lastIndex);
    }    
}


void EntityArray::clear() {
    entityToIndex.clear();
    indexToEntity.clear();
    mSize = 0;
}


std::size_t EntityArray::size() const {
    return mSize;
}


bool EntityArray::empty() const {
    return mSize == 0;
}