
//player.c

#include <stdio.h>
#include "renderer.hpp"
#include "player.hpp"
#include "vector.hpp"
#include <SDL2_mixer/SDL_mixer.h>
void init_player( player* p) {
    
    
     vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    
    p->hit_radius = 15;
    p->lives = 3;
    p->location.x = 0;
    p->location.y = 0;
    p->velocity.x = 0;
    p->velocity.y = 0;
    p->obj_vert[0].x = 0;
    p->obj_vert[0].y = 1.5;
    p->obj_vert[1].x = -1;
    p->obj_vert[1].y = -1;
    p->obj_vert[2].x = 1;
    p->obj_vert[2].y = -1;

    for(int i = 0; i < P_VERTS; i++) {

        multiply_vector(&p->obj_vert[i], -1);
        multiply_vector(&p->obj_vert[i], 12);
        add_vector(&p->world_vert[i], &p->obj_vert[i]);
        add_vector(&p->world_vert[i], &translation);
    }
    
    for(int i = 0; i < BULLETS; i++) {
        
        p->bullets[i].alive = FALSE;
    }
}

void apply_force( vector2d* velocity,  vector2d v) {

    add_vector(velocity, &v);
}

 vector2d get_direction( player* p) {

    vector2d direction = p->obj_vert[0];
    normalise_vector(&direction);

    return direction;
}

void shoot_bullet( player* p, Mix_Chunk *bullet_sound) {

    for (int i = 0; i < BULLETS; i++) {
        
        if (p->bullets[i].alive == FALSE) {
            
            p->bullets[i].alive = TRUE;
            p->bullets[i].location = p->world_vert[0];
            p->bullets[i].velocity = get_direction(p);
            multiply_vector(&p->bullets[i].velocity, 4);
            play(bullet_sound);
            break;
        }
    }
}

void update_player( player* p) {
    
    limit_vector(&p->velocity, 2);
    add_vector(&p->location, &p->velocity);
    
    vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    for (int i =0; i < P_VERTS; i++) {
        
        p->world_vert[i] = add_vector_new(&p->obj_vert[i], &p->location);
        add_vector(&p->world_vert[i], &translation);
    }
    
    for (int i = 0; i < BULLETS; i++) {
        
        add_vector(&p->bullets[i].location, &p->bullets[i].velocity);
    }
}

void rotate_player( player* p, float degrees) {
    
  

    for (int i =0; i < P_VERTS; i++) {
    
        rotate_vector(&p->obj_vert[i], degrees);
    }
}

void bounds_player( player* p) {
    
   
    
    if (p->location.x < -SCREEN_WIDTH / 2) {
        
        p->location.x = SCREEN_WIDTH / 2;
    }
    
    if (p->location.x > SCREEN_WIDTH / 2) {
        
        p->location.x = -SCREEN_WIDTH / 2;
    }

    if (p->location.y < -SCREEN_HEIGHT / 2) {
        
        p->location.y = SCREEN_HEIGHT / 2;
    }
    
    if (p->location.y > SCREEN_HEIGHT / 2) {
        
        p->location.y = -SCREEN_HEIGHT / 2;
    }

    //reset bullet
    
    for (int i = 0; i < BULLETS; i++) {
        
        if (p->bullets[i].location.x < 0 || p->bullets[i].location.x >= SCREEN_WIDTH) {
            
            p->bullets[i].alive = FALSE;
        }
        
        if (p->bullets[i].location.y < 0 || p->bullets[i].location.y >= SCREEN_HEIGHT) {
            
            p->bullets[i].alive = FALSE;
        }
    }
}

