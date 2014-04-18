#ifndef __EW_LIST__
#define __EW_LIST__

typedef enum { OK, ERROR } status ;
typedef enum { FALSE=0 , TRUE=1 } bool ;
typedef void *generic_ptr ;

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

#endif
