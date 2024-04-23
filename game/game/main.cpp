#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "defs.h"
#include "graphic.h"
#include "game.h"

using namespace std;

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



    
int main (int argc, char* argv[])
{
//-----------------background------------------------
    Graphic graphics;
    graphics.initSDL();
    
    SDL_Texture* background = graphics.loadTexture("space.gif");
    
    if (background == NULL) cerr << "vl";
    graphics.prepareScene(background);
//--------------------------------------------------
    

    bool quit = false;
    mouse mouses;
    mouses.x = SCREEN_WIDTH / 2;
    mouses.y = SCREEN_HEIGHT / 2;
    SDL_Event event;
    int phuonghuong = 0;
//-----------------gameloop------------------------
    while (!quit && !gameover(mouses))
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) quit = true;
        }
//--------------move-------------------------------------
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        SDL_Texture* ship = graphics.loadTexture("blueship.png");
        
                
        if (currentKeyStates[SDL_SCANCODE_UP] )
        {
            mouses.turnnorth();
            phuonghuong = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN] )
        {
            mouses.turnsouth();
            phuonghuong = 180;
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT] )
        {
            mouses.turnwest();
            phuonghuong = -90;
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT] )
        {
            mouses.turneast();
            phuonghuong = 90;
        }
        mouses.move();
//----------------------------------------------------------
        
//---------------drawship----------------------------------
        SDL_Rect Filled_rect;
        Filled_rect.x = mouses.x;
        Filled_rect.y = mouses.y;
        Filled_rect.w = 70;
        Filled_rect.h = 70;
        
//        if (ship == NULL) cout << "vl";
        graphics.prepareScene();
        SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
        SDL_RenderCopyEx(graphics.renderer, ship, NULL, &Filled_rect, phuonghuong, NULL, SDL_FLIP_NONE);
        graphics.presentscene();
            SDL_Delay(16);
//---------------------------------------------------------
        SDL_Delay(0);
    }
    graphics.quitSDL();
    return 0;
}



   



