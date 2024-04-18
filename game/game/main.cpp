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
    Graphic graphics;
    graphics.initSDL();
    
    SDL_Texture* background = graphics.loadTexture("space.gif");
    
    if (background == NULL) cerr << "vl";
    graphics.prepareScene(background);
    bool quit = false;
    mouse mouses;
    mouses.x = SCREEN_WIDTH / 2;
    mouses.y = SCREEN_HEIGHT / 2;
    SDL_Event event;
    while (!quit && !gameover(mouses))
    {
        graphics.prepareScene();
            
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) quit = true;
            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            
            if (currentKeyStates[SDL_SCANCODE_UP] ) {mouses.turnnorth();mouses.move();}
            if (currentKeyStates[SDL_SCANCODE_DOWN] )
            {mouses.turnsouth(); mouses.move();}
            if (currentKeyStates[SDL_SCANCODE_LEFT] )
            {mouses.turnwest(); mouses.move();}
            if (currentKeyStates[SDL_SCANCODE_RIGHT] )
            {mouses.turneast(); mouses.move();}
            
        }
        
        SDL_Rect Filled_rect;
        Filled_rect.x = mouses.x;
        Filled_rect.y = mouses.y;
        Filled_rect.w = 101;
        Filled_rect.h = 101;
        
        SDL_Texture* ship = graphics.loadTexture("ship30.png");
        
        if (ship == NULL) cout << "vl";
       
        SDL_RenderCopy(graphics.renderer, background, NULL, NULL);

        SDL_RenderCopy(graphics.renderer, ship, NULL, &Filled_rect);

        graphics.presentscene();
            SDL_Delay(0);
            
    }
    graphics.quitSDL();
    return 0;
}



   



