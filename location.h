/*
 *
 * location struct which contains where in a world (group of maps) that an
 * item is.
 *
 * mwolf
 */

#include <stddef.h>

typedef struct location_s *location ;

extern int initLoc( location *l ) ;

/* returns 1 if true, 0 if false. */
extern int isLocInitted( location l ) ;

extern int zeroLoc( location l ) ;

extern int deleteLoc( location l ) ;

extern int setLocX( location l, size_t n ) ;
extern int setLocY( location l, size_t n ) ;

extern int setLocN(location l, const char *n ) ;

extern size_t getLocX( location l ) ;
extern size_t getLocY( location l ) ;

extern const char *getLocN( location l ) ;

extern int printLoc( location l ) ;
