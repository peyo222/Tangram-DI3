#include "Utilities.h"

int Init(struct Tangram *tangram) {

    /* Initialisation du tangram */
    tangram->hTri1.type = 3;
    tangram->hTri2.type = 3;
    tangram->mTri.type = 3;
    tangram->sTri1.type = 3;
    tangram->sTri2.type = 3;
    tangram->square.type = 4;
    tangram->trapeze.type = 4;
    tangram->forms[0] = &(tangram->sTri1);
    tangram->forms[1] = &(tangram->sTri2);
    tangram->forms[2] = &(tangram->mTri);
    tangram->forms[3] = &(tangram->trapeze);
    tangram->forms[4] = &(tangram->square);
    tangram->forms[5] = &(tangram->hTri1);
    tangram->forms[6] = &(tangram->hTri2);
    tangram->base = 200;
    tangram->r = 255;
    tangram->g = 255;
    tangram->b = 255;
    tangram->a = 255;
    tangram->fr = 102;
    tangram->fg = 255;
    tangram->fb = 153;
    tangram->fa = 255;
    tangram->x = 50;
    tangram->y = 50;
    tangram->puzzle = 1;

    /* Initialisation du premier grand triangle */
    tangram->hTri1.x[0] = tangram->x;
    tangram->hTri1.y[0] = tangram->y;
    tangram->hTri1.x[1] = tangram->x + (tangram->base)/2;
    tangram->hTri1.y[1] = tangram->y + (tangram->base)/2;
    tangram->hTri1.x[2] = tangram->x;
    tangram->hTri1.y[2] = tangram->y + tangram->base;

    /* Initialisation du deuxième grand triangle */
    tangram->hTri2.x[0] = tangram->x;
    tangram->hTri2.y[0] = tangram->y;
    tangram->hTri2.x[1] = tangram->x + tangram->base;
    tangram->hTri2.y[1] = tangram->y;
    tangram->hTri2.x[2] = tangram->x + (tangram->base)/2;
    tangram->hTri2.y[2] = tangram->y + (tangram->base)/2;

    /* Initialisation du triangle moyen */
    tangram->mTri.x[0] = tangram->x +(tangram->base)/2;
    tangram->mTri.y[0] = tangram->y + tangram->base;
    tangram->mTri.x[1] = tangram->x + tangram->base;
    tangram->mTri.y[1] = tangram->y + (tangram->base)/2;
    tangram->mTri.x[2] = tangram->x + tangram->base;
    tangram->mTri.y[2] = tangram->y + tangram->base;

    /* Initialisation du premier petit triangle */
    tangram->sTri1.x[0] = tangram->x;
    tangram->sTri1.y[0] = tangram->y + tangram->base;
    tangram->sTri1.x[1] = tangram->x + (tangram->base)/4;
    tangram->sTri1.y[1] = tangram->y + (tangram->base)*3/4;
    tangram->sTri1.x[2] = tangram->x + (tangram->base)/2;
    tangram->sTri1.y[2] = tangram->y + (tangram->base);

    /* Initialisation du deuxième petit triangle */
    tangram->sTri2.x[0] = tangram->x + (tangram->base)/2;
    tangram->sTri2.y[0] = tangram->y + (tangram->base)/2;
    tangram->sTri2.x[1] = tangram->x + (tangram->base)*3/4;
    tangram->sTri2.y[1] = tangram->y + (tangram->base)/4;
    tangram->sTri2.x[2] = tangram->x + (tangram->base)*3/4;
    tangram->sTri2.y[2] = tangram->y + (tangram->base)*3/4;

    /* Initialisation du carré */
    tangram->square.x[0] = tangram->x + (tangram->base)/2;
    tangram->square.y[0] = tangram->y + (tangram->base)/2;
    tangram->square.x[1] = tangram->x + (tangram->base)*3/4;
    tangram->square.y[1] = tangram->y + (tangram->base)*3/4;
    tangram->square.x[2] = tangram->x + (tangram->base)/2;
    tangram->square.y[2] = tangram->y + tangram->base;
    tangram->square.x[3] = tangram->x + (tangram->base)/4;
    tangram->square.y[3] = tangram->y + (tangram->base)*3/4;

    /* Initialisation du trapèze */
    tangram->trapeze.x[0] = tangram->x + (tangram->base)*3/4;
    tangram->trapeze.y[0] = tangram->y + (tangram->base)/4;
    tangram->trapeze.x[1] = tangram->x + tangram->base;
    tangram->trapeze.y[1] = tangram->y;
    tangram->trapeze.x[2] = tangram->x + tangram->base;
    tangram->trapeze.y[2] = tangram->y + (tangram->base)/2;
    tangram->trapeze.x[3] = tangram->x + (tangram->base)*3/4;
    tangram->trapeze.y[3] = tangram->y + (tangram->base)*3/4;

    /* Initialisation du puzzle1 */
    tangram->puzzle1->hTri1.x[0] = 472;
    tangram->puzzle1->hTri1.y[0] = 160;
    tangram->puzzle1->hTri1.x[1] = 572;
    tangram->puzzle1->hTri1.y[1] = 260;
    tangram->puzzle1->hTri1.x[2] = 472;
    tangram->puzzle1->hTri1.y[2] = 360;
    tangram->puzzle1->hTri2.x[0] = 433;
    tangram->puzzle1->hTri2.y[0] = 400;
    tangram->puzzle1->hTri2.x[1] = 574;
    tangram->puzzle1->hTri2.y[1] = 259;
    tangram->puzzle1->hTri2.x[2] = 574;
    tangram->puzzle1->hTri2.y[2] = 400;
    tangram->puzzle1->mTri.x[0] = 471;
    tangram->puzzle1->mTri.y[0] = 160;
    tangram->puzzle1->mTri.x[1] = 471;
    tangram->puzzle1->mTri.y[1] = 301;
    tangram->puzzle1->mTri.x[2] = 401;
    tangram->puzzle1->mTri.y[2] = 231;
    tangram->puzzle1->sTri1.x[0] = 422;
    tangram->puzzle1->sTri1.y[0] = 10;
    tangram->puzzle1->sTri1.x[1] = 471;
    tangram->puzzle1->sTri1.y[1] = 60;
    tangram->puzzle1->sTri1.x[2] = 422;
    tangram->puzzle1->sTri1.y[2] = 109;
    tangram->puzzle1->sTri2.x[0] = 473;
    tangram->puzzle1->sTri2.y[0] = 60;
    tangram->puzzle1->sTri2.x[1] = 523;
    tangram->puzzle1->sTri2.y[1] = 10;
    tangram->puzzle1->sTri2.x[2] = 523;
    tangram->puzzle1->sTri2.y[2] = 110;
    tangram->puzzle1->square.x[0] = 472;
    tangram->puzzle1->square.y[0] = 60;
    tangram->puzzle1->square.x[1] = 522;
    tangram->puzzle1->square.y[1] = 110;
    tangram->puzzle1->square.x[2] = 472;
    tangram->puzzle1->square.y[2] = 160;
    tangram->puzzle1->square.x[3] = 422;
    tangram->puzzle1->square.y[3] = 110;
    tangram->puzzle1->trapeze.x[0] = 645;
    tangram->puzzle1->trapeze.y[0] = 324;
    tangram->puzzle1->trapeze.x[1] = 716;
    tangram->puzzle1->trapeze.y[1] = 324;
    tangram->puzzle1->trapeze.x[2] = 645;
    tangram->puzzle1->trapeze.y[2] = 394;
    tangram->puzzle1->trapeze.x[3] = 574;
    tangram->puzzle1->trapeze.y[3] = 394;

    /* Initialisation du puzzle2 */
    tangram->puzzle2->hTri1.x[0] = 474;
    tangram->puzzle2->hTri1.y[0] = 266;
    tangram->puzzle2->hTri1.x[1] = 615;
    tangram->puzzle2->hTri1.y[1] = 266;
    tangram->puzzle2->hTri1.x[2] = 615;
    tangram->puzzle2->hTri1.y[2] = 407;
    tangram->puzzle2->hTri2.x[0] = 473;
    tangram->puzzle2->hTri2.y[0] = 124;
    tangram->puzzle2->hTri2.x[1] = 614;
    tangram->puzzle2->hTri2.y[1] = 265;
    tangram->puzzle2->hTri2.x[2] = 473;
    tangram->puzzle2->hTri2.y[2] = 265;
    tangram->puzzle2->mTri.x[0] = 615;
    tangram->puzzle2->mTri.y[0] = 408;
    tangram->puzzle2->mTri.x[1] = 515;
    tangram->puzzle2->mTri.y[1] = 308;
    tangram->puzzle2->mTri.x[2] = 515;
    tangram->puzzle2->mTri.y[2] = 408;
    tangram->puzzle2->sTri1.x[0] = 514;
    tangram->puzzle2->sTri1.y[0] = 308;
    tangram->puzzle2->sTri1.x[1] = 465;
    tangram->puzzle2->sTri1.y[1] = 358;
    tangram->puzzle2->sTri1.x[2] = 514;
    tangram->puzzle2->sTri1.y[2] = 407;
    tangram->puzzle2->sTri2.x[0] = 422;
    tangram->puzzle2->sTri2.y[0] = 267;
    tangram->puzzle2->sTri2.x[1] = 472;
    tangram->puzzle2->sTri2.y[1] = 217;
    tangram->puzzle2->sTri2.x[2] = 472;
    tangram->puzzle2->sTri2.y[2] = 317;
    tangram->puzzle2->square.x[0] = 472;
    tangram->puzzle2->square.y[0] = 90;
    tangram->puzzle2->square.x[1] = 472;
    tangram->puzzle2->square.y[1] = 160;
    tangram->puzzle2->square.x[2] = 402;
    tangram->puzzle2->square.y[2] = 160;
    tangram->puzzle2->square.x[3] = 402;
    tangram->puzzle2->square.y[3] = 90;
    tangram->puzzle2->trapeze.x[0] = 500;
    tangram->puzzle2->trapeze.y[0] = 19;
    tangram->puzzle2->trapeze.x[1] = 571;
    tangram->puzzle2->trapeze.y[1] = 19;
    tangram->puzzle2->trapeze.x[2] = 500;
    tangram->puzzle2->trapeze.y[2] = 89;
    tangram->puzzle2->trapeze.x[3] = 429;
    tangram->puzzle2->trapeze.y[3] = 89;

    /* Initialisation du puzzle3 */
    tangram->puzzle3->hTri1.x[0] = 702;
    tangram->puzzle3->hTri1.y[0] = 332;
    tangram->puzzle3->hTri1.x[1] = 602;
    tangram->puzzle3->hTri1.y[1] = 232;
    tangram->puzzle3->hTri1.x[2] = 502;
    tangram->puzzle3->hTri1.y[2] = 332;
    tangram->puzzle3->hTri2.x[0] = 401;
    tangram->puzzle3->hTri2.y[0] = 232;
    tangram->puzzle3->hTri2.x[1] = 601;
    tangram->puzzle3->hTri2.y[1] = 232;
    tangram->puzzle3->hTri2.x[2] = 501;
    tangram->puzzle3->hTri2.y[2] = 332;
    tangram->puzzle3->mTri.x[0] = 401;
    tangram->puzzle3->mTri.y[0] = 90;
    tangram->puzzle3->mTri.x[1] = 542;
    tangram->puzzle3->mTri.y[1] = 89;
    tangram->puzzle3->mTri.x[2] = 471;
    tangram->puzzle3->mTri.y[2] = 20;
    tangram->puzzle3->sTri1.x[0] = 453;
    tangram->puzzle3->sTri1.y[0] = 382;
    tangram->puzzle3->sTri1.x[1] = 503;
    tangram->puzzle3->sTri1.y[1] = 332;
    tangram->puzzle3->sTri1.x[2] = 553;
    tangram->puzzle3->sTri1.y[2] = 382;
    tangram->puzzle3->sTri2.x[0] = 632;
    tangram->puzzle3->sTri2.y[0] = 333;
    tangram->puzzle3->sTri2.x[1] = 681;
    tangram->puzzle3->sTri2.y[1] = 383;
    tangram->puzzle3->sTri2.x[2] = 583;
    tangram->puzzle3->sTri2.y[2] = 383;
    tangram->puzzle3->square.x[0] = 542;
    tangram->puzzle3->square.y[0] = 90;
    tangram->puzzle3->square.x[1] = 542;
    tangram->puzzle3->square.y[1] = 160;
    tangram->puzzle3->square.x[2] = 472;
    tangram->puzzle3->square.y[2] = 160;
    tangram->puzzle3->square.x[3] = 472;
    tangram->puzzle3->square.y[3] = 90;
    tangram->puzzle3->trapeze.x[0] = 472;
    tangram->puzzle3->trapeze.y[0] = 161;
    tangram->puzzle3->trapeze.x[1] = 543;
    tangram->puzzle3->trapeze.y[1] = 161;
    tangram->puzzle3->trapeze.x[2] = 472;
    tangram->puzzle3->trapeze.y[2] = 231;
    tangram->puzzle3->trapeze.x[3] = 401;
    tangram->puzzle3->trapeze.y[3] = 231;

    /* Initialisation commune des puzzles */
    tangram->puzzle1->hTri1.type = 3;
    tangram->puzzle1->hTri2.type = 3;
    tangram->puzzle1->mTri.type = 3;
    tangram->puzzle1->sTri1.type = 3;
    tangram->puzzle1->sTri2.type = 3;
    tangram->puzzle1->square.type = 4;
    tangram->puzzle1->trapeze.type = 4;
    tangram->puzzle1->r = 0;
    tangram->puzzle1->g = 0;
    tangram->puzzle1->b = 0;
    tangram->puzzle1->a = 125;
    tangram->puzzle2->hTri1.type = 3;
    tangram->puzzle2->hTri2.type = 3;
    tangram->puzzle2->mTri.type = 3;
    tangram->puzzle2->sTri1.type = 3;
    tangram->puzzle2->sTri2.type = 3;
    tangram->puzzle2->square.type = 4;
    tangram->puzzle2->trapeze.type = 4;
    tangram->puzzle2->r = 0;
    tangram->puzzle2->g = 0;
    tangram->puzzle2->b = 0;
    tangram->puzzle2->a = 125;
    tangram->puzzle3->hTri1.type = 3;
    tangram->puzzle3->hTri2.type = 3;
    tangram->puzzle3->mTri.type = 3;
    tangram->puzzle3->sTri1.type = 3;
    tangram->puzzle3->sTri2.type = 3;
    tangram->puzzle3->square.type = 4;
    tangram->puzzle3->trapeze.type = 4;
    tangram->puzzle3->r = 0;
    tangram->puzzle3->g = 0;
    tangram->puzzle3->b = 0;
    tangram->puzzle3->a = 125;

    return 0;
}

