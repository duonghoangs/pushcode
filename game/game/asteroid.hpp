

//asteroids.h
#include "vector.hpp"
#define VERTS 10

enum sizes {SMALL, MEDIUM, LARGE};

struct asteroid {
    int alive;
    enum sizes size;
    float hit_radius;
    float rotation;
    vector2d location;
    vector2d velocity;
    vector2d obj_vert[VERTS];
    vector2d world_vert[VERTS];
};

void init_asteroids( asteroid asteroids[], int size);
void update_asteroids( asteroid asteroids[], int size);
int shrink_asteroid( asteroid* a, int size);
void spawn_asteroids( asteroid a[], int length, int size,  vector2d v);
void bounds_asteroids( asteroid asteroids[], int size);
int collision_asteroids( asteroid asteroids[], int size,  vector2d* v, float radius);
