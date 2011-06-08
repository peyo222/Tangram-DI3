#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Utilities.h"

void Afficher(struct Tangram *tangram);
int main ( int argc, char** argv ) {
    SDL_Surface *screen = NULL;
    SDL_Surface *background = NULL;
    SDL_Surface *texture = NULL;
    SDL_Surface *button = NULL;
    SDL_Surface *buttonTmp = NULL;
    SDL_Event event;
    int done = 0;       // Fin de la boucle principale
    int dragDrop = 0;   // Détection du drag&drop
    int buttonUp = 0;   // On prend un buttonUp sur deux
    int doubleClick = 0;// Détection du double click
    int mouse[2];       // Sauvegarde des coordonnées de la souris
    struct Tangram tangram;
    struct Tangram puzzle1;
    struct Tangram puzzle2;
    struct Tangram puzzle3;
    struct Form * focus = NULL;
    void* param[6];
    Uint32 colorkey;
    SDL_TimerID timer;
    Uint32 delay = (33/10)*10;
    tangram.puzzle1 = &puzzle1;
    tangram.puzzle2 = &puzzle2;
    tangram.puzzle3 = &puzzle3;
    tangram.puzzle = 1;


    /* Initialisation*/
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) { // Initialisation du SDL_Video
        printf( "Impossible d'initialiser SDL: %s\n", SDL_GetError() );
        return -1;
    }
    screen = SDL_SetVideoMode(WIN_SIZE_X, WIN_SIZE_Y, 16, SDL_HWSURFACE|SDL_DOUBLEBUF); // Creation d'une nouvelle fenêtre
    //Init du background
    background = SDL_LoadBMP("japan2.bmp");
    //Init de la texture
    texture = SDL_LoadBMP("texture.bmp");
    //Init du boutton
    buttonTmp = SDL_LoadBMP("button2.bmp");
    button = SDL_DisplayFormat(buttonTmp);
    SDL_FreeSurface(buttonTmp);
    colorkey = SDL_MapRGB(button->format, 124, 50, 124);
    SDL_SetColorKey(button, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );

    if (!screen) {
        printf("Impossible d'initialiser la fenêtre: %s\n", SDL_GetError());
        return -1;
    }
    SDL_WM_SetCaption("Tangram", NULL); // Nom de la fenêtre
    if (Init(&tangram) == -1) // Initialisation des formes et des dessins
        return -1;

    param[0] = screen;
    param[1] = background;
    param[2] = texture;
    param[3] = &tangram;
    param[4] = focus;
    param[5] = button;
    //Refresh(30, param);
    timer = SDL_AddTimer(delay, Refresh, param);
    //Refresh(screen, background, texture, &tangram, focus);
    /*Programme principal*/
    while (!done) { // Boucle principale
        while (SDL_WaitEvent(&event) && !done) {
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
                    if (event.button.button == SDL_BUTTON_RIGHT) {
                        focus = Selection(&tangram,event.button.x,event.button.y);
                        if (focus != NULL) {
                            Rotation(focus);
                            //Refresh(screen,background, texture, &tangram,focus);
                        }
                    }
                    if (event.button.button == SDL_BUTTON_MIDDLE);
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (!doubleClick) {
                            if (!dragDrop) {
                                focus = Selection(&tangram,event.button.x,event.button.y);
                                //Refresh(screen,background,texture,&tangram,focus);
                                if (focus != NULL) {
                                    dragDrop = 1;
                                    doubleClick = 1;
                                    mouse[0] = event.motion.x;
                                    mouse[1] = event.motion.y;
                                }
                                else if (event.motion.x > WIN_SIZE_X-76-5 && event.motion.x < WIN_SIZE_X-5 && event.motion.y > WIN_SIZE_Y-76-5 && event.motion.y < WIN_SIZE_Y-5) {
                                    if (tangram.puzzle < 3)
                                        tangram.puzzle++;
                                    else
                                        tangram.puzzle = 1;
                                    Init(&tangram);
                                }
                            }
                        }
                        else {
                            if (mouse[0] == event.motion.x && mouse[1] == event.motion.y) {
                                Invert(focus);
                                //Refresh(screen,background,texture,&tangram,focus);
                            }
                            focus = Selection(&tangram,event.button.x,event.button.y);
                            //Refresh(screen,background,texture,&tangram,focus);
                            if (focus != NULL)
                                dragDrop = 1;
                            doubleClick = 0;
                        }
                    }
                }
                case SDL_MOUSEBUTTONUP: {
                    if (!buttonUp)
                        buttonUp = 1;
                    else {
                        buttonUp = 0;
                        dragDrop = 0;
                    }
                }
                case SDL_MOUSEMOTION: {
                    if (dragDrop == 1) {
                        DragDrop(focus, event.motion.x, event.motion.y);
                        //Refresh(screen, background, texture,&tangram, focus);
                    }
                }
            }
            //Afficher(&tangram);
        }
        //timer = SDL_AddTimer(delay, Refresh, param);
    }
    SDL_FreeSurface(texture);
    SDL_FreeSurface(button);
    SDL_FreeSurface(background);
    SDL_Quit(); // On ferme SDL
    return 0;
}

