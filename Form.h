#ifndef FORM_H_INCLUDED
#define FORM_H_INCLUDED

struct Form {
    Sint16 x[4];
    Sint16 y[4];
    int type;
};

struct Tangram {
    struct Form hTri1, hTri2, mTri, sTri1, sTri2, square, trapeze;
    struct Tangram *puzzle1;
    struct Tangram *puzzle2;
    struct Tangram *puzzle3;
    int puzzle;
    struct Form* forms[7]; //tableau de parcours des formes
    short base;
    short x; // coordonnées du point supérieur gauche
    short y; // du carré de base
    Uint8 r, g, b, a; //couleur des pièces
    Uint8 fr, fg, fb, fa; //couleur de la pièce selectionnée
};

#endif
