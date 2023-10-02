#ifndef __TXUTILS_H__
    #define __TXUTILS_H__

    #include "SDL2/SDL.h"

    class Element
    {
    private:
        SDL_Texture *texture = nullptr;
        SDL_Rect rect;
    public:
        Element(SDL_Renderer *renderer, const char *path, int PosX = 0, int PosY = 0);
        Element(SDL_Renderer *renderer, SDL_Texture *texture, int PosX = 0, int PosY = 0);
        ~Element();

        SDL_Texture* GetTexture();
        SDL_Rect* GetRect();
    
        void down();
        void resizeRect(int w, int h);
        void changeTx(SDL_Texture* texture);
        void render(SDL_Renderer *renderer);
        void SetPositionXY(int posX, int posY);
    };

    enum BricType { bloc1, line, LLeft, LRight, S1, S2, square};

    class BRICS
    {
    private:
        BricType type;
    public:
        Element bric;
        
        BRICS(SDL_Renderer *renderer, const char *path, BricType newType, int posX = 0, int posY = 0);
        BRICS(SDL_Renderer *renderer, SDL_Texture *texture, BricType newType, int posX = 0, int posY = 0);
        ~BRICS();

        void down();
    };
    

    SDL_Texture *LoadTexture ( SDL_Renderer *renderer , const char *path );
    SDL_Texture *LoadingTextureAndRect ( SDL_Renderer *renderer , const char *path, SDL_Rect &rect, Uint16 x = 0, Uint16 y = 0 );
#endif // __TXUTILS__H_