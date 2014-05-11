#include <list.h>
#include <globals.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fill_list( list *p_L,  int n ) ;

status print_int(generic_ptr p ) ;

status print_int(generic_ptr p )
{
	if( p == NULL ) return ERROR ;

	printf("content is %d\n", *(int *) p);

	return OK;
}

int main(int argc, char *argv[] )
{
	list theList ;

	int n, n2, *stuck_int ;

	assert( argc > 2 ) ;

	if( argc < 3 )
	{
		printf("usage: %s <length of list> <num_to_delete>\n");
		return 0;
	}

	n = atoi( argv[1] ) ;

	n2 = atoi( argv[2] ) ;

	if( n2 >= n )
	{
		printf("length of list must be greater than "
		       "index to delete\n" ) ;
		return 0;
	}
	
	assert(OK == init_list( &theList ) ) ;
	
	assert( OK == fill_list(&theList, n) ) ;

	assert( OK == traverse(theList, print_int ) ) ;

	assert( OK == delete_by_index( &theList, (generic_ptr) &stuck_int, 
				       (size_t) n2 ) ) ;

	assert( *stuck_int == n2 ) ;

	assert( OK == traverse(theList, print_int ) ) ;

	return 0;
}

int fill_list(list *p_L,  int n )
{
	int *ip;

	while( n > -1 )
	{
		ip = (int *) malloc(sizeof(int)) ;

		*ip = n;

		insert( p_L, (generic_ptr) ip ) ;

		--n ;
	}
}
