#pragma once
#include <unordered_map>
#include <typeinfo>
#include <cassert>
#include "components.h"
#include "system.h"



class SystemManager {

    private:
        std::unordered_map<const char*, System*> systemMap;
    
    private:
        template<typename T>
        void register_system() {
            const char* typeName = typeid(T).name();
            assert(systemMap.find(typeName) == systemMap.end());
            systemMap.insert({typeName, new T()});
        }
    
    public:
        SystemManager() {               
            register_system<TransformSystem>();            
            assert(systemMap.size() == NUM_COMPONENTS);
        }

        ~SystemManager() {
            for (auto& pair : systemMap) {
                delete pair.second;
            }
        }

        template<typename T>
        void insert(const Entity e) {
            systemMap[typeid(T).name()]->entities.insert(e);
        }

        template<typename T>
        void erase(const Entity e) {
            systemMap[typeid(T).name()]->entities.erase(e);
        }

        void entity_destroy(const Entity e) {
            for (auto& pair : systemMap) {
                pair.second->entities.erase(e);
            }
        }

        template<typename T>
        T* at() {
            return static_cast<T*>(systemMap[typeid(T).name()]);
        }

        void update(const float dt) {
            for (auto& pair : systemMap) {
                pair.second->update(dt);
            }
        }

        void draw() {
            for (auto& pair : systemMap) {
                pair.second->draw();
            }
        }

        void clear() {
            for (auto& pair : systemMap) {
                pair.second->entities.clear();
            }
        }



};

