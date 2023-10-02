#include "loop.h"

int loopMenu(SDL_Renderer *renderer) {
    
    SDL_RenderClear(renderer);
    Element menu(renderer, "data/img/PLAN_MENU.bmp");
    Element PressEnter(renderer, "data/img/press_enter.bmp", 15, 44);
    menu.render(renderer);
    PressEnter.render(renderer);
    SDL_RenderPresent(renderer);
    Uint32 lastBlinked = SDL_GetTicks();
    Uint32 currentTime = SDL_GetTicks();

    bool visible = true;
    bool enterPressed = false;
    SDL_Event event;
    while (!enterPressed) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 1; // Quitter le programme.
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                enterPressed = true;
            }
        }
        currentTime = SDL_GetTicks();
        if ((currentTime - lastBlinked) > 800 ) {
            lastBlinked = SDL_GetTicks();
            visible = !visible;
            menu.render(renderer);
            if (visible) {
                PressEnter.render(renderer);
            }
            SDL_RenderPresent(renderer);
        }
        
        std::cout << "O";
        SDL_Delay(200);
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

int loopJeu(SDL_Renderer *renderer) {
    srand(SDL_GetTicks());
    SDL_Texture **font = InitFont(renderer);

    Element jeu(renderer, "data/img/PLAN_JEU.bmp");
    score score(renderer, font);

    SDL_Texture *brics[7] = {
        LoadTexture(renderer,"data/img/BRICS/bloc1.bmp"),   // 0
        LoadTexture(renderer,"data/img/BRICS/line.bmp"),    // 1
        LoadTexture(renderer,"data/img/BRICS/LLeft.bmp"),   // 2
        LoadTexture(renderer,"data/img/BRICS/LRight.bmp"),  // 3
        LoadTexture(renderer,"data/img/BRICS/S1.bmp"),      // 4
        LoadTexture(renderer,"data/img/BRICS/S2.bmp"),      // 5
        LoadTexture(renderer,"data/img/BRICS/square.bmp")   // 6
    };

    int previewVal = rand() % 7;
    BRICS preview(renderer, brics[previewVal], 53, 28);
    preview.bric.resizeRect(preview.GetRect()->w*3, preview.GetRect()->h*3);
    preview.bric.render(renderer);

    Element compteur[4] = {
        Element(renderer, "data/img/RETRO_FONT/0.bmp",22,50),
        Element(renderer, "data/img/RETRO_FONT/1.bmp",22,50),
        Element(renderer, "data/img/RETRO_FONT/2.bmp",22,50),
        Element(renderer, "data/img/RETRO_FONT/3.bmp",22,50)
    };
    for (int i = 3; i >= 0; --i) {
        compteur[i].resizeRect(6,10);
        jeu.render(renderer);
        score.render(renderer, font);
        preview.bric.render(renderer);
        compteur[i].render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(600);
    }
    for (int i = 0; i < 3; i++){
        compteur->~Element();
    }

    jeu.render(renderer);
    score.render(renderer, font);
    
    Uint8 FallingVal = previewVal;
    Element falling(renderer, brics[FallingVal], 22, 22);
    falling.resizeRect(falling.GetRect()->w*3, falling.GetRect()->h*3);
    falling.render(renderer);

    SDL_RenderPresent(renderer);

    Uint32 LastFall = SDL_GetTicks();
    Uint32 currentTimer = SDL_GetTicks();

    bool tabJeu[26][15];

    bool isFalling = true;
    bool JeuLooped = true;
    SDL_Event event;
    while (JeuLooped) {
        if (isFalling){
            currentTimer = SDL_GetTicks();
            if ((currentTimer-LastFall) > 100) {
                falling.down();
                jeu.render(renderer);
                preview.bric.render(renderer);
                falling.render(renderer);
                score.render(renderer, font);
                SDL_RenderPresent(renderer);
                LastFall = SDL_GetTicks();
            }
        }else {
            falling.changeTx(brics[previewVal]);
            falling.resizeRect(falling.GetRect()->w*3, falling.GetRect()->h*3);
            falling.SetPositionXY(22, 22);
            std::cout << previewVal << std::endl;
            previewVal = rand() % 7;
            std::cout << previewVal << std::endl;
            preview.bric.changeTx(brics[previewVal]);
            preview.bric.resizeRect(preview.bric.GetRect()->w*3, preview.bric.GetRect()->h*3);
            isFalling = true;
        }
        
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 1; // Quitter le programme.
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                isFalling = !isFalling;
                score.addScore(50);
                jeu.render(renderer);
                score.render(renderer, font);
                preview.bric.render(renderer);
                falling.render(renderer);
                SDL_RenderPresent(renderer);
            }
        }
        SDL_Delay(30);
    }
    

    SDL_RenderPresent(renderer);
    // Libération mémoire
    for (int i = 0; i < 10; i++) {
        SDL_DestroyTexture(font[i]);
        std::cout << "Texture \"" << i << ".bmp\" Détruite" << std::endl;
    }
    delete[] font;
    return 0;
}