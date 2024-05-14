
#ifndef graphic_h
#define graphic_h

#include <math.h>
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
    
    void prepareScene ()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
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

int draw_pixel(uint32_t* pixel_buffer, int x, int y, uint32_t colour) {
    
//    ** ghép vào một if
    //dont draw any pixels that are outside of the pixel buffer
    if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0) 
    {
        return 1;
    }

    uint32_t position = y * SCREEN_WIDTH + x;
    pixel_buffer[position] = colour;

    return 0;
}

void clear_pixels(uint32_t* pixel_buffer, uint32_t colour)
{
    int buffer_size = SCREEN_WIDTH * SCREEN_HEIGHT;
    for (int i = 0; i < buffer_size; i++)
    {
        pixel_buffer[i] = colour;
    }
}

int draw_line(uint32_t* pixel_buffer, int x1, int y1, int x2, int y2, uint32_t colour)
{
    
    
    //plot the first point
    draw_pixel(pixel_buffer, x1, y1, colour);
    
    //make sure we draw the line always from left to right
    if (x1 > x2) {
        
        int temp_x = x1;
        int temp_y = y1;
        
        x1 = x2;
        y1 = y2;
        
        x2 = temp_x;
        y2 = temp_y;
    }
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    //the length of the line is greater along the X axis
    if (dx >= fabs(dy)) {
        
        double slope = (double) dy / dx;
        
        //line travels from top to bottom
        if (y1 <= y2) {
            
            double ideal_y = y1 + slope;
            int y = (int) round(ideal_y);
            double error = ideal_y - y;
            //loop through all the X values
            for(int i = 1; i <= dx; i++) {
                int x = x1 + i;
                draw_pixel(pixel_buffer, x, y, colour);
                error += slope;
                if (error  >= 0.5) 
                {
                    y++;
                    error -= 1;
                }
            }
        }
        
        //line travels from bottom to top
        if (y1 > y2) 
        {
            float ideal_y = y1 + slope;
            int y = (int) round(ideal_y);
            float error = ideal_y - y;
            //loop through all the x values
            for(int i = 1; i <= dx; i++) {
                int x = x1 + i;
                draw_pixel(pixel_buffer, x, y, colour);
                error += slope;
                if (error  <= -0.5) 
                {
                    y--;
                    error += 1;
                }
            }
        }
        
        
    }
    
    //the length of the line is greater along the Y axis
    if (fabs(dy) > dx) 
    {
        double slope = (double) dx / dy;
        //line travels from top to bottom
        if (y1 < y2)
        {
            double ideal_x = x1 + slope;
            int x = (int) round(ideal_x);
            double error = ideal_x - x;
            int i = 0;
            //loop through all the y values
            for(i = 1; i <= dy; i++)
            {
                int y = y1 + i;
                draw_pixel(pixel_buffer, x, y, colour);
                error += slope;
                if (error  >= 0.5)
                {
                    x++;
                    error -= 1;
                }
            }
        }
        
        //draw line from bottom to top
        if (y1 > y2) 
        {
            double ideal_x = x1 - slope;
            int x = (int) round(ideal_x);
            double error = ideal_x - x;
            //loop through all the y values
            for(int i = 1; i <= fabs(dy); i++)
            {
                int y = y1 - i;
                draw_pixel(pixel_buffer, x, y, colour);
                error += slope;
                if (error  <= -0.5)
                {
                    x++;
                    error += 1;
                }
            }
        }
    }
    
    return 0;
}
    

#endif /* graphic_h */
