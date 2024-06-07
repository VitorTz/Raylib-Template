#pragma once
#include <array>
#include <unordered_map>
#include <cassert>
#include "constants.h"
#include "types.h"


class IComponentArray {

    public:
        virtual ~IComponentArray() = default;
        virtual void erase(Entity e) = 0;
        virtual void clear() = 0;

};


template<typename T>
class ComponentArray : public IComponentArray {

    private:
        std::array<T, MAX_ENTITIES> arr;
        std::unordered_map<Entity, std::size_t> entityToIndex;
        std::unordered_map<std::size_t, Entity> indexToEntity;
        std::size_t mSize;
    
    public:
        ComponentArray() : mSize(0) { 
            entityToIndex.reserve(MAX_ENTITIES / entityToIndex.max_load_factor());
            indexToEntity.reserve(MAX_ENTITIES / indexToEntity.max_load_factor());
        }

        void erase(const Entity e) override {
            if (entityToIndex.find(e) != entityToIndex.end()) {
                const std::size_t removeComponentIndex = entityToIndex[e];
                const std::size_t lastComponentIndex = --mSize;
                const Entity lastComponentEntity = indexToEntity[lastComponentIndex];
                
                arr[removeComponentIndex] = arr[lastComponentIndex];

                indexToEntity[removeComponentIndex] = lastComponentEntity;
                entityToIndex[lastComponentEntity] = removeComponentIndex;

                entityToIndex.erase(e);
                indexToEntity.erase(lastComponentIndex);
            }            
        }
        
        void insert(const Entity e, T c) {
            assert(entityToIndex.find(e) == entityToIndex.end());
            entityToIndex[e] = mSize;
            indexToEntity[mSize] = e;
            arr[mSize++] = c;
        }

        T& at(const Entity e) {
            assert(entityToIndex.find(e) != entityToIndex.end());
            return arr[entityToIndex[e]];
        }

        void clear() override {
            entityToIndex.clear();
            indexToEntity.clear();
            mSize = 0;
        }

        std::size_t size() const {
            return mSize;
        }

};