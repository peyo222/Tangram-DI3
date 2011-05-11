#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Utilities.h"

int main ( int argc, char** argv ) {
    SDL_Surface *screen = NULL;
    SDL_Event event;
    int done = 0;
    int dragDrop = 0;
    struct Tangram tangram;
    struct Form * focus = NULL;


    /* Initialisation*/
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { // Initialisation du SDL_Video
        printf( "Impossible d'initialiser SDL: %s\n", SDL_GetError() );
        return -1;
    }
    screen = SDL_SetVideoMode(840, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF); // Creation d'une nouvelle fenêtre
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
                    if (event.button.button == SDL_BUTTON_RIGHT){
                        focus = Selection(&tangram,event.button.x,event.button.y);
                        Rotation(focus);
                         Refresh(screen,&tangram,focus);
                    };
                    if (event.button.button == SDL_BUTTON_MIDDLE);
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (dragDrop == 0) {
                            focus = Selection(&tangram,event.button.x,event.button.y);
                            Refresh(screen,&tangram,focus);
                            if (focus != NULL)
                                dragDrop = 1;
                        }
                        else
                            dragDrop = 0;
                    }
                }
                case SDL_MOUSEMOTION: {
                    if (dragDrop == 1) {
                        DragDrop(focus, event.motion.x, event.motion.y);
                        Refresh(screen, &tangram, focus);
                    }
                }
            }
        }
    }
    SDL_Quit(); // On ferme SDL
    return 0;
}
