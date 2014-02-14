#include <stdio.h>
#include <stdlib.h>

#include <location.h>

int main(int argc, char *argv[] ) 
{
	location myloc = NULL;
	
	initLoc( &myloc ) ;

	printf(" is initted returned %d\n", isLocInitted( myloc ) ) ;

	

	return 0 ;
}
