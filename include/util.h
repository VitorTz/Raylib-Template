#pragma once
#include <raylib.h>
#include <cmath>
#include <random>


extern std::default_random_engine generator;


int randint(int start, int end);

float randFloat(float min, float max);

void normalize_vector(Vector2* v);



