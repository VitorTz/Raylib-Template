#include "../include/scene.h"



MainScene::MainScene() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        const Entity e = gEcs->entity_create();
        transform_t& t = gEcs->getComponent<transform_t>(e);
        t.pos.x = randint(0, SCREEN_WIDTH);
        t.pos.y = randint(0, SCREEN_HEIGHT) - SCREEN_HEIGHT;
        t.speed = randFloat(100.f, 300.f);
        t.direction.y = 1.f;
        gEcs->addComponent<circle_t>(e, circle_t{5.f, BLUE});
        gEcs->addToSystem<CircleSystem>(e);
    }
}


SceneId MainScene::update() {    
    gEcs->update(GetFrameTime());
    return MainSceneId;
}


void MainScene::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
        gEcs->draw();
    EndDrawing();
}