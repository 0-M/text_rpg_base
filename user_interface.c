/* user interface API */

#include "user_interface.h"
#include "world.h"


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_WORDS 10

void upperString( char buffer[] ) ;
int  getInput   ( int *item     ) ;
int inputToWords( char *buffers[], int inputLength ) ;


int interfaceLoop( char *mapString, int debugOption )
{
	int inputCode, itemCode;
	/*world WORLD ; */
	
	/***************************/
	/* CODE TABLE - inputCode  */
	/* 0: quit                 */
	/* 1: forward              */
	/* 2: backward             */
	/* 3: left                 */
	/* 4: right                */
	/* 5: take                 */
	/* 6: talk                 */
	/* 666: unrecognized input */
	/*                         */
	/***************************/

	/*worldInit( mapString , &WORLD ) ; */

	while ( ( inputCode = getInput(&itemCode) ) )
	{
		switch ( inputCode ) {
			case 1:
				printf( "GO FORWARD\n" ) ; /* TEMP */
			case 2:
				printf( "GO BACKWARD\n" ) ;
			case 3:
				printf( "GO LEFT\n" ) ;
			case 4:
				printf( "GO RIGHT\n" ) ;
			case 5:
				printf( "TAKING SOMETHING\n" ) ;
			case 6:
				printf( "TALKING THE TALK\n" ) ;
			case 7:
				printf( "SWAG TO THE #YOLO INFINITY\n" ) ;
			case 666:
				printf("input not recognized\n");
		}
	}

	printf( "GAME ENDED BY USER\n\n\n" );

	return 0 ;

}

int getInput( int *item )
{
	int i, buffLength, numWords, returnCode = -1 ;
	char *buffers[MAX_INPUT_WORDS] ;
	
	buffers[0] = malloc( sizeof (char) * BUFSIZ ) ;
	if (buffers[0] == NULL) return -2;

	/* take in a string */
	fgets( buffers[0] , BUFSIZ , stdin ) ;
	buffLength = strlen( buffers[0] ) ;
	
	printf( "DEBUG DATA: main input buffer: %s\nbuffer length: %d \n\n",
		buffers[0], buffLength ) ;

	/* clear newline*/
	if (( buffLength > 0)
	 && ( buffers[0][buffLength-1] == '\n'))
	      buffers[0][buffLength-1] = '\0'; 

	/* turn input into individual words */
	numWords = inputToWords( buffers, buffLength );
	printf("number of words = %d\n\n", numWords);
	/* convert strings to uppercase */
	for ( i = 1 ; i <= numWords ; i++ ){
		upperString(buffers[i]);
		printf("word %d: %s\n", i, buffers[i]);
	}

	if (numWords == 1) {
		/* QUIT */
		if (!(strncmp(buffers[1], "Q", BUFSIZ))
	   	 || !(strncmp(buffers[1], "QUIT", BUFSIZ)))
		{
			returnCode = 0 ;  
		/* FORWARD */
		} else if
		   ( !(strncmp(buffers[1], "W", BUFSIZ))
		  || !(strncmp(buffers[1], "FORWARD", BUFSIZ)))
		{
			returnCode = 1 ;
		/* BACKWARD */
		} else if
		   ( !(strncmp(buffers[1], "S", BUFSIZ))
		  || !(strncmp(buffers[1], "BACKWARD", BUFSIZ)))
		{
			returnCode = 2 ;
		/* LEFT */
		} else if
		   ( !(strncmp(buffers[1], "A", BUFSIZ))
		  || !(strncmp(buffers[1], "LEFT", BUFSIZ)))
		{
			returnCode = 3 ;
		/* RIGHT */
		} else if
		   ( !(strncmp(buffers[1], "D", BUFSIZ))
		  || !(strncmp(buffers[1], "RIGHT", BUFSIZ)))
		{
			returnCode = 4;
		} else {
			returnCode = 666;
		} 
	} else if (numWords == 2) {
		/* TAKE */
		if ( !(strncmp(buffers[1], "T", BUFSIZ))
		  || !(strncmp(buffers[1], "TAKE", BUFSIZ)))
		{
			returnCode = 5 ;
		/* TALK */
		} else if
		   ( !(strncmp(buffers[1], "E", BUFSIZ))
		  || !(strncmp(buffers[1], "TALK", BUFSIZ)))
		{
			returnCode = 6 ;
		/* SWAG */
		} else if
		   (( !(strncmp(buffers[1], "SWAG", BUFSIZ))
		  || !(strncmp(buffers[1], "BASED", BUFSIZ))
		  || !(strncmp(buffers[1], "LIL", BUFSIZ)))
		&& ((!(strncmp(buffers[2], "B", BUFSIZ))
		  || !(strncmp(buffers[2], "GOD", BUFSIZ))
		  || !(strncmp(buffers[2], "MONEY", BUFSIZ)))))
		{
			returnCode = 7 ;
		/* UNRECOGNIZED INPUT */
		} else {
			returnCode = 666 ;
		}
	} else {
		/*0 or 3+ inputs*/
		returnCode = 666;
	}

	for ( i = 0 ; i < numWords ; i++ )
		free( buffers[i] ) ;
	
	return returnCode ; 
}

int inputToWords( char *buffers[], int inputLength )
{
	int i, wordCount = 0, wordState = 0, letterCount = 0;
	char *input, *temp;

	temp = malloc( sizeof ( int ) * BUFSIZ ) ;

	input = buffers[0] ;

	for ( i = 0; i < inputLength ; i++ )
	{
		if ( wordState == 0 ){
			if ( input[i] != ' ' ){
				wordState   = 1 ;
				letterCount = 0 ;
				wordCount++ ;
				if (wordCount >= MAX_INPUT_WORDS){
					printf( "TOO MANY WORDS, LIMIT IS %d",
						MAX_INPUT_WORDS ) ;
					return wordCount ;
				}
				buffers[wordCount] = 
					malloc( sizeof (char) * BUFSIZ ) ;
			}
		} 
		if ( wordState == 1 ){
			if ( input[i] == ' ' ){
				buffers[wordCount][letterCount] = '\0';
				wordState = 0 ;
			} else {
				buffers[wordCount][letterCount] = input[i];
				letterCount++ ;
			}
		}
	}

	free( temp ) ;

	return wordCount ; 
}

void upperString( char buffer[] )
{
	int i; 

	for ( i = 0 ; buffer[i] != '\0' ; i++ )
		buffer[i] = toupper( buffer[i] );
}












