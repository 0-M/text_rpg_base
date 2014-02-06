#include <world.h>
#include <stdio.h>

int worldInit( char *mapString, world *WORLD )
{
	if(mapString == NULL){

		printf("%s:%d: in worldInit: mapString is NULL\n",
		       __FILE__, __LINE__);
		fflush(stdout);
		return -1;
	}

	if(WORLD == NULL){

		printf("%s:%d: in worldInit: WORLD is NULL\n",
		       __FILE__, __LINE__);
		fflush(stdout);
		return -1;
	}	

	printf("%s:%d: in worldInit: WARNING: FUNCTION DOES NOTHING YET\n",
	       __FILE__, __LINE__);

	return 0;
}
