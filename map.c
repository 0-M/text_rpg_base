#include <map.h>

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char **mapLoad( char *mapName )
{
	uint64_t i = 0;

	char *map = NULL;
	char **charMap = NULL;
	uint64_t mapHeight = 0, mapWidth = 0;
	
	FILE *mapFilePtr = NULL;

	map = mapName;
	
	mapFilePtr = fopen(map, "r");

	if (mapFilePtr == NULL) {
		printf("\n\nERROR: MAP FAILED TO LOAD\n\n");
		fflush(stdout);
		return NULL ; 
	}
	
	/* Get height and width from map data file */

	fscanf( mapFilePtr , "%lu\n%lu", &mapHeight, &mapWidth ) ;

	/* Malloc double array for map length */

	charMap = (char **) malloc( sizeof ( char * ) * mapHeight ) ; /* rows */

	for (i = 0 ; i < mapHeight ; i++ ) {
		charMap[i] = malloc( sizeof ( char ) * mapWidth ) ; /* cols */
 		fscanf( mapFilePtr, "%s" , charMap[i] ) ;
	}

	fclose( mapFilePtr ) ;

	return charMap ;
}


