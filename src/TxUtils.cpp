#include <iostream>
#include "TxUtils.h"
#include <SDL2/SDL.h>

SDL_Texture *LoadTexture( SDL_Renderer *renderer , const char *path){
    SDL_Surface *imageSurface = nullptr;
    SDL_Texture *imageTexture = nullptr;

    imageSurface = SDL_LoadBMP(path);
    if( imageSurface == nullptr ){
        throw std::runtime_error("Surface \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    imageTexture = SDL_CreateTextureFromSurface( renderer , imageSurface );
    if(imageTexture == nullptr){
        throw std::runtime_error("Texture \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    SDL_FreeSurface( imageSurface );

    return imageTexture;
}

Element::Element(SDL_Renderer *renderer, const char *path, int PosX, int PosY) {
    texture = LoadTexture(renderer, path);
    if (texture == nullptr){
        throw std::runtime_error("Texture \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    rect.x = PosX;
    rect.y = PosY;
    if (SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h)) {
        throw std::runtime_error("Texture \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    

}

Element::Element(SDL_Renderer *renderer, SDL_Texture *NewTexture, int PosX, int PosY){
    this->texture = NewTexture;
    this->rect.x = PosX;
    this->rect.y = PosY;
    if (SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h)) {
        throw std::runtime_error("Query de texture importe : " + std::string(SDL_GetError()));
    }
}

Element::~Element() {
    SDL_DestroyTexture(texture);
    std::cout << "Element détruit" << std::endl;
}

SDL_Texture* Element::GetTexture() {
    return texture;
}

SDL_Rect* Element::GetRect() {
    return &rect;
}

void Element::resizeRect(int newW, int newH){
    this->rect.w = newW;
    this->rect.h = newH;
}

void Element::changeTx(SDL_Texture* NewTexture){
    this->texture = NewTexture;
    std::cout << "texture : " << NewTexture << std::endl;
    if (SDL_QueryTexture(this->texture, NULL, NULL, &rect.w, &rect.h)) {
        throw std::runtime_error("ChangeTx() : " + std::string(SDL_GetError())); // ! Texture invalide
    }
}

void Element::down(){
    this->rect.y++;
}

void Element::SetPositionXY(int posX, int posY){
    rect.x = posX;
    rect.y = posY;
}

void Element::render(SDL_Renderer *renderer){
    if(SDL_RenderCopy(renderer, texture, NULL, &rect)) {
        throw std::runtime_error("Rendu | " + std::string(SDL_GetError()));
    }
}


BRICS::BRICS(SDL_Renderer *renderer, const char *path, BricType newType, int posX, int posY)
    :   bric(renderer, path, posX, posY),
        type(newType) {
}
BRICS::BRICS(SDL_Renderer *renderer, SDL_Texture *texture, BricType newType, int posX, int posY)
    :   bric(renderer, texture, posX, posY),
        type(newType){
}
BRICS::~BRICS(){
    std::cout << "Brics détuite" << std::endl; 
}

void BRICS::down(){
    bric.down();
}