#ifndef UTILITIES_H_INCLUDED
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Form.h"
#define UTILITIES_H_INCLUDED

int Init(struct Tangram *tangram);
struct Form* Selection(struct Tangram *tangram, short x, short y);
void Refresh(SDL_Surface *screen, SDL_Surface *background, SDL_Surface *texture, struct Tangram *tangram, struct Form *focus);
void DragDrop(struct Form *focus,  short x, short y);
void Invert(struct Form *focus);
void Rotation(struct Form *focus);

#endif
