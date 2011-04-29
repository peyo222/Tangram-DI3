#include "Utilities.h"

int Init(SDL_Surface *screen,struct Tangram *tangram) {
    /* Initialisation du tangram */
    tangram->hTri1.type = 3;
    tangram->hTri2.type = 3;
    tangram->mTri.type = 3;
    tangram->sTri1.type = 3;
    tangram->sTri2.type = 3;
    tangram->square.type = 4;
    tangram->trapeze.type = 4;
    tangram->forms[0] = &(tangram->hTri1); tangram->forms[1] = &(tangram->hTri2); tangram->forms[2] = &(tangram->mTri); tangram->forms[3] = &(tangram->sTri1); tangram->forms[4] = &(tangram->sTri2); tangram->forms[5] = &(tangram->square); tangram->forms[6] = &(tangram->trapeze);
    tangram->base = 300;
    tangram->r = 255;
    tangram->g = 255;
    tangram->b = 255;
    tangram->a = 255;
    tangram->x = 50;
    tangram->y = 50;

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


    /* Dessin du carré de base */
    boxRGBA(screen, tangram->x, tangram->y, tangram->x + tangram->base, tangram->y + tangram->base, tangram->r, tangram->g, tangram->b, tangram->a);
    /*filledPolygonRGBA(screen, tangram->hTri1.x, tangram->hTri1.y, 3, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->hTri2.x, tangram->hTri2.y, 3, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->mTri.x, tangram->mTri.y, 3, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->sTri1.x, tangram->sTri1.y, 3, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->sTri2.x, tangram->sTri2.y, 3, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->square.x, tangram->square.y, 4, tangram->r, tangram->g, tangram->b, tangram->a);
    filledPolygonRGBA(screen, tangram->trapeze.x, tangram->trapeze.y, 4, tangram->r, tangram->g, tangram->b, tangram->a);*/

    polygonRGBA(screen, tangram->hTri1.x, tangram->hTri1.y, tangram->hTri1.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->hTri2.x, tangram->hTri2.y, tangram->hTri2.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->mTri.x, tangram->mTri.y, tangram->mTri.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->sTri1.x, tangram->sTri1.y, tangram->sTri1.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->sTri2.x, tangram->sTri2.y, tangram->sTri2.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->square.x, tangram->square.y, tangram->square.type, 0, 0, 0, 255);
    polygonRGBA(screen, tangram->trapeze.x, tangram->trapeze.y, tangram->trapeze.type, 0, 0, 0, 255);

    SDL_Flip(screen);
    return 0;
}

struct Form* Selection(struct Tangram *tangram, short x, short y) {
    short vector1[2];
    short vector2[2];
    int i, j, tmp, res;
    for (i=0;i<7;i++) {
        res = 0;
        for (j=0;j<tangram->forms[i]->type;j++) {
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
            tmp = vector1[0]*vector2[0]+vector1[1]*vector2[1];
            if (tmp > 0)
                res++;
            else if (tmp < 0)
                res--;
        }
        printf("i = %d res = %d  x = %d y = %d\n",i ,res, x, y);
        if (res == (tangram->forms[i]->type)*(-1) || res == tangram->forms[i]->type)
            return tangram->forms[i];
    }
    return NULL;
}