#include <location.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct location_s {

	char *mapName ;
	size_t x, y   ;
} location_s ;

#define X(l) (l -> x       )
#define Y(l) (l -> y       )
#define N(l) (l -> mapName )

status initLoc( location *l )
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

	return OK;
}

bool isLocInitted( location l )
{
	return ((l == NULL ) ? TRUE : FALSE) ;
}

status zeroLoc( location l )
{
	if( l == NULL )
	{
		printf( "ERROR:%s:%d:zeroLoc(): was passed NULL\n",
		       __FILE__ , __LINE__ ) ;
		fflush( stdout ) ;
		return ERROR ;
	}

	N(l) = NULL ;

	X(l) = 0 ;
	Y(l) = 0 ;

	return OK;
}

int zeroLocFree( location l ) 
{
	if( l == NULL )
	{
		printf( "ERROR:%s:%d:zeroLocFree(): was passed NULL\n",
		       __FILE__ , __LINE__ ) ;
		fflush( stdout ) ;
		return ERROR ;
	}

	free( N(l) ) ;

	N(l) = NULL ;

	X(l) = 0 ;
	Y(l) = 0 ;

	return OK ;
}

int setLocX( location l, size_t n )
{
	if( l == NULL )
	{
		printf("%s:%d:setLocX(): passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush(stdout);
		return ERROR;
	}

	X(l) = n ;

	return OK;
}

int setLocY( location l, size_t n )
{
	if( l == NULL )
	{
		printf("%s:%d:setLocY(): passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush(stdout);
		return ERROR;
	}

	Y(l) = n ;

	return OK;
}

int setLocN(location l, const char *n )
{
	if( n == NULL )
	{
		printf("%s:%d:setLocN(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush( stdout ) ;
		return ERROR ;
	}

	if( N(l) != NULL ) free( N(l) ) ;

	N(l) = (char *) malloc( sizeof( char ) * strlen( n ) ) ;
	
	strcpy( N(l), n ) ;

	return OK ;
}

size_t getLocX( location l )
{
	if( l == NULL )
	{
		printf("%s:%d:getLocX(): passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush(stdout);
		return 0;
	}

	return X(l) ;
}

size_t getLocY( location l )
{
	if( l == NULL )
	{
		printf("%s:%d:getLocY(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush(stdout);
		return 0;
	}

	return Y(l) ;
}

const char *getLocName( location l )
{
	if( l == NULL )
	{
		printf("%s:%d:getLocN(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush( stdout ) ;
		return NULL ;
	}

	return N(l);
}

int deleteLoc( location l )
{
	int rc;

	if( l == NULL ){
		printf("%s:%d:deleteloc(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush(stdout) ;
		return ERROR;
	}

	rc = zeroLocFree( l ) ;

	if( rc != 0 )
	{
		printf("WARNING:%s:%d:deleteLoc(): zeroLocFree() failed."
		       "may be causing a memory leak.\n",
		       __FILE__, __LINE__ ) ;
	}

	free( l ) ;

	return OK;
}

int printLoc( location l )
{
	if( l == NULL )
	{
		printf("%s:%d:printLoc(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;
		fflush( stdout ) ;
		return ERROR ;
	}

	printf("Name: %s x:%zu y:%zu\n", N(l), X(l), Y(l) ) ;

	return OK ;
}
