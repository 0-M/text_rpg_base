#ifndef __MAP_H__
#define __MAP_H__

/* API for maps */

#include <stddef.h>

typedef struct map_s *map;

/* Pass mapInit() a pointer to a null pointer.  mapInit() will return an
 * initialized map.
 */

extern int mapInit( map *m ) ;

/*
 * mapDelete() frees the map, and any memory that might 
 * be held in the data structure
 */

extern int mapDelete( map m ) ;

/*
 * Zeroize() sets all values inside the map to NULL or 0 depending if they
 * are pointers or integral types
 */

extern int mapZeroize( map m ) ;

/*
 * mapIsInitted returns 1 if map is non-null, 0 if map is null. for use in 
 * if statements.
 */

extern int mapIsInitted( map m ) ;

/* Pass mapLoad() the name of a file where a map is stored */

extern int mapLoad( map m, const char *fileName ) ;

extern int mapSave( map m, const char *fileName ) ;


extern int mapCopy( map dest, map src ) ;

extern int mapEqual( map lhs, map rhs ) ;

extern int mapWidth( map m, size_t *w ) ;

extern int mapHeight( map m, size_t *h ) ;

extern int mapName( map m, char *n ) ;

extern int mapNameLen(map m, size_t *nameLen ) ;

extern int mapPrint( map m ) ;

#endif
