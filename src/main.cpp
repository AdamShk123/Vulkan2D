#include "../include/main.hpp"

SDL_Window *window;

int main(int argc, char **argv)
{
    fmt::println("Hello, World!");

    init();

    run();

    close();

    return 0;
}

void init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::string error = SDL_GetError();
        throw std::runtime_error(error.c_str());
    }

    SDL_WindowFlags flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
    window = SDL_CreateWindow("Vulkan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1200, flags);

    if(!window) {
        std::string error = SDL_GetError();
        throw std::runtime_error(error.c_str());
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void run() {
    SDL_Event e;
    bool quit = false;

    while(!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
            else if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                }
            }
        }
    }
}

void close() {
    IMG_Quit();

    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}
