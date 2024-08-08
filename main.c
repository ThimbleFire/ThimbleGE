//https://github.com/aminosbh/sdl2-samples-and-projects?tab=readme-ov-file

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

static bool Init() {
 

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("My SDL Window", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_OPENGL
    );
 
    if(window == nullptr) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

int main() {

    if (Init() == false) { Shutdown(); }

    SDL_Event e;
    bool running = true;
    
    while(running) {

        ClearScreen(renderer);

        // handle logic
        if(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_KEYDOWN:
                    running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                    break;
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }

        SDL_RenderPresent(renderer);
    }    

    Shutdown();
    return EXIT_SUCCESS;
}

void Shutdown() {

    if(window != nullptr) {
        
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    if(renderer != nullptr) {
        
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    SDL_QUIT();
}

static void ClearScreen(SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, Colors::BLACK.r, Colors::BLACK.g, Colors::BLACK.b, Colors::BLACK.a);
    SDL_RenderClear(renderer);
}

