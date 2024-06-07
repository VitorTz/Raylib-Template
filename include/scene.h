#pragma once
#include <memory>


enum SceneId {
    MainSceneId
};


constexpr static SceneId FIRST_SCENE = SceneId::MainSceneId;

class Scene;


class SceneManager {

    private:
        std::unique_ptr<Scene> scene;   
        SceneId currentScene = FIRST_SCENE;
        bool shouldChangeScene = false;  
    
    private:        
        void load_next_scene(SceneId nextScene);

    public:
        SceneManager();
        void update();       
        void draw();

};


class Scene {

    public:        
        virtual ~Scene() = default;
        virtual SceneId update() = 0;
        virtual void draw() = 0;

};


class MainScene : public Scene {

    public:
        MainScene();
        SceneId update() override;
        void draw() override;

};