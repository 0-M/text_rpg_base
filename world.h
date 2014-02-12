#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include "map.h"

/* fixme move definition of world struct to world.c */

typedef struct S_WORLD {
	map m           ;
	char **items    ;
	char **creatures;
	char **players  ;
} world ; 

extern int worldInit( char *mapString , world *WORLD ) ;

extern int worldDelete( world *WORLD ) ;

extern int worldCopy( world *WORLD ) ;

extern int worldPrint(world *WORLD ) ;

#endif
