/* Main Game Driver */

#include "user_interface.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main( int argc, char *argv[] )
{

	uint32_t debug = 0 ;
	int i;
	int rc = 0;

	/* check for -d (DEBUG)  */
	for( i = 0; i < argc; ++i ){ 
		if ( strcmp( argv[i], "-d" ) )
			debug = 1 ;
	} 

	rc = interfaceLoop(argv[1] , debug);

	if ( rc != 0 ){
		printf("interfaceLoop returned in error number: %d\n", rc);
		fflush(stdout);
		return -1 ; 
	}

	return 0 ;
}
