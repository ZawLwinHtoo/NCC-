//
// Created by zl_shit_h on 08/08/23.
//


#include <SDL2/SDL.h>

int main() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create the game window
    SDL_Window* window = SDL_CreateWindow("SDL Snake Game", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game loop
    bool quit = false;
    while (!quit) {
        // Event handling
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the border
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect borderRect = { 10, 10, 780, 580 };
        SDL_RenderDrawRect(renderer, &borderRect);

        // Draw the snake and other game elements here

        // Update the window
        SDL_RenderPresent(renderer);
    }

    // Clean up and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
