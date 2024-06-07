#include "../include/scene.h"
#include <raylib.h>


MainScene::MainScene() {

}


SceneId MainScene::update() {        
    return MainSceneId;
}


void MainScene::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
}