#pragma once
#include <raylib.h>
#include <raymath.h>


#define NUM_COMPONENTS 3

typedef struct transform {
    Vector2 pos{};
    Vector2 size{};
    Vector2 direction{};
    Vector2 lastMovement{};
    float rotation = 0.f;
    float speed = 0.f;
} transform_t;


typedef struct sprite {
    Texture2D texture;
} sprite_t;


typedef struct circle {
    float radius;
    Color color;
} circle_t;