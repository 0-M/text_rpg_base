#include <location.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct location_s {

	char *mapName ;
	size_t x, y   ;
} location_s ;

#define X(l) (l -> x       )
#define Y(l) (l -> y       )
#define N(l) (l -> mapName )

int initLoc( location *l )
{
	int rc = 0;
	
	assert( l != NULL ) ;

	*l = (location) malloc( sizeof( location_s ) ) ;

	rc = zeroLoc( *l ) ;

	if( rc != 0 )
	{
		printf("ERROR:%s:%d:initLoc(): zeroLoc() failed *l=%p\n",
		       __FILE__, __LINE__, (void *) *l ) ;
		fflush( stdout ) ;
		return -1 ;
	}

	return 0;
}

int zeroLoc( location l ) 
{
	if( l == NULL )
	{
		printf( "ERROR:%s:%d:zeroLoc(): was passed NULL\n",
		       __FILE__ , __LINE__ ) ;
		fflush( stdout ) ;
		return -1 ;
	}

	N(l) = NULL ;

	X(l) = 0 ;
	Y(l) = 0 ;

	return 0 ;
}
