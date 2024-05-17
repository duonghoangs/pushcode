#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "menu.hpp"
#include "renderer.hpp"
#include <SDL2_mixer/SDL_mixer.h>

bool Checkselect(const int& x, const int& y, const SDL_Rect& rect)
{
  if (x >= rect.x && x <= rect.w &&
      y >= rect.y && y <= rect.h)
  {
    return true;
  }
  return false;
}

int showmenu (SDL_Texture *menu, Graphic graphics)
{
    menu = graphics.loadTexture("MENU.png");
    if (menu == NULL) {cerr << "cant load menuimg!!!";}
    const int menubuttom = 2;
    SDL_Rect posarr[menubuttom];
    posarr[0].x = 80;
    posarr[0].y = 310;
    posarr[0].w = 250;
    posarr[0].h = 355;
    
    posarr[1].x = 80;
    posarr[1].y = 390;
    posarr[1].w = 250;
    posarr[1].h = 436;
    SDL_Event mouse;
    
    int mousex = 0;
    int mousey = 0;
    SDL_Texture *selecte = graphics.loadTexture("blueship.png");
    SDL_Rect buttomrect[4];
    buttomrect[0].x = -2;
    buttomrect[0].y = 305;
    buttomrect[0].w = 70;
    buttomrect[0].h = 70;
    
    buttomrect[1].x = 277;
    buttomrect[1].y = 305;
    buttomrect[1].w = 70;
    buttomrect[1].h = 70;
    
    buttomrect[2].x = -2;
    buttomrect[2].y = 375;
    buttomrect[2].w = 70;
    buttomrect[2].h = 70;
    
    buttomrect[3].x = 277;
    buttomrect[3].y = 375;
    buttomrect[3].w = 70;
    buttomrect[3].h = 70;

    int x = 0;
    int sound_flag = 0;
    
    SDL_Rect sound;
    sound.x = 190;
    sound.y = 390;
    sound.w = 660;
    sound.h = 569;
    SDL_Texture *soundt = graphics.loadTexture("on.png");
    while (true)
    {
        graphics.prepareScene(menu);
        SDL_GetMouseState(&mousex, &mousey);
            
            for (int i = 0; i < menubuttom; ++i)
            {
                if (Checkselect(mousex, mousey, posarr[i]))
                {
                    if (i == 0) {x = 1;}
                    else {x = 3;}
                        
                    SDL_RenderCopyEx(graphics.renderer, selecte, NULL, &buttomrect[x - 1], 90, NULL, SDL_FLIP_NONE);
                    SDL_RenderCopyEx(graphics.renderer, selecte, NULL, &buttomrect[x], -90, NULL, SDL_FLIP_NONE);
                }
            }

        while (SDL_PollEvent(&mouse))
        {
            
            switch (mouse.type)
            {
                case SDL_QUIT: 
                {
                    return 1;
                }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                        {
                          mousex = mouse.button.x;
                          mousey = mouse.button.y;

                          
                            if (Checkselect(mousex, mousey, posarr[0]))
                            {
                              return 0;
                            }
                            if (Checkselect(mousex, mousey, posarr[1]))
                            {
                                if (sound_flag == 0) 
                                {
                                    Mix_PauseMusic(); sound_flag = 1;
                                    soundt = graphics.loadTexture("off.png");
                                }
                                else 
                                {
                                    Mix_ResumeMusic(); sound_flag = 0;
                                    soundt = graphics.loadTexture("on.png");
                                }
                            }
                         
                        }
                case SDL_KEYDOWN:
                        if (mouse.key.keysym.sym == SDLK_ESCAPE)
                        {
                          return 1;
                        }
                      default:
                        break;
            }
        }
        SDL_RenderCopy(graphics.renderer, soundt, NULL, &sound);
        graphics.presentscene();
    }
    return 1;
}
