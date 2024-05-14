
#include <math.h>
#include "defs.h"
#include "vector.h"
#include "graphic.h"
#ifndef asteroid_h
#define asteroid_h
#define VERT 10


enum size {SMALL, MEDIUM, LARGE};


struct asteroid
{
    int alive;
    enum size sizes;
    double hit_box;
    double quay;
    Vector location;
    Vector velocity;
    Vector obj_vert[VERT];
    Vector world_vert[VERT];
};
void init_asteroid (asteroid asteroids[], int sizes)
{
    int i = 0;
    int j = 0;
    Vector huongtam = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    for (i = 0; i < VERT; ++i)
    {
        int ranx = rand() % 100;
        int rany = rand() % 100;
        int ly = rand() % SCREEN_WIDTH/2;
        int lx = rand() % SCREEN_HEIGHT/2;
        double vx = (float) (rand() % 500) / 1000;
        double vy = (float) (rand() % 500) / 1000;
        double độ =  (float) (rand() %  100 + 1000) / 1000;
                
                //50% chance the sign of the variable will be switched to negative
                if (ranx >= 50)
                {
                    vx = -vx;
                    lx = -lx;
                    độ = -độ;
                }
                
                //50% chance the sign of the variable will be switched to negative
                if (rany >= 50)
                {
                    vy = -vy;
                    ly = -ly;
                }
            
                //firest 3 asteroids are alive
                if (i <  3) 
                {
                    asteroids[i].alive = 1;
                
                } 
                else
                {
                    asteroids[i].alive = 0;
                }

                asteroids[i].sizes = LARGE;
                asteroids[i].hit_box = 35;
                asteroids[i].quay = độ;
                asteroids[i].location.x = lx;
                asteroids[i].location.y = ly;
                asteroids[i].velocity.x = vx;
                asteroids[i].velocity.y = vy;
                asteroids[i].obj_vert[0].x = .0;
                asteroids[i].obj_vert[0].y = .4;
                asteroids[i].obj_vert[1].x = .2;
                asteroids[i].obj_vert[1].y = .3;
                asteroids[i].obj_vert[2].x = .2;
                asteroids[i].obj_vert[2].y = .1;
                asteroids[i].obj_vert[3].x = .4;
                asteroids[i].obj_vert[3].y = .0;
                asteroids[i].obj_vert[4].x = .3;
                asteroids[i].obj_vert[4].y = -.2;
                asteroids[i].obj_vert[5].x = .1;
                asteroids[i].obj_vert[5].y = -.2;
                asteroids[i].obj_vert[6].x = .0;
                asteroids[i].obj_vert[6].y = -.3;
                asteroids[i].obj_vert[7].x = -.2;
                asteroids[i].obj_vert[7].y = -.2;
                asteroids[i].obj_vert[8].x = -.4;
                asteroids[i].obj_vert[8].y = 0;
                asteroids[i].obj_vert[9].x = -.3;
                asteroids[i].obj_vert[9].y = .3;
                
        for (j = 0; j < VERT; j++)
        {
            nhan_vector(&asteroids[i].obj_vert[j], 88);  // co dãn thiên thạch
            cong_vector(&asteroids[i].world_vert[j],  &asteroids[i].obj_vert[j]); //
            cong_vector(&asteroids[i].world_vert[j], &huongtam);
        }
    }
}
void update_asteroid(asteroid asteroids[], int sizes)
{
    int i = 0;
    int j = 0;
    Vector huongtam = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    for (i = 0; i < sizes; i++)
    {
        //updates each asteroids location based off its velicity vector
        cong_vector(&asteroids[i].location, &asteroids[i].velocity);
        
        //update each vert of the asteroid to reflect the changes made to the asteroids location vector
        //and rotation amount, then translate the new vert location to screen space
        for (j = 0; j < VERT; j++) {
                
            asteroids[i].world_vert[j] = cong_vector_moi(&asteroids[i].obj_vert[j], &asteroids[i].location);
            cong_vector(&asteroids[i].world_vert[j], &huongtam);
            quay_vector(&asteroids[i].obj_vert[j], asteroids[i].quay);
        }
    }
}

