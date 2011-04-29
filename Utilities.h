#ifndef UTILITIES_H_INCLUDED
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Form.h"
#define UTILITIES_H_INCLUDED

int Init(SDL_Surface *screen, struct Tangram *tangram);
struct Form* Selection(struct Tangram *tangram, short x, short y);


#endif
