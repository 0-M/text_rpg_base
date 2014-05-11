#include <world.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <list.h>

/*
 * world_s has lists which will have ptr, and location of object on map.
 * maps are differentiated by their name, so maps having the same name are
 * not allowed.
 */


struct world_s {

	list mapList    ;
	list itemList   ;
	list entList    ;
	list playerList ;

	list itemLocs   ;
	list entLocs    ;
	list playerLocs ;

	size_t numMaps      ;
	size_t numEntities  ;
	size_t numItems     ;
	size_t numPlayers   ;

	short initFlag;
} ; 

#define NUMNPCS(w)    ( ( w ) -> numEntities )
#define NUMPLAYERS(w) ( ( w ) -> numPlayers  )
#define NUMITEMS(w)   ( ( w ) -> numItems    )
#define NUMMAPS(w)    ( ( w ) -> numMaps     )

#define MAPL(w)    ( ( w ) ->    mapList )
#define ITEML(w)   ( ( w ) ->   itemList )
#define NPCL(w)    ( ( w ) ->    entList )
#define PLAYERL(w) ( ( w ) -> playerList )

#define INITFLAG(w) ( ( w ) -> initFlag )

status worldInit( world *w )
{
	status rc = 0 ;

	if( w == NULL ) 
	{
		printf("%s:%d:worldInit(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;

		return ERROR;
	}

	*w = (world) malloc(sizeof( world ) ) ;

	rc = worldZero( *w ) ;

	if( rc != 0 )
	{
		printf("ERROR:%s:%d:worldInit():worldZero() failed *w=%p\n",
		       __FILE__, __LINE__, (void *) *w) ;
	}

	return OK;
}

status worldZero( world w )
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldZeroize(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;

		return ERROR;
	}

	NUMNPCS    ( w ) = 0 ;
	NUMMAPS    ( w ) = 0 ;
	NUMPLAYERS ( w ) = 0 ;
	NUMITEMS   ( w ) = 0 ;

	init_list( & MAPL    ( w ) ) ;
	init_list( & NPCL    ( w ) ) ;
	init_list( & PLAYERL ( w ) ) ;
	init_list( & ITEML   ( w ) ) ;

	return OK;
}

bool worldIsInitted( world w )
{
	return ( ( w == NULL ) ? TRUE : FALSE ) ;
}

status worldDelete(world w)
{
	status rc;

	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldDelete() passed NULL ptr\n",
		       __FILE__, __LINE__ ) ;

		return ERROR;
	}

	rc = worldClearPlayers( w ) ;

	if( rc != OK)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Players"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w ) ;
	}

	rc = worldClearMaps( w ) ;

	if( rc != OK)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Maps"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldClearEnts( w ) ;

	if( rc != OK)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Entities"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldClearItems( w ) ;

	if( rc != OK)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Items"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldZero( w ) ;

	if( rc != OK )
	{
		printf("ERROR:%s:%d:worldDelete():worldZero() failed w=%p\n",
		       __FILE__, __LINE__, (void *) w ) ;
	}

	return OK;
}

status worldClearPlayers( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearPlayers() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

status worldClearMaps( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

status worldClearEnts( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

status worldClearItems( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	

	return 0;
}

status worldAddMap(world w, map m )
{
	status rc;

	if( w == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL w\n");

		return ERROR;
	}

	if( m == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL m\n");

		return ERROR;
	}

	rc = insert( & MAPL(w), (void *) m);

	if(rc == OK) return 0;
	
	if(rc == ERROR)
	{
		printf("ERROR:%s:%d:worldAddMap(): insert() failed, "
		       "l=%p, m=%p\n", 
		       __FILE__, __LINE__, (void *) &MAPL(w), (void *) m);
	}

	return ERROR;
}

status worldDeleteMap(world w, map m ) 
{
	map tempMap = NULL;

	size_t key;

	status rc;

	if( w == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL w\n");

		return ERROR;
	}

	rc = find_key_index( MAPL(w), m, mapEqual, & key );

	if( rc == ERROR )
	{
		printf("ERROR:%s:%d:worldDeleteMap(): findkey() failed\n",
		       __FILE__, __LINE__ ) ;
		return ERROR;
	}

	rc = delete_by_index( & MAPL( w ), (generic_ptr *) &tempMap, key ) ;

	return OK ;
}

extern status worldDeleteMapContents(world w, map m )
{
	

	return OK;
}
