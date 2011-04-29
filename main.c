#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Utilities.h"

int main ( int argc, char** argv ) {
    SDL_Surface *screen = NULL;
    SDL_Event event;
    int done = 0;
    struct Tangram tangram;
    struct Form * focus = NULL;


    /* Initialisation*/
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { // Initialisation du SDL_Video
        printf( "Impossible d'initialiser SDL: %s\n", SDL_GetError() );
        return -1;
    }
    screen = SDL_SetVideoMode(840, 480, 16, SDL_SWSURFACE|SDL_DOUBLEBUF); // Creation d'une nouvelle fenêtre
    if ( !screen ) {
        printf("Impossible d'initialiser la fenêtre: %s\n", SDL_GetError());
        return -1;
    }
    SDL_WM_SetCaption("Tangram", NULL); // Nom de la fenêtre
    if (Init(screen, &tangram) == -1) // Initialisation des formes et des dessins
        return -1;


    /*Programme principal*/
    while (!done) { // Boucle principale
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: // Si la fenêtre est fermée
                    done = 1;
                    break;
                case SDL_KEYDOWN: { // Si un touche est pressée
                        if (event.key.keysym.sym == SDLK_ESCAPE) // On quitte si Echap
                            done = 1;
                        break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    if (event.button.button == SDL_BUTTON_RIGHT);
                    if (event.button.button == SDL_BUTTON_MIDDLE);
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        focus = Selection(&tangram,event.button.x,event.button.y);
                        if(focus!=NULL) puts("OK"); else puts("KO");
                        if (focus != NULL) {
                            polygonRGBA(screen, focus->x, focus->y, focus->type, 125, 75, 0, 255);
                        }
                    }
                }
            }
        }
    }
    SDL_Quit(); // On ferme SDL
    return 0;
}
