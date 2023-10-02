#ifndef __PROJECT_H__
#define __PROJECT_H__

// Inclusions
#include<iostream>
#include<string>
#include<SDL2/SDL.h>

// Maccros dimension fenêtre
#define HAUTEUR_FENETRE 900
#define LARGEUR_FENETRE 700

#define HAUTEUR_LOGIQUE 90
#define LARGEUR_LOGIQUE 70

#define HAUTEUR_JEU 79
#define LARGEUR_JEU 45


// Prototypes
void InitializeSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void ExitWithError(const char *ErrorMessage);

#endif // __PROJECT_H__