#include "../include/entity_manager.h"


EntityManager::EntityManager() : mSize(0) {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entities.push(i);
    }    
}


Entity EntityManager::entity_create() {
    assert(mSize < MAX_ENTITIES);
    const Entity e = entities.front();
    entities.pop();
    mSize++;
    return e;
}


void EntityManager::entity_destroy(const Entity e) {
    entities.push(e);
    mSize--;
}


void EntityManager::clear() {
    std::queue<Entity> empty;
    std::swap(entities, empty);
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entities.push(i);
    }    
    mSize = 0;
}


std::size_t EntityManager::size() const {
    return mSize;
}