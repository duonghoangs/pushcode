
#include "vector.h"
#include "defs.h"
#include "graphic.h"
#define P_VERT 3
#define nbullet 3
    
enum boolean {TRUE, FALSE};

struct bullet 
{
    Vector l;
    Vector v;
    boolean alive;
};

struct ship {

    double hit_box;
    int live;
    Vector l;
    Vector v;
    Vector obj_vert[P_VERT];
    Vector world_vert[P_VERT];
    bullet bullets[nbullet];
};

void init_ship(ship* ships)
{
       Vector huong = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    ships->hit_box = 15;
    ships->live = 3;
    ships->l.x = 0;
    ships->l.y = 0;
    ships->v.x = 0;
    ships->v.y = 0;
    ships->obj_vert[0].x = 0;
    ships->obj_vert[0].y = 1.5;
    ships->obj_vert[1].x = -1;
    ships->obj_vert[1].y = -1;
    ships->obj_vert[2].x = 1;
    ships->obj_vert[2].y = -1;

       //convert player verts from object space to world space
       for(int i = 0; i < P_VERT; i++) 
       {
           nhan_vector(&ships->obj_vert[i], -1);
           nhan_vector(&ships->obj_vert[i], 12);
           cong_vector(&ships->world_vert[i], &ships->obj_vert[i]);
           cong_vector(&ships->world_vert[i], &huong);
       }
       
       for(int i = 0; i < nbullet; i++) 
       {
           ships->bullets[i].alive = FALSE;
       }
}

void draw_ship(uint32_t* pixel_buffer, ship* ships)
{
    if (ships->live > 0)
    {
        draw_line(pixel_buffer, ships->world_vert[0].x,ships->world_vert[0].y, ships->world_vert[1].x, ships->world_vert[1].y, 0xffffffff);
        draw_line(pixel_buffer, ships->world_vert[1].x, ships->world_vert[1].y, ships->world_vert[2].x, ships->world_vert[2].y, 0xffffffff);
        draw_line(pixel_buffer, ships->world_vert[2].x, ships->world_vert[2].y, ships->world_vert[0].x, ships->world_vert[0].y, 0xffffffff);
    }
    
    /*
     //draw vers representing the player
     for (i = 0; i < P_VERTS; i++) {
     
     draw_pixel(pixel_buffer, p->world_vert[i].x, p->world_vert[i].y, 0xff00ffff);
     }
     */
    
    //draw verts representing the bullets
    for (int i = 0; i < nbullet; i++) {
        
        if (ships->bullets[i].alive == TRUE) {
            
            draw_pixel(pixel_buffer, ships->bullets[i].l.x, ships->bullets[i].l.y, 0xffffffff);
        }
    }
    
    /*
     //draw vert representing ships location
     struct vector2d cpy = {p->location.x, p->location.y};
     struct vector2d translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
     add_vector(&cpy, &translation);
     
     draw_pixel(pixel_buffer, cpy.x, cpy.y, 0x00ff00ff);
     */
}

void apply_force(Vector* velocity, Vector v) 
{
    cong_vector(velocity, &v);
}

Vector get_direction(ship* ships)
{
    Vector direction = ships->obj_vert[0];
    chuanhoa_vector(&direction);
    return direction;
}

void shoot_bullet(ship* ships)
{
    for (int i = 0; i < nbullet; i++) 
    {
        if (ships->bullets[i].alive == FALSE) 
        {
            ships->bullets[i].alive = TRUE;
            ships->bullets[i].l = ships->world_vert[0];
            ships->bullets[i].v = get_direction(ships);
            nhan_vector(&ships->bullets[i].v, 3);
            break;
        }
    }
}

void update_ship(ship* ships) {
    
    limitvector(&ships->v, 5);
    cong_vector(&ships->l, &ships->v);
    
    Vector translation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    for (int i =0; i < P_VERT; i++) 
    {
        ships->world_vert[i] = cong_vector_moi(&ships->obj_vert[i], &ships->l);
        cong_vector(&ships->world_vert[i], &translation);
    }
    
    for (int i = 0; i < nbullet; i++) 
    {
        cong_vector(&ships->bullets[i].l, &ships->bullets[i].v);
    }
}

void rotate_ship(ship* ships, double degrees)
{
    for (int i =0; i < P_VERT; i++)
    {
        quay_vector(&ships->obj_vert[i], degrees);
    }
}

void bounds_ship(ship* ships)
{
    if (ships->l.x < -SCREEN_WIDTH / 2) 
    {
        ships->l.x = SCREEN_WIDTH / 2;
    }
    if (ships->l.x > SCREEN_WIDTH / 2) 
    {
        ships->l.x = -SCREEN_WIDTH / 2;
    }
    if (ships->l.y < -SCREEN_HEIGHT / 2)
    {
        ships->l.y = SCREEN_HEIGHT / 2;
    }
    if (ships->l.y > SCREEN_HEIGHT / 2) 
    {
        ships->l.y = -SCREEN_HEIGHT / 2;
    }

    //bullet is out of bounds, reset bullet to be shot again
    //bullets are in world space
    for (int i = 0; i < nbullet; i++) 
    {
        if (ships->bullets[i].l.x < 0 || ships->bullets[i].l.x >= SCREEN_WIDTH) 
        {
            ships->bullets[i].alive = FALSE;
        }
        if (ships->bullets[i].l.y < 0 || ships->bullets[i].l.y >= SCREEN_HEIGHT) 
        {
            ships->bullets[i].alive = FALSE;
        }
    }
}