void draw_asteroid(uint32_t* pixel_buffer, struct asteroid asteroids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (asteroids[i].alive)
        {
            
            draw_line(pixel_buffer, asteroids[i].world_vert[0].x, asteroids[i].world_vert[0].y, asteroids[i].world_vert[1].x, asteroids[i].world_vert[1].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[1].x, asteroids[i].world_vert[1].y, asteroids[i].world_vert[2].x, asteroids[i].world_vert[2].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[2].x, asteroids[i].world_vert[2].y, asteroids[i].world_vert[3].x, asteroids[i].world_vert[3].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[3].x, asteroids[i].world_vert[3].y, asteroids[i].world_vert[4].x, asteroids[i].world_vert[4].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[4].x, asteroids[i].world_vert[4].y, asteroids[i].world_vert[5].x, asteroids[i].world_vert[5].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[5].x, asteroids[i].world_vert[5].y, asteroids[i].world_vert[6].x, asteroids[i].world_vert[6].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[6].x, asteroids[i].world_vert[6].y, asteroids[i].world_vert[7].x, asteroids[i].world_vert[7].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[7].x, asteroids[i].world_vert[7].y, asteroids[i].world_vert[8].x, asteroids[i].world_vert[8].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[8].x, asteroids[i].world_vert[8].y, asteroids[i].world_vert[9].x, asteroids[i].world_vert[9].y, 0xffffffff);
            draw_line(pixel_buffer, asteroids[i].world_vert[9].x, asteroids[i].world_vert[9].y, asteroids[i].world_vert[0].x, asteroids[i].world_vert[0].y, 0xffffffff);
        }
    }
}

int shrink_asteroid(asteroid* a, int sizes) {

    a->obj_vert[0].x = .0;
    a->obj_vert[0].y = .4;
    a->obj_vert[1].x = .2;
    a->obj_vert[1].y = .3;
    a->obj_vert[2].x = .2;
    a->obj_vert[2].y = .1;
    a->obj_vert[3].x = .4;
    a->obj_vert[3].y = .0;
    a->obj_vert[4].x = .3;
    a->obj_vert[4].y = -.2;
    a->obj_vert[5].x = .1;
    a->obj_vert[5].y = -.2;
    a->obj_vert[6].x = .0;
    a->obj_vert[6].y = -.3;
    a->obj_vert[7].x = -.2;
    a->obj_vert[7].y = -.2;
    a->obj_vert[8].x = -.4;
    a->obj_vert[8].y = 0;
    a->obj_vert[9].x = -.3;
    a->obj_vert[9].y = .3;
    
    

    for (int i = 0; i < VERT; i++) {
        
        nhan_vector(&a->obj_vert[i], 88);
    }

    if (sizes == LARGE) {
            
        for (int i = 0; i < VERT; i++) {
        
            chia_vector(&a->obj_vert[i], 2);
        }
        
        a->sizes = MEDIUM;
        
        return 0;
    }
    
    if (sizes == MEDIUM) {
        
        //shrink asteroid
        for (int i = 0; i < VERT; i++) {
        
            chia_vector(&a->obj_vert[i], 4);
        }
        
        a->sizes = SMALL;
        
        return 0;
    }
    
    if (sizes == SMALL) {
        
        //shrink asteroid
        for (int i = 0; i < VERT; i++) {
        
            chia_vector(&a->obj_vert[i], 8);
        }

        return 0;
    }

    return 1;
}

void tao_asteroids(asteroid a[], int length, int size, Vector v)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if(a[i].alive == 0)
        {
            if (count == 3)
            {
                break;
            }
            a[i].location = v;
            a[i].hit_box /= 2;
            a[i].alive = 1;
            count++;
            shrink_asteroid(&a[i], size);
        }
    }
}


void bound_asteroid(asteroid asteroids[], int sizes) 
{
    for (int i = 0 ; i < sizes; i++) {
        
        if (asteroids[i].location.x < -SCREEN_WIDTH / 2) {
            
            asteroids[i].location.x = SCREEN_WIDTH / 2;
        }
    
        if (asteroids[i].location.x > SCREEN_WIDTH / 2) {
            
            asteroids[i].location.x = -SCREEN_WIDTH / 2;
        }
        
        if (asteroids[i].location.y < -SCREEN_HEIGHT / 2) {
            
            asteroids[i].location.y = SCREEN_HEIGHT / 2;
        }
    
        if (asteroids[i].location.y > SCREEN_HEIGHT / 2) {
            
            asteroids[i].location.y = -SCREEN_HEIGHT / 2;
        }
    }
}

int hit_asteroid(asteroid asteroids[], int sizes, Vector* v, double r)
{
    for (int i = 0; i < sizes; i++)
    {
        //only check for collions for asteroids that are shown onscreen
        if (asteroids[i].alive == 1) 
        {
            double s = asteroids[i].hit_box + r;
            double a = pow(asteroids[i].location.x - v->x, 2);
            double b = pow(asteroids[i].location.y - v->y, 2);
            double distance = sqrt(a + b);
            
            if (distance < s)
            {
                return i;
            }
        }
    }

    return -1;
}

#endif /* asteroid_h */
