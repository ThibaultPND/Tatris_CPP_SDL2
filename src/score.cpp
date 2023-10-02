#include "score.h"

score::score(SDL_Renderer* renderer, SDL_Texture** font)
    : nb1(renderer, font[0], 51, 50),
      nb2(renderer, font[0], 55, 50),
      nb3(renderer, font[0], 59, 50),
      nb4(renderer, font[0], 63, 50),
      valeur(0) {
}

score::~score() {
}

void score::render(SDL_Renderer *renderer, SDL_Texture** font) {
    std::string valeurStr = std::to_string(valeur);
    const char *chartex = valeurStr.c_str();

    int i = 0;
    if (valeurStr.length() <= 4){
        if (valeurStr.length() >= 4){
            nb1.changeTx(font[chartex[i++] - '0']  );
        }else{
            nb1.changeTx(font[0]);
        }
        if (valeurStr.length() >= 3){
            nb2.changeTx(font[chartex[i++] - '0']  );
        }else{
            nb2.changeTx(font[0]);
        }
        if (valeurStr.length() >= 2){
            nb3.changeTx(font[chartex[i++] - '0']  );
        }else{
            nb3.changeTx(font[0]);
        }
        if (valeurStr.length() >= 1){
            nb4.changeTx(font[chartex[i++] - '0']  );
        }else{
            nb4.changeTx(font[0]);
        }
    }else{
        this->valeur = 0;
        this->render(renderer, font);
        return;
    }
    

    nb1.render(renderer);
    nb2.render(renderer);
    nb3.render(renderer);
    nb4.render(renderer);
}


int score::getScore(){
    return this->valeur;
};

void score::setScore(int value){
    this->valeur = value;
}
void score::addScore(int value){
    this->valeur += value;
}