/* main API for the displayed world */

#include "map.h"

typedef struct S_WORLD {
	char **map      ;
	char **items    ;
	char **creatures;
	char **players  ;
} world ; 

void worldInit( char *mapString , world *WORLD ) ;

