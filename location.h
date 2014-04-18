/*
 *
 * location struct which contains where in a world (group of maps) that an
 * item is.
 *
 * mwolf
 */

#include <stddef.h>

#include <globals.h>

typedef struct location_s *location ;

extern status initLoc( location *l ) ;

/* returns 1 if true, 0 if false. */
extern bool isLocInitted( location l ) ;

extern status zeroLoc( location l ) ;

extern status deleteLoc( location l ) ;

extern status setLocX( location l, size_t n ) ;
extern status setLocY( location l, size_t n ) ;

extern status setLocN(location l, const char *n ) ;

extern size_t getLocX( location l ) ;
extern size_t getLocY( location l ) ;

extern const char *getLocName( location l ) ;

extern status printLoc( location l ) ;
