

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>

static SDL_Texture *menu = NULL;

int showmenu (SDL_Texture *menu ,struct Graphic graphics);
bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect);
#endif /* menu_hpp */
