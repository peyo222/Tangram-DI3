#ifndef UTILITIES_H_INCLUDED
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "Form.h"
#define UTILITIES_H_INCLUDED
#define WIN_SIZE_X 840
#define WIN_SIZE_Y 480

int Init(struct Tangram *tangram);
struct Form* Selection(struct Tangram *tangram, short x, short y);
Uint32 Refresh(Uint32 interval, void *param);
void DragDrop(struct Form *focus,  short x, short y);
void Invert(struct Form *focus);
void Rotation(struct Form *focus);

#endif
