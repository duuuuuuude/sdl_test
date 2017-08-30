#include "SDL.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window;

    window = SDL_CreateWindow("Hello!",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              1440, // width
                              900, // height
                              SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "There was an error initializing the window!" << endl
             << SDL_GetError() << endl;
    }

    // SDL_SetWindowBordered(window, SDL_FALSE);
    // SDL_SetWindowTitle(window, "Kek");

    int x, y, h, w;

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
        SDL_GetWindowPosition(window, &x, &y);

        cout << x << ", " << y << endl;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}


