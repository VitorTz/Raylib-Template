#include "../include/system.h"
#include "../include/util.h"
#include "../include/ecs.h"


void TransformSystem::update(const float dt) {
    for (const Entity e : entities) {
        transform_t& t = gEcs->get_transform(e);
        const float distance = dt * t.speed;
        normalize_vector(&t.direction);
        t.lastMovement.x = distance * t.direction.x;
        t.lastMovement.y = distance * t.direction.y;
        t.pos.x += t.lastMovement.x;
        t.pos.y += t.lastMovement.y;        
    }
}


void TransformSystem::draw() {

}