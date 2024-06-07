#pragma once
#include "component_array.h"
#include <cassert>
#include <typeinfo>
#include "components.h"


class ComponentManager {

    private:
        std::unordered_map<const char*, IComponentArray*> componentArrayMap;
    
    public:
        ComponentArray<transform_t>* transform_array;        

    private:
        template<typename T>
        ComponentArray<T>* get_array() {
            const char* typeName = typeid(T).name();
            return static_cast<ComponentArray<T>*>(componentArrayMap[typeName]);
        }
        
        template<typename T>
        void register_component() {
            const char* typeName = typeid(T).name();
            assert(componentArrayMap.find(typeName) == componentArrayMap.end());
            componentArrayMap.emplace(typeName, new ComponentArray<T>());
        }
        
    
    public:
        // TODO: Register all components here
        ComponentManager() {            
            register_component<transform_t>();            
            transform_array = get_array<transform_t>();
            assert(componentArrayMap.size() == NUM_COMPONENTS);
        }

        ~ComponentManager() {
            for (auto& pair : componentArrayMap) {
                delete pair.second;
            }
        }

        template<typename T>
        void insert(const Entity e, T c) {
            ComponentArray<T>* arr = get_array<T>();
            arr->insert(e, std::move(c));
        }

        template<typename T>
        T& at(const Entity e) {
            ComponentArray<T>* arr = get_array<T>();
            return arr->at(e);
        }

        template<typename T>
        void erase(const Entity e) {
            ComponentArray<T>* arr = get_array<T>();
            return arr->erase(e);
        }

        template<typename T>
        void clear_array() {
            ComponentArray<T>* arr = get_array<T>();
            return arr->clear();
        }
        
        void entity_destroy(const Entity e) {
            for (auto& pair : componentArrayMap) {
                pair.second->erase(e);
            }
        }

        void clear() {
            for (auto& pair : componentArrayMap) {
                pair.second->clear();
            }
        }

};


