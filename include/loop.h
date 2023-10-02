#ifndef __LOOP_h__
    #define __LOOP_h__

    #include "Project.h"
    #include "TxUtils.h"
    #include "font.h"
    #include "score.h"
    #include <cstdlib>
    #include <SDL2/SDL.h>

    int loopMenu(SDL_Renderer *renderer);
    int loopJeu(SDL_Renderer *renderer);

    bool CanGoDown(bool tabJeu[26][15] );// TODO fonction

#endif // __LOOP_h__