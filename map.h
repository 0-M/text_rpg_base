#ifndef __MAP_H__
#define __MAP_H__

/* API for maps */

#include <stdint.h>

/* Pass mapLoad() the name the file where your map is stored, usually map.dat */

char **mapLoad( char *mapName, uint64_t *mapL, uint64_t *mapW ) ;


#endif
