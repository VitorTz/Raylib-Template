#include "../include/system.h"
#include "../include/globals.h"
#include <iostream>

void CircleSystem::update(const float dt) {
    
}


void CircleSystem::draw() {    
    for (const Entity e : entities) {    
        transform_t& t = gEcs->getComponent<transform_t>(e);
        circle_t& c = gEcs->getComponent<circle_t>(e);
        DrawCircleV(t.pos, c.radius, c.color);
        if (t.pos.y > SCREEN_HEIGHT) {
            gEcs->enity_destroy(e);
        }
    }
}

