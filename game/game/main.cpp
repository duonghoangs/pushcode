
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderer.hpp"
#include "player.hpp"
#include "asteroid.hpp"
#include <SDL2_image/SDL_image.h>
#include "menu.hpp"
#include <SDL2_mixer/SDL_mixer.h>
#define ASTEROIDS 27
#define LIVES 3





asteroid asteroids[ASTEROIDS];
player p;
player lives[LIVES];


void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if ( SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
    
int main (int argc, char* args[]) 
{
    Graphic graphics;
    graphics.initSDL();
    SDL_Texture *background = graphics.loadTexture("space.gif");
    graphics.prepareScene(background);

    for (int i = 0; i < LIVES; i++)
    {
        init_player(&lives[i]);
        lives[i].lives = 1;
    }
    
    init_player(&p);
    init_asteroids(asteroids, ASTEROIDS);
    
    int quit = 0;
    //================ load music =======================

    Mix_Music *background_sound = loadMusic("background.mp3");
    play(background_sound);

    Mix_Chunk *bullet_sound = loadSound("fire.wav");
    Mix_Music *death_sound = loadMusic("death.mp3");
    Mix_Chunk *asteroid_sound = loadSound("asteroid.wav");
    
   //================= gmae loop ====================
    
    int độ = 0;
    while(quit == 0) 
    {        
        //================ menu ===========================
        SDL_Texture *menu = NULL;
        int retmenu = showmenu(menu, graphics);
        if (retmenu == 1) {quit = 1;}
        while (quit == 0)
        {
            SDL_PumpEvents();
            
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            
            if (state[SDL_SCANCODE_ESCAPE]) {
                
                quit = 1;
            }
            
            if (state[SDL_SCANCODE_UP]) {
                
                vector2d thrust = get_direction(&p);
                multiply_vector(&thrust, 0.06);
                apply_force(&p.velocity, thrust);
            }
            
            if (state[SDL_SCANCODE_LEFT]) {
                
                rotate_player(&p, -4); độ += -4;
            }
            
            if (state[SDL_SCANCODE_RIGHT]) {
                
                rotate_player(&p, 4); độ += 4;
            }
            if (lives[0].lives > 0)
            {
                shoot_bullet(&p, bullet_sound);
            }
            //        while (SDL_PollEvent(&event)) {
            //
            //            switch(event.type) {
            //
            //                case SDL_KEYDOWN:
            //
            //                    switch( event.key.keysym.sym ) {
            //
            //                        case SDLK_SPACE:
            //
            //                            if (p.lives > 0) {
            //
            //                                shoot_bullet(&p);
            //                            }
            //
            //                            break;
            //                    }
            //            }
            //        }
            
            update_player(&p);
            bounds_player(&p);
            bounds_asteroids(asteroids, ASTEROIDS);
            
            int res = collision_asteroids(asteroids, ASTEROIDS, &p.location, p.hit_radius);
            
            if (res != -1) {
                
                p.lives--;
                p.location.x = 0;
                p.location.y = 0;
                p.velocity.x = 0;
                p.velocity.y = 0;
                
                
                
                for (int i = LIVES; i >= 0; i--) {
                    
                    if(lives[i].lives > 0) {
                        
                        lives[i].lives = 0;
                        
                        break;
                        
                    }
                }
            }
            
            vector2d translation = {-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2};
            
            for (int i = 0; i < BULLETS; i++) {
                
                if (p.bullets[i].alive == TRUE) {
                    
                    vector2d world = add_vector_new(&p.bullets[i].location, &translation);
                    int index = collision_asteroids(asteroids, ASTEROIDS, &world, 1);
                    
                    if (index != -1) {
                        
                        asteroids[index].alive = 0;
                        p.bullets[i].alive = FALSE;
                        play(asteroid_sound);
                        if (asteroids[index].size != SMALL) {
                            spawn_asteroids(asteroids, ASTEROIDS, asteroids[index].size, asteroids[index].location);
                        }
                    }
                }
            }
            
            update_asteroids(asteroids, ASTEROIDS);
            //===========================ship, backgound==================
            SDL_Rect rect;
            rect.x = p.location.x + SCREEN_WIDTH / 2 - rect.w / 2;
            rect.y = p.location.y + SCREEN_HEIGHT / 2 - rect.h / 2;
            rect.w = 70;
            rect.h = 70;
            
            SDL_Texture *ship = graphics.loadTexture("blueship.png");
            graphics.prepareScene();
            if (lives[0].lives == 0)
            {
                ship = NULL;
            }
            SDL_Texture *aster = graphics.loadTexture("asteroid.png");
            if (aster == NULL) {cerr << "vl";}
            SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
            SDL_RenderCopyEx(graphics.renderer, ship, NULL, &rect, độ, NULL, SDL_FLIP_NONE);
            
            //=========================asteroid=================================
            for (int i = 0; i < ASTEROIDS; i++) {
                
                if (asteroids[i].alive) {
                    SDL_Rect rects;
                    
                    if (asteroids[i].size == LARGE)
                    {
                        rects.x = asteroids[i].location.x + SCREEN_WIDTH / 2 - rects.w/2;
                        rects.y = asteroids[i].location.y + SCREEN_HEIGHT / 2 - rects.h/2;
                        rects.w = 70;
                        rects.h = 70;
                    }
                    if (asteroids[i].size == MEDIUM)
                    {
                        rects.x = asteroids[i].location.x + SCREEN_WIDTH / 2 - rects.w/4;
                        rects.y = asteroids[i].location.y + SCREEN_HEIGHT / 2 - rects.h/4;
                        rects.w = 40;
                        rects.h = 40;
                    }
                    if (asteroids[i].size == SMALL)
                    {
                        rects.x = asteroids[i].location.x + SCREEN_WIDTH / 2 - rects.w/14;
                        rects.y = asteroids[i].location.y + SCREEN_HEIGHT / 2 - rects.h/14;
                        rects.w = 20;
                        rects.h = 20;
                    }
                    asteroids[i].rotation += asteroids[i].rotation / abs(asteroids[i].rotation);
                    SDL_RenderCopyEx(graphics.renderer, aster, NULL, &rects, asteroids[i].rotation, NULL, SDL_FLIP_NONE);
                }
            }
            //================bullet=====================================
            SDL_Texture *bullet = graphics.loadTexture("bluebullet.png");
            for (int i = 0; i < BULLETS; i++) {
                
                if (p.bullets[i].alive == TRUE) {
                    SDL_Rect bulle;
                    bulle.x = p.bullets[i].location.x - bulle.w/2;
                    bulle.y = p.bullets[i].location.y - bulle.h/2;
                    bulle.w = 10;
                    bulle.h = 10;
                    SDL_RenderCopy(graphics.renderer, bullet, NULL, &bulle);
                }
                
            }
            //==============liveicon====================================
            int x = 0;
            for (int i = 0; i < LIVES; i++)
            {
                if (lives[i].lives > 0)
                {
                    SDL_Rect liveicon = {20 + x, 20, 35, 35};
                    x += 30;
                    SDL_RenderCopy(graphics.renderer, ship, NULL, &liveicon);
                }
            }
            graphics.presentscene();
            //============== death =====================================
            if (lives[0].lives == 0)
            {
                Mix_PauseMusic();
                Mix_PlayMusic(death_sound, 0);
                SDL_Delay(4000);
                init_player(&p);

                    init_asteroids(asteroids, ASTEROIDS);

                    for (int i = 0; i < LIVES; i++) {
                        lives[i].lives = 1;
                    }
                play(background_sound);
                độ = 0;
                int retmenu = showmenu(menu, graphics);
                if (retmenu == 1) {quit = 1;}
                
            }
        }
    }
    
    
    graphics.quitSDL();
    return 0;
}
    













