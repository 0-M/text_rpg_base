/*
 * basic map object testing binary by mwolf
 *
 * uses assert.h. FIXME: write personal debugging macros.
 *
 */

#include <map.h>

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int main(int argc, char *argv[] )
{
	int i, rc;

	size_t w,h;

	char *name = NULL;

	map mymap = (( map ) NULL);

	if(argc != 2){

		printf("usage: %s <map file to test>\n", argv[0] ) ;

		return -1;
	}

	rc = mapInit( &mymap );

	assert( rc == 0 );

	rc = mapPrint( mymap );

	assert( rc == 0 );

	rc = mapLoad( mymap, argv[1] );

	assert( rc == 0 );

	rc = mapPrint( mymap );

	assert( rc == 0 );

	rc = mapHeight(mymap, &h ) ;

	assert( rc == 0 );

	rc = mapWidth(mymap, &w ) ;

	assert( rc == 0 );
	
	rc = mapName(mymap, &name ) ;

	assert( rc == 0 );

	printf("map hxW: %zu x %zu name: %s\n", 
	       h, w, name ) ;

	free( name );

	return 0;
}
