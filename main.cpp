#include "SDL.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = NULL;

    window = SDL_CreateWindow("Hello!",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              1280, // width
                              720, // height
                              SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "There was an error initializing the window!" << endl
             << SDL_GetError() << endl;
    }

    // fill screen with white color
    SDL_Surface* screen = SDL_GetWindowSurface(window);
    Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255);
    SDL_FillRect(screen, NULL, blue);
    SDL_UpdateWindowSurface(window);

    // main loop
    SDL_Event event;
    bool running = true;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}


