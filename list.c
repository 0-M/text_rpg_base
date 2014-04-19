#include <stdlib.h>
#include <list.h>
 
status allocate_node( list *p_L, generic_ptr data ) {

	list L = (list)malloc( sizeof( node ) ) ;
	
	if( L == NULL ) return ERROR ;
	
	*p_L = L ;
	DATA(L) = data ;
	NEXT(L) = NULL ;
	return OK ;
	
}

void free_node( list *p_L ) {
	
	free( *p_L ) ;
	*p_L = NULL ;
	
}

status init_list( list *p_L ) {
	
	*p_L = NULL ;
	return OK ;
	
}

bool empty_list( list L ) {
	
	return (L == NULL ) ? TRUE : FALSE ;
	
}

status insert( list *p_L, generic_ptr data ) {
	
	list L ;
	
	if( allocate_node( &L, data ) == ERROR ) return ERROR ;
	NEXT(L) = *p_L ;
	*p_L = L ;
	return OK ;
	
}

status append( list *p_L, generic_ptr data ) {
	
	list L, tmplist ;
	
	if( allocate_node( &L, data) == ERROR ) return ERROR ;
	
	if( empty_list( *p_L ) == TRUE ) *p_L = L ;
	else {
		for( tmplist = *p_L ; NEXT(tmplist) != NULL ; tmplist = NEXT(tmplist) ) ;
		NEXT(tmplist) = L ;
	}
	
	return OK ;
	
}

status delete( list *p_L, generic_ptr *p_data ) {
	
	if( empty_list( *p_L ) ) return ERROR ;
	
	*p_data = DATA( *p_L ) ;
	return delete_node( p_L, *p_L ) ;
	
}

status delete_node( list *p_L, list n ) {
	
	if( empty_list( *p_L ) == TRUE ) return ERROR ;
	
	if( *p_L == n ) *p_L = NEXT( *p_L ) ;
	else {
		
		list L ;
		for( L = *p_L; L != NULL && NEXT(L) != n; L = NEXT(L) ) ;
		
		if( L == NULL ) return ERROR ;
		
		NEXT(L) = NEXT(n) ;
		
	}
	
	free_node( &n ) ;

	return OK ;
	
}

status traverse( list L, status (*p_func_f) () ) {
	
	if( empty_list( L ) ) return OK ;
	
	if( (*p_func_f)(DATA(L)) == ERROR ) return ERROR ;
	
	else return traverse( NEXT(L), p_func_f ) ;
	 
}

status find_key( list L, generic_ptr key, int (*p_cmp_f)(), list *p_keynode ) {
	
	list curr = NULL ;
	
	while( ( curr = list_iterator( L, curr ) ) != NULL ) {
		
		if( (*p_cmp_f)(key, DATA(curr)) == 0 ) {
			
			*p_keynode = curr ;
			return OK ; 
			
		}
		
	}
	return ERROR ;
	
} 

list list_iterator( list L, list lastreturn ) 
{	
	return ( lastreturn == NULL ) ? L : NEXT( lastreturn ) ;	
}

void destroy( list *p_L, void (*p_func_f)() ) {
	
	if( empty_list(*p_L) == FALSE ) {
		
		destroy( &NEXT(*p_L), p_func_f) ;
		if( p_func_f != NULL ) (*p_func_f)(DATA(*p_L)) ;
		free_node( p_L ) ;
		
	}
	
}

bool equal( list L1, list L2, int (*p_cmp_f)() ) {
	
	list curr1 = NULL, curr2 = NULL ;
	int n1 = 0, n2 = 0 ;
	
	while( ( curr1 = list_iterator( L1, curr1 ) ) != NULL ) n1++ ;
	while( ( curr2 = list_iterator( L2, curr2 ) ) != NULL ) n2++ ;
	if( n1 != n2 ) return FALSE ;
	
	curr1 = NULL ;
	curr2 = NULL ;
	
	while( ( curr1 = list_iterator( L1, curr1 ) ) != NULL && ( curr2 = list_iterator( L2, curr2 ) ) != NULL ) {
		
		if( (*p_cmp_f)( DATA(curr1), DATA(curr2) ) != 0 ) return FALSE ;
		
	}
	
	return TRUE ;
	
}

size_t list_length( list L )
{
	size_t length = 0;

	list curr = NULL ;

	while( ( curr = list_iterator( L, curr ) ) != NULL )
	{
		++length ;
	}
	
	return length;
}

extern status list_index_safe( list L, size_t index, list *p_L )
{
	if( index >= list_length( L ) ) return ERROR;

	return list_index( L, index, p_L ) ;
}

extern status list_index( list L, size_t index, list *p_L )
{
	/* set curr to be the 0th node in the list, so that if index 0 is given
	 * return will occur without loop.
	 */

	list curr = list_iterator(L, NULL ) ;

	while( index > 0 )
	{
		curr = list_iterator( L, curr ) ;

		--index ;
	}

	*p_L = curr ;
	
	return OK;
}
