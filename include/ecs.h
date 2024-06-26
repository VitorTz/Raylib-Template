#pragma once
#include <memory>
#include "component_manager.h"
#include "entity_manager.h"
#include "system_manager.h"


class ECS {

    private:
        std::unique_ptr<ComponentManager> componentManager;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<SystemManager> systemManager;
        EntityArray entitiesToDestroy;
        bool shouldClearAllEntities = false;
    
    public:
        ECS(

        ) : componentManager(std::make_unique<ComponentManager>()),
            entityManager(std::make_unique<EntityManager>()),
            systemManager(std::make_unique<SystemManager>()) {

        }

        Entity entity_create() {
            const Entity e = entityManager->entity_create();
            componentManager->insert<transform_t>(e, transform_t{});
            systemManager->insert<TransformSystem>(e);
            return e;
        }

        void enity_destroy(const Entity e) {
            entitiesToDestroy.insert(e);            
        }

        transform_t& get_transform(const Entity e) {
            return componentManager->transform_array->at(e);
        }

        template<typename T>
        void addComponent(const Entity e, T c) {
            componentManager->insert<T>(e, std::move(c));
        }    

        template<typename T>
        T& getComponent(const Entity e) {
            return componentManager->at<T>(e);
        }
        
        template<typename T>
        void rmvComponent(const Entity e) {
            componentManager->erase<T>(e);            
        }

        template<typename T>
        void addToSystem(const Entity e) {
            systemManager->insert<T>(e);
        }

        template<typename T>
        void rmvFromSystem(const Entity e) {
            systemManager->erase<T>(e);
        }

        void update(const float dt) {
            systemManager->update(dt);
            if (shouldClearAllEntities) {
                entitiesToDestroy.clear();
                componentManager->clear();
                systemManager->clear();
                entityManager->clear();
                shouldClearAllEntities = false;
            }
            for (const Entity e : entitiesToDestroy) {
                entityManager->entity_destroy(e);
                systemManager->entity_destroy(e);
                componentManager->entity_destroy(e);
                entitiesToDestroy.clear();
            }
        }

        void draw() {
            systemManager->draw();
        }

        void clear() {
            shouldClearAllEntities = true;            
        }        

};


inline std::unique_ptr<ECS> gEcs = std::make_unique<ECS>();