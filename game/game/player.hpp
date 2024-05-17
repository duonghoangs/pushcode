
//player.h

#include "vector.hpp"

#define P_VERTS 3
#define BULLETS 3
    
enum boolean {TRUE, FALSE};

struct bullet {
    
    vector2d location;
    vector2d velocity;
    enum boolean alive;
};

struct player {

    float hit_radius;
    int lives;
    vector2d location;
    vector2d velocity;
    vector2d obj_vert[P_VERTS];
    vector2d world_vert[P_VERTS];
    bullet bullets[BULLETS];
};

void init_player( player* p);

void draw_player(uint32_t* pixel_buffer, struct player* p);

void shoot_bullet( player* p, Mix_Chunk *bullet_sound);

void update_player( player* p);

void bounds_player( player* p);

void apply_force( vector2d* velocity,  vector2d v);

void rotate_player( player* p, float degrees);

struct vector2d get_direction( player* p);