void Afficher(struct Tangram *tangram) {
    printf("hTri1\n");
    printf("%d \n",tangram->hTri1.x[0]);
    printf("%d \n",tangram->hTri1.y[0]);
    printf("%d \n",tangram->hTri1.x[1]);
    printf("%d \n",tangram->hTri1.y[1]);
    printf("%d \n",tangram->hTri1.x[2]);
    printf("%d \n",tangram->hTri1.y[2]);
    printf("\n");
    printf("hTri2\n");
    printf("%d \n",tangram->hTri2.x[0]);
    printf("%d \n",tangram->hTri2.y[0]);
    printf("%d \n",tangram->hTri2.x[1]);
    printf("%d \n",tangram->hTri2.y[1]);
    printf("%d \n",tangram->hTri2.x[2]);
    printf("%d \n",tangram->hTri2.y[2]);
    printf("\n");
    printf("mTri\n");
    printf("%d \n",tangram->mTri.x[0]);
    printf("%d \n",tangram->mTri.y[0]);
    printf("%d \n",tangram->mTri.x[1]);
    printf("%d \n",tangram->mTri.y[1]);
    printf("%d \n",tangram->mTri.x[2]);
    printf("%d \n",tangram->mTri.y[2]);
    printf("\n");
    printf("sTri1\n");
    printf("%d \n",tangram->sTri1.x[0]);
    printf("%d \n",tangram->sTri1.y[0]);
    printf("%d \n",tangram->sTri1.x[1]);
    printf("%d \n",tangram->sTri1.y[1]);
    printf("%d \n",tangram->sTri1.x[2]);
    printf("%d \n",tangram->sTri1.y[2]);
    printf("\n");
    printf("sTri2\n");
    printf("%d \n",tangram->sTri2.x[0]);
    printf("%d \n",tangram->sTri2.y[0]);
    printf("%d \n",tangram->sTri2.x[1]);
    printf("%d \n",tangram->sTri2.y[1]);
    printf("%d \n",tangram->sTri2.x[2]);
    printf("%d \n",tangram->sTri2.y[2]);
    printf("\n");
    printf("square\n");
    printf("%d \n",tangram->square.x[0]);
    printf("%d \n",tangram->square.y[0]);
    printf("%d \n",tangram->square.x[1]);
    printf("%d \n",tangram->square.y[1]);
    printf("%d \n",tangram->square.x[2]);
    printf("%d \n",tangram->square.y[2]);
    printf("%d \n",tangram->square.x[3]);
    printf("%d \n",tangram->square.y[3]);
    printf("\n");
    printf("trapeze\n");
    printf("%d \n",tangram->trapeze.x[0]);
    printf("%d \n",tangram->trapeze.y[0]);
    printf("%d \n",tangram->trapeze.x[1]);
    printf("%d \n",tangram->trapeze.y[1]);
    printf("%d \n",tangram->trapeze.x[2]);
    printf("%d \n",tangram->trapeze.y[2]);
    printf("%d \n",tangram->trapeze.x[3]);
    printf("%d \n",tangram->trapeze.y[3]);
}
