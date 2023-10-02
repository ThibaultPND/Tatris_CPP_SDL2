/***************************************************************
**  Auteur : Thibault Chassagne
**  MAJ : 30/09/2023
*  
**  Nom : Tatris
*  
*?  Description : Ce logiciel à pour but de crée une version éclaté de Tatris
*
g++ -o Tatris.exe -Iinclude -Iinclude/SDL2 src/*.cpp -Llib -lSDL2main -lSDL2 -static -DSDL_MAIN_HANDLED && bin\Tatris.exe
***************************************************************/
#include <Project.h>
#include <SDL2/SDL.h>
#include "TxUtils.h"
#include "render.h"
#include "sound2.h"
#include "loop.h"
#include "font.h"


int main(int argc, char* argv[]) {
    std::cout << "Debut du  programme...\n" << std::endl;
    SDL_Window* window(nullptr);
    SDL_Renderer* renderer(nullptr);
    try {
        // Initialisation
        InitializeSDL( window, renderer );
        srand(SDL_GetTicks());

        // Programme

        if (loopMenu(renderer) == 1){
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            std::cout << "Fin du programme...\n" << std::endl;

            return EXIT_SUCCESS;
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        if (loopJeu(renderer) == 1){
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            std::cout << "Fin du programme...\n" << std::endl;

            return EXIT_SUCCESS;
        }


        // Libération des ressources
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::cout << "Fin du programme...\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}