#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include "map.h"

typedef struct S_WORLD {
	char **map      ;
	char **items    ;
	char **creatures;
	char **players  ;
} world ; 

int worldInit( char *mapString , world *WORLD ) ;

#endif
