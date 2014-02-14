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

#define DEFAULTSLICE 3

int main(int argc, char *argv[] )
{
	int rc;

	size_t i;

	size_t w,h;

	size_t whichslice = DEFAULTSLICE;

	size_t doubleBufferH;

	char *name = NULL;

	char **mybuf = NULL;

	char *mapslice = NULL;

	map mymap = (( map ) NULL);

	if(argc < 2){

		printf("usage: %s <map file to test>\n", argv[0] ) ;

		return -1;
	}

	if( argc > 2){
		whichslice = (size_t) atoi( argv[2] ) ;
	}

	rc = mapInit( &mymap );	        assert( rc == 0 );

	rc = mapPrint( mymap );	        assert( rc == 0 );

	rc = mapLoad( mymap, argv[1] );	assert( rc == 0 );

	rc = mapPrint( mymap );	        assert( rc == 0 );

	rc = mapHeight(mymap, &h );     assert( rc == 0 );

	rc = mapWidth(mymap, &w );      assert( rc == 0 );
	
	rc = mapName(mymap, &name );    assert( rc == 0 );

	printf("map hxW: %zu x %zu name: %s\n", 
	       h, w, name ) ;

	printf("\n");

	rc = mapDoubleBuffer( mymap, &mybuf, &doubleBufferH ); 

	assert( rc == 0 ) ;

	printf("printing the map after copying via mapDoubleBuffer()\n");

	for(i = 0; i < h; ++i )
	{
		printf("%s\n", mybuf[i]);
	}

	rc = mapSingleBuffer(mymap, whichslice, &mapslice ); assert( rc == 0 ) ;

	printf("printing the %zuth slice of the map\n", whichslice ) ;

	printf("%s\n", mapslice ) ;

	free( name );

	return 0;
}
