#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "defs.h"
#include "graphic.h"

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

        SDL_Event event;
        while (true) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_KEYDOWN:
                        cerr << "\nDown: " << event.key.keysym.scancode;
                        break;
                    case SDL_KEYUP:
                        cerr << "\nUp: " << event.key.keysym.scancode;
                        break;
                    default: cerr << "\n.";
                }
            }
            SDL_Delay(100);
        }

        graphics.quitSDL();
        return 0;
    }



   



