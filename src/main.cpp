#include <raylib.h>
#include "../include/constants.h"
#include "../include/scene.h"


int main(int argc, char const *argv[]) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    Image iconImage = LoadImage(ICON_PATH);
    SetWindowIcon(iconImage);

    SceneManager sceneManager;
    while (!WindowShouldClose()) {
        sceneManager.update();        
        sceneManager.draw();        
    }
    UnloadImage(iconImage);
    CloseWindow();
}
