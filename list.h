#ifndef __EW_LIST__
#define __EW_LIST__

/*
 * polymorphic single linked list implementation based on Esakov and Weiss
 * Textbook
 *
 */

#include <globals.h>
#include <stddef.h>

typedef struct node node, *list;
struct node 
{ 
	generic_ptr datapointer; 
	list next; 
} ;

#define DATA( L ) ( ( L ) -> datapointer )
#define NEXT( L ) ( ( L ) -> next )

extern status allocate_node( list *p_L, generic_ptr data ) ;
extern void free_node( list *p_L ) ;

extern status init_list( list *p_L ) ;
extern bool empty_list( list L ) ;
extern status insert( list *p_L, generic_ptr data ) ;
extern status append( list *p_L, generic_ptr data ) ;
extern status delete( list *p_L, generic_ptr *p_data ) ;
extern status delete_node( list *p_L, list node ) ;

extern status traverse( list L, status (*p_func_f) () );
extern status find_key( list L, generic_ptr key, int (*p_cmp_f)(), list *p_keynode ) ;

extern list list_iterator( list L, list lastreturn ) ;
extern void destroy( list *p_L, void (*p_func_f)() );

/* 
 * Extension functions which allow access by index implemented by mwolf
 * 
 * works like array indexes: a list with 10 elements (10 long) can be accessed 
 * from 0 to 9 and list_length will return 10. 
 *
 * list_index_safe() will fail if the index passed is greater than the list
 * length.
 *
 * list_index() will set p_L to the last element in the list if index passed
 * is greater than list length.
 */

extern status list_index( list L, size_t index, list *p_L ) ;

extern status list_index_safe( list L, size_t index, list *p_L ) ;

extern size_t list_length( list L ) ;

#endif
