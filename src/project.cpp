#include"Project.h"

void InitializeSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Erreur lors de l'initialisation de SDL : " + std::string(SDL_GetError()));
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    // Création de la fenêtre
    window = SDL_CreateWindow("Tatris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0);
    if (window == nullptr) {
        SDL_Quit();
        throw std::runtime_error("Erreur lors de la création de la fenêtre : " + std::string(SDL_GetError()));
    }

    // Création du rendu
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error("Erreur lors de la création du rendu : " + std::string(SDL_GetError()));
    }

    if(SDL_RenderSetLogicalSize(renderer, LARGEUR_LOGIQUE, HAUTEUR_LOGIQUE)) {
        throw std::runtime_error("Erreur lors du changement de taille logique : " + std::string(SDL_GetError()));
    }

    if (SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE)) {
        throw std::runtime_error("Erreur lors du changement du DrawColor : " + std::string(SDL_GetError()));
    }
    
}


void ExitWithError(const char *message) {
    SDL_Log("Erreur : %s > %s", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

