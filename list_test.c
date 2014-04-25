/*
 * list_test.c source for testing linked list implementation
 *
 *
 *
 */

#include <list.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



void fill_list(list *p_L, int32_t length ) ;

/* this is the general format for function ptrs passed to linked list API */

status print_int_from_list( generic_ptr p_int32_t ) ;

int cmp_int32_t( generic_ptr lhs, generic_ptr rhs ) ;

int cmp_int32_t( generic_ptr lhs, generic_ptr rhs )
{
	return ( * ( int32_t * ) lhs ) - ( * ( int32_t * ) rhs ) ;
}

status print_int_from_list(generic_ptr p_int32_t )
{
	if( p_int32_t == NULL )
	{
		printf("data pointer in node is NULL \n");

		return ERROR;
	}
	printf("content of this node is %d\n", 
	       * ( int32_t * ) p_int32_t ) ;

	return OK;
}

int main( int argc, char *argv[] )
{
	list theList;

	list tempList = NULL;

	int32_t list_size, node_to_print, index_to_find ;

	size_t index_ret ;

	status rc ;

	if( argc < 2 )
	{
		printf("usage: %s <list_size> <node_to_print> "
		       "<index_to_find>\n", argv[0] ) ;
	
		return 0;
	}

	list_size = atoi( argv[1] ) ;

	node_to_print = atoi( argv[2] ) ;

	index_to_find = atoi( argv[3] ) ;

	if( node_to_print < 0 )
	{
		printf("cannot access a negative index in this "
		       "linked list implementation \n");

		return 0;
	}

	init_list( & theList ) ;

	init_list( & tempList ) ;

	fill_list( & theList , list_size) ;

	traverse( theList, print_int_from_list ) ;

	printf("the list is %lu long\n", list_length( theList ) ) ;

	if( argc == 2 ) return 0 ;

	list_index( theList, (size_t) node_to_print, & tempList ) ;

	printf("The %dth number in the list is %d\n", node_to_print, 
	       * (int32_t *) DATA( tempList ) ) ;

	if( argc == 3 ) return 0 ;

	rc = find_key_index(theList, (generic_ptr ) &index_to_find, 
			    cmp_int32_t, &index_ret ) ;

	switch(rc)
	{
	case OK:
		printf("found the index %lu from key %d\n", 
		       index_ret, index_to_find ) ;
		break;
	
	case ERROR:
		printf( "no index found\n" ) ;
		break;

	default:
		/* can't get here*/
		printf("shouldn't reach default switch case\n");
	}

	return 0;
}

void fill_list(list *p_L, int32_t length )
{
	status rc;

	int32_t *p ;

	while( length > 0 )
	{
		p = ( int32_t * ) malloc(sizeof( int32_t ) ) ;

		*p = length;

		rc = insert( p_L, (generic_ptr) p) ;
		
		if( rc != OK )
		{
			printf("ERROR from insert(&L=%p, p=%p\n",
			       (void *) *p_L, (void *) p ) ;
		}

		--length ;
	}

}
