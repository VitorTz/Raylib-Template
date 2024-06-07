#pragma once
#include <raylib.h>
#include <raymath.h>


#define NUM_COMPONENTS 1

typedef struct transform {
    Vector2 pos{};
    Vector2 size{};
    Vector2 direction{};
    Vector2 lastMovement{};
    float rotation = 0.f;
    float speed = 0.f;
} transform_t;

