//
//  graphic.h
//  game
//
//  Created by Thái Dương on 14/04/2024.
//

#ifndef graphic_h
#define graphic_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "defs.h"

struct Graphic
{
    SDL_Renderer* renderer;
    SDL_Window* window;
    
    
    void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }
      
    void logSDLError(std::ostream& os,
     const std::string &msg, bool fatal)
    {
     os << msg << " Error: " << SDL_GetError() << std::endl;
     if (fatal) {
     SDL_Quit();
     exit(1);
     }
    }

    SDL_Window* initSDL()
    {
         if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
         {logSDLError(std::cout, "SDL_Init", true);}
        
        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
         SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == nullptr) {logSDLError(std::cout, "CreateWindow", true);}
        
         renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
         SDL_RENDERER_PRESENTVSYNC);

         if (renderer == nullptr)
         {
             logSDLError(std::cout, "CreateRenderer", true);
             SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
             SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
         }
        
        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        SDL_ShowCursor(0);
        return window;
    }


    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                         "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Load texture %s", IMG_GetError());
          }

        return texture;
    }



    void quitSDL()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        IMG_Quit();
    }
    
    void renderTexture(SDL_Texture *texture, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void prepareScene (SDL_Texture* background)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        
    }
    
    void presentscene ()
    {
        SDL_RenderPresent(renderer);
    }


};
#endif /* graphic_h */
