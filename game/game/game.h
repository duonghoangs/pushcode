
#ifndef game_h
#define game_h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "defs.h"
#include "graphic.h"

#define INITIAL_speed 50;
struct mouse
{
    int x, y;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_speed;
    void move ()
    {
        x += dx;
        y += dy;
    }
    void turnnorth ()
    {
        dy = -speed; dx = 0;
    }
    void turnsouth ()
    {
        dy = speed; dx = 0;
    }
    void turneast ()
    {
        dy = 0; dx = speed;
    }
    void turnwest ()
    {
        dy = 0; dx = -speed;
    }
};


void render (const mouse& mouses, const Graphic& graphics)
{
    SDL_Rect Filled_rect;
    Filled_rect.x = mouses.x;
    Filled_rect.y = mouses.y;
    Filled_rect.w = 10;
    Filled_rect.h = 10;
    
    
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(graphics.renderer, &Filled_rect);    
    SDL_RenderPresent(graphics.renderer);
}

bool gameover (const mouse& mouses)
{
    return mouses.x < 0 or mouses.y < 0 or mouses.y >= SCREEN_HEIGHT or mouses.x >= SCREEN_WIDTH;
}
#endif /* game_h */
