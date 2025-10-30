// Compile with:
// clang bitmap_sdl.c -o bitmap_sdl -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2
// (adjust include/library paths depending on your SDL2 installation)

// Or if SDL2 is installed via Homebrew:
// clang bitmap_sdl.c -o bitmap_sdl `sdl2-config --cflags --libs`
// clang sdl_test.c -o sdl_test `pkg-config --libs --cflags sdl2`

// #include <SDL2/SDL.h>
#include "/opt/homebrew/include/SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    (void)argc; (void)argv;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    int width = 512, height = 512;
    SDL_Window *window = SDL_CreateWindow(
        "Bitmap Buffer Window (SDL2)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create a bitmap buffer (RGBA)
    unsigned char *pixels = malloc(width * height * 4);
    if (!pixels) {
        fprintf(stderr, "Failed to allocate pixel buffer\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Fill with a simple gradient
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width + x) * 4;
            pixels[i + 0] = (Uint8)x;        // Red
            pixels[i + 1] = (Uint8)y;        // Green
            pixels[i + 2] = (Uint8)(255 - x); // Blue
            pixels[i + 3] = 255;              // Alpha
        }
    }

    SDL_Texture *texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING,
        width, height
    );
    if (!texture) {
        fprintf(stderr, "SDL_CreateTexture Error: %s\n", SDL_GetError());
        free(pixels);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Copy pixel data to texture
    SDL_UpdateTexture(texture, NULL, pixels, width * 4);

    // Main loop
    SDL_bool running = SDL_TRUE;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = SDL_FALSE;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                running = SDL_FALSE;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    free(pixels);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