Uint32 Refresh(Uint32 interval, void *param) {
    /*SDL_FillRect(screen, NULL, 0);*/
    SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Surface *texture;
    SDL_Surface *button;
    struct Tangram *tangram;
    struct Form *focus;
    SDL_Rect position;
    void ** pparam = (void**)param;

    screen = (SDL_Surface*)pparam[0];
    background = (SDL_Surface*)pparam[1];
    texture = (SDL_Surface*)pparam[2];
    tangram = (struct Tangram*)pparam[3];
    focus = (struct Form*)pparam[4];
    button = (SDL_Surface*)pparam[5];

    position.x = 0;position.y = 0;
    SDL_BlitSurface(background, NULL, screen, &position);
    position.x = WIN_SIZE_X - 5 - 76; position.y = WIN_SIZE_Y - 5 - 76;
    SDL_BlitSurface(button, NULL, screen, &position);

    if (tangram->puzzle == 1) {
        filledPolygonRGBA(screen, tangram->puzzle1->hTri2.x, tangram->puzzle1->hTri2.y, tangram->puzzle1->hTri2.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->hTri1.x, tangram->puzzle1->hTri1.y, tangram->puzzle1->hTri1.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->mTri.x, tangram->puzzle1->mTri.y, tangram->puzzle1->mTri.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->square.x, tangram->puzzle1->square.y, tangram->puzzle1->square.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->trapeze.x, tangram->puzzle1->trapeze.y, tangram->puzzle1->trapeze.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->sTri2.x, tangram->puzzle1->sTri2.y, tangram->puzzle1->sTri2.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
        filledPolygonRGBA(screen, tangram->puzzle1->sTri1.x, tangram->puzzle1->sTri1.y, tangram->puzzle1->sTri1.type, tangram->puzzle1->r, tangram->puzzle1->g, tangram->puzzle1->b, tangram->puzzle1->a);
    }
    else if (tangram->puzzle == 2) {
        filledPolygonRGBA(screen, tangram->puzzle2->hTri2.x, tangram->puzzle2->hTri2.y, tangram->puzzle2->hTri2.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->hTri1.x, tangram->puzzle2->hTri1.y, tangram->puzzle2->hTri1.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->mTri.x, tangram->puzzle2->mTri.y, tangram->puzzle2->mTri.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->square.x, tangram->puzzle2->square.y, tangram->puzzle2->square.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->trapeze.x, tangram->puzzle2->trapeze.y, tangram->puzzle2->trapeze.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->sTri2.x, tangram->puzzle2->sTri2.y, tangram->puzzle2->sTri2.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
        filledPolygonRGBA(screen, tangram->puzzle2->sTri1.x, tangram->puzzle2->sTri1.y, tangram->puzzle2->sTri1.type, tangram->puzzle2->r, tangram->puzzle2->g, tangram->puzzle2->b, tangram->puzzle2->a);
    }
    else if (tangram->puzzle == 3) {
        filledPolygonRGBA(screen, tangram->puzzle3->hTri2.x, tangram->puzzle3->hTri2.y, tangram->puzzle3->hTri2.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->hTri1.x, tangram->puzzle3->hTri1.y, tangram->puzzle3->hTri1.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->mTri.x, tangram->puzzle3->mTri.y, tangram->puzzle3->mTri.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->square.x, tangram->puzzle3->square.y, tangram->puzzle3->square.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->trapeze.x, tangram->puzzle3->trapeze.y, tangram->puzzle3->trapeze.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->sTri2.x, tangram->puzzle3->sTri2.y, tangram->puzzle3->sTri2.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
        filledPolygonRGBA(screen, tangram->puzzle3->sTri1.x, tangram->puzzle3->sTri1.y, tangram->puzzle3->sTri1.type, tangram->puzzle3->r, tangram->puzzle3->g, tangram->puzzle3->b, tangram->puzzle3->a);
    }

    texturedPolygon(screen, tangram->hTri2.x, tangram->hTri2.y, tangram->hTri2.type, texture, 0, 0);
    aapolygonRGBA(screen, tangram->hTri2.x, tangram->hTri2.y, tangram->hTri2.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->hTri1.x, tangram->hTri1.y, tangram->hTri1.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->hTri1.x, tangram->hTri1.y, tangram->hTri1.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->mTri.x, tangram->mTri.y, tangram->mTri.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->mTri.x, tangram->mTri.y, tangram->mTri.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->square.x, tangram->square.y, tangram->square.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->square.x, tangram->square.y, tangram->square.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->trapeze.x, tangram->trapeze.y, tangram->trapeze.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->trapeze.x, tangram->trapeze.y, tangram->trapeze.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->sTri2.x, tangram->sTri2.y, tangram->sTri2.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->sTri2.x, tangram->sTri2.y, tangram->sTri2.type, 0, 0, 0, 255);
    texturedPolygon(screen, tangram->sTri1.x, tangram->sTri1.y, tangram->sTri1.type, texture, 0 ,0);
    aapolygonRGBA(screen, tangram->sTri1.x, tangram->sTri1.y, tangram->sTri1.type, 0, 0, 0, 255);

    SDL_Flip(screen);
    return(interval);
}

struct Form* Selection(struct Tangram *tangram, short x, short y) {
    short vector1[2];
    short vector2[2];
    int i, j, tmp, res;

    for (i=0; i<7; i++) {
        res = 0;
        for (j=0; j<tangram->forms[i]->type; j++) {
            if (j<(tangram->forms[i]->type)-1) {
                vector1[0] = tangram->forms[i]->x[j+1] - tangram->forms[i]->x[j];
                vector1[1] = tangram->forms[i]->y[j+1] - tangram->forms[i]->y[j];
            }
            else {
                vector1[0] = tangram->forms[i]->x[0] - tangram->forms[i]->x[j];
                vector1[1] = tangram->forms[i]->y[0] - tangram->forms[i]->y[j];
            }
            vector2[0] = x - tangram->forms[i]->x[j];
            vector2[1] = y - tangram->forms[i]->y[j];
            /*tmp = vector1[0]*vector2[0]+vector1[1]*vector2[1];*/
            tmp = vector2[0]*vector1[1]-vector1[0]*vector2[1];
            if (tmp > 0)
                res++;
            else if (tmp < 0)
                res--;
        }
        /*printf("i = %d res = %d  x = %d y = %d\n",i ,res, x, y);*/
        if (res == (tangram->forms[i]->type)*(-1) || res == tangram->forms[i]->type)
            return tangram->forms[i];
    }
    return NULL;
}

void DragDrop(struct Form *focus, short x, short y) {
    int g[2]; //Point de gravité
    int v[2]; //Vecteur de translation
    int i;
    if (focus->type == 3) {
        g[0] = (focus->x[0]+focus->x[1]+focus->x[2])/3;
        g[1] = (focus->y[0]+focus->y[1]+focus->y[2])/3;
    }
    if (focus->type == 4) {
        g[0] = focus->x[0]+(focus->x[2]-focus->x[0])/2;
        g[1] = focus->y[0]+(focus->y[2]-focus->y[0])/2;
    }
    v[0] = x - g[0];
    v[1] = y - g[1];
    for(i=0;i<focus->type;i++) {
        //printf("x = %d y = %d", focus->x[i], focus->y[i]);
        focus->x[i] = focus->x[i]+v[0];
        focus->y[i] = focus->y[i]+v[1];
    }
}

void Invert(struct Form *focus) {
    int tmp;
    int g;
    int i;
    if (focus->type == 4)
        g = focus->x[0]+(focus->x[2]-focus->x[0])/2;
    else if (focus->type == 3)
        g = (focus->x[0]+focus->x[1]+focus->x[2])/3;
    for (i=0;i<focus->type;i++) {
        tmp = focus->x[i] - g;
        focus->x[i] = g-tmp;
    }
}

void Rotation(struct Form *focus) {
    int g[2]; //Point de gravité
    int i;
    float angle = 45; //Angle de Rotation
    short xi;

    angle = ( M_PI * angle ) / 180;

    if(focus->type == 3) {
        g[0] = (focus->x[0]+focus->x[1]+focus->x[2])/3;
        g[1] = (focus->y[0]+focus->y[1]+focus->y[2])/3;
        for(i=0; i<3; i++) {
            xi = focus->x[i];
            //printf("x = %d y = %d \n", focus->x[i], focus->y[i]);
            focus->x[i] = roundf((cos(angle) * (xi - g[0])) - (sin(angle) *(focus->y[i]-g[1])) + g[0]);
            focus->y[i] = roundf((sin(angle) * (xi - g[0])) + (cos(angle) *(focus->y[i]-g[1])) + g[1]);
            //printf("x' = %d y' = %d \n", focus->x[i], focus->y[i]);
        }
    }
    else {
        g[0] = focus->x[0]+(focus->x[2]-focus->x[0])/2;
        g[1] = focus->y[0]+(focus->y[2]-focus->y[0])/2;
        for(i=0; i<4; i++) {
            xi = focus->x[i];
            //printf("x = %d y = %d \n", focus->x[i], focus->y[i]);
            focus->x[i] = roundf((cos(angle) * (xi - g[0])) - (sin(angle) *(focus->y[i]-g[1])) + g[0]);
            focus->y[i] = roundf((sin(angle) * (xi - g[0])) + (cos(angle) *(focus->y[i]-g[1])) + g[1]);
            //printf("x' = %d y' = %d \n", focus->x[i], focus->y[i]);
        }
    }
}
