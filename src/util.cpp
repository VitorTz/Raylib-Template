#include "../include/util.h"

std::default_random_engine generator;

int randint(const int start, const int end) {
    std::uniform_int_distribution<int> d(start, end-1);
    return d(generator);
}


float randFloat(const float start, const float end) {
    std::uniform_real_distribution<float> d(start, end);
    return d(generator);
}


void normalize_vector(Vector2* v) {
    const float m = std::sqrt(v->x * v->x + v->y * v->y);
    if (m > 1) {
        v->x /= m;
        v->y /= m;
    }
}