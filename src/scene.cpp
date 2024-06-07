#include "../include/scene.h"



SceneManager::SceneManager() {
    this->load_next_scene(SceneId::MainSceneId);
}


void SceneManager::load_next_scene(const SceneId nextScene) {
    switch (nextScene) {
        case SceneId::MainSceneId:
            this->scene = std::make_unique<MainScene>();
            break;
        default:
            break;
    }
    this->currentScene = nextScene;
}


void SceneManager::update() {
    const SceneId nextScene = this->scene->update();
    if (nextScene != this->currentScene) {
        this->load_next_scene(nextScene);
    }
}


void SceneManager::draw() {
    this->scene->draw();
}