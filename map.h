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

extern int mapZero( map m ) ;

/*
 * mapIsInitted returns 1 if map is non-null, 0 if map is null. for use in 
 * if statements.
 */

extern int mapIsInitted( map m ) ;

/*
 * Pass mapLoad() the name of a file where a map is stored
 * 
 *
 * */

extern int mapLoad( map m, const char *fileName ) ;

extern int mapSave( map m, const char *fileName ) ;

/*
 * mapCopy() creates a completely new map object which with separate pointers
 * so deleting one will not muck up another
 */

extern int mapCopy( map dest, map src ) ;

extern int mapEqual( map lhs, map rhs ) ;

extern int mapWidth( map m, size_t *w ) ;

extern int mapHeight( map m, size_t *h ) ;

/* mapName() sets *n to point to a copy of the internal name of the map */

extern int mapName( map m, char **str_ptr ) ;

extern int mapNameLen(map m, size_t *nameLen ) ;

extern int mapPrint( map m ) ;

/* mapDoublebuffer will take a ptr to a NULL and give it content equal to
 * the data inside the double array in the map object.
 *
 * if it is passed an already allocated double buffer it will erase the content
 * then free old memory, and ask for new memory for the new map.
 */
extern int mapDoubleBuffer( map m, char ***BUFFER, size_t *h ) ;

extern int freeDoubleBuffer( char **BUFFER, size_t h ) ;

extern int mapSingleBuffer( map m, size_t line, char **BUFFER ) ;

#endif
