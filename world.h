#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include "map.h"

/* fixme move definition of world struct to world.c */

typedef struct world_s *world;

extern int worldInit( world *w ) ;

extern int worldZero( world w ) ;

extern int worldIsInitted( world w ) ;

extern int worldDelete( world w ) ;

extern int worldCopy( world dest, world src ) ;

extern int worldPrint(world w ) ;

extern int worldEqual(world lhs, world rhs ) ;

extern int worldName( world w, char **str_ptr ) ;

#endif
