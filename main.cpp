#include "SDL.h"
#include <iostream>

#define window_width 400
#define window_height 200

#define fps 60

using namespace std;

int limit_framerate(Uint32 starting_tick) {
    cout<<"hellooo"<< endl;
    // if (ideal deltatime - time the frame is running)
    if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
        // delay for diff between ideal deltatime and the time the frame is running
        SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
    }
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = NULL;

    window = SDL_CreateWindow("Hello!",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              window_width, // width
                              window_height, // height
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
    Uint32 starting_tick;
    SDL_Event event;
    bool running = true;
    
    while (running) {
        starting_tick = SDL_GetTicks(); // num of milliseconds since program started
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
 
        limit_framerate(starting_tick);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}


