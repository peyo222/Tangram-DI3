#ifndef FORM_H_INCLUDED
#define FORM_H_INCLUDED

struct Form {
    short x[4];
    short y[4];
    int type;
};

struct Tangram {
    struct Form hTri1, hTri2, mTri, sTri1, sTri2, square, trapeze;
    struct Form* forms[7]; //tableau de parcours des formes
    short base;
    short x; // coordonnées du point supérieur gauche
    short y; // du carré de base
    Uint8 r, g, b, a;
};

#endif
