#include <map.h>

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char **mapLoad( char *mapName, uint64_t *mapL, uint64_t *mapW )
{
	uint64_t i = 0;

	char **charMap = NULL;
	uint64_t mapHeight = 0, mapWidth = 0;
	
	FILE *mapFilePtr = NULL;

	if(mapName == NULL){

		printf("%s:%d:mapLoad(): parameter mapName passed is NULL\n",
		       __FILE__,__LINE__);
		fflush(stdout);
		return NULL;
	}

	mapFilePtr = fopen(mapName, "r");

	if (mapFilePtr == NULL) {
		printf("\n\nERROR: fopen failed\n\n");
		fflush(stdout);
		return NULL ; 
	}
	
	/* Get height and width from map data file */

	fscanf( mapFilePtr , "%lu\n%lu", &mapHeight, &mapWidth ) ;

	*mapL = mapHeight;
	*mapW = mapWidth;

	/* Malloc double array for map length */

	charMap = (char **) malloc( sizeof ( char * ) * mapHeight ) ; /* rows */

	for (i = 0 ; i < mapHeight ; i++ ) {
		charMap[i] = malloc( sizeof ( char ) * mapWidth ) ; /* cols */
 		fscanf( mapFilePtr, "%s" , charMap[i] ) ;
	}

	fclose( mapFilePtr ) ;

	return charMap ;
}
