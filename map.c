
char **mapLoad( char *mapName )
{
	char *mapName;
	char **charMap;
	int mapHeight, mapWidth;

	map = mapName
	if (fopen(map, r) == NULL) {
		printf("\n\nMAP FAILED TO LOAD\n\n");
		return NULL ; }

	/* Get height and width from map data file */
	fscanf( "%d\n%d" , map , mapHeight , mapWidth ) ;
	
	charMap = malloc( sizeof ( char * ) * mapHeight ) ; /* rows */

	for (i = 0 ; i < mapHeight ; i++ ) {
		charMap[i] = malloc( sizeof ( char ) * mapWidth ) ; /* cols */
 		fscanf( "%s" , map , charMap[i] ) ;
	}

	fclose( map ) ;

	return charMap ;
}


