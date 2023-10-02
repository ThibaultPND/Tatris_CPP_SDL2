#ifndef __SCORE_H__
#define __SCORE_H__

#include "iostream"
#include "TxUtils.h"
#include "SDL2/SDL.h"

class score {
    private:
        Element nb1;
        Element nb2;
        Element nb3;
        Element nb4;
        int valeur;
    public:
    score(SDL_Renderer* renderer, SDL_Texture** font);
    ~score();

    void render(SDL_Renderer *renderer, SDL_Texture** font);

    int getScore();
    void setScore(int value);
    void addScore(int value);
};



#endif // __SCORE_H__