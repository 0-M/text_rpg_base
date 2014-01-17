/* Main Game Driver */

#include "user_interface.h"


int main( int argc, char *argv[] )
{

	int debug = 0 ;

	/* check for -d (DEBUG)  */
	if ( argc > 2 ){
		if ( argv[1] == "-D" )
		debug = 1 ;
	} 

	if ( interfaceLoop( argv[1] , debug) != 0 )
		return -1 ; 

	return 0 ;
}
