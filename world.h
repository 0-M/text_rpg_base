#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include "map.h"

typedef struct S_WORLD {
	map m           ;
	char **items    ;
	char **creatures;
	char **players  ;
} world ; 

extern int worldInit( char *mapString , world *WORLD ) ;

extern worldDelete( world *WORLD ) ;

extern worldCopy( world *WORLD ) ;

extern worldPrint(world *WORLD ) ;

#endif
