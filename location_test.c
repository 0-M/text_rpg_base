#include <stdio.h>
#include <stdlib.h>

#include <location.h>

int main() 
{
	location myloc = NULL;
	
	initLoc( &myloc ) ;

	printf(" is initted returned %d\n", isLocInitted( myloc ) ) ;

	setLocX( myloc, 12 ) ;

	setLocY( myloc, 31 ) ;

     	setLocN( myloc, "amapname" ) ;

	printLoc( myloc ) ;

	return 0 ;
}
