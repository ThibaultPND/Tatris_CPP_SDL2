#include "font.h"

SDL_Texture** InitFont(SDL_Renderer *renderer) {
    SDL_Texture **texture = new SDL_Texture*[10] {
        LoadTexture(renderer, "data/img/RETRO_FONT/0.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/1.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/2.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/3.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/4.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/5.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/6.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/7.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/8.bmp"),
        LoadTexture(renderer, "data/img/RETRO_FONT/9.bmp")
    };

    return texture;
}