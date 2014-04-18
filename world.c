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

	size_t numMaps      ;
	size_t numEntities  ;
	size_t numItems     ;
	size_t numPlayers   ;

	short initFlag;
} ; 

#define NUMNPCS(w)    (w->numEntities)
#define NUMPLAYERS(w) (w->numPlayers)
#define NUMITEMS(w)   (w->numItems)
#define NUMMAPS(w)    (w->numMaps)

#define MAPL(w)    (w->mapList)
#define ITEML(w)   (w->itemList)
#define NPCL(w)    (w->entList)
#define PLAYERL(w) (w->playerList)

#define INITFLAG(w) (w->initFlag)

int worldInit( world *w )
{
	int rc = 0 ;

	if( w == NULL ) 
	{
		printf("%s:%d:worldInit(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;

		return -1;
	}

	*w = (world) malloc(sizeof( world ) ) ;

	rc = worldZero( *w ) ;

	if( rc != 0 )
	{
		printf("ERROR:%s:%d:worldInit():worldZero() failed *w=%p\n",
		       __FILE__, __LINE__, (void *) *w) ;
	}

	return 0;
}

int worldZero( world w )
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldZeroize(): was passed NULL\n",
		       __FILE__, __LINE__ ) ;

		return -1;
	}

	NUMNPCS    (w) = 0 ;
	NUMMAPS    (w) = 0 ;
	NUMPLAYERS (w) = 0 ;
	NUMITEMS   (w) = 0 ;

	init_list( & MAPL    ( w ) ) ;
	init_list( & NPCL    ( w ) ) ;
	init_list( & PLAYERL ( w ) ) ;
	init_list( & ITEML   ( w ) ) ;

	return 0;
}

int worldIsInitted( world w )
{
	return ( ( w == NULL ) ? 0 : 1 ) ;
}

int worldDelete(world w)
{
	int rc = 0;

	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldDelete() passed NULL ptr\n",
		       __FILE__, __LINE__ ) ;

		return -1;
	}

	rc = worldClearPlayers( w ) ;

	if( rc != 0)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Players"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w ) ;
	}

	rc = worldClearMaps( w ) ;

	if( rc != 0)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Maps"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldClearEnts( w ) ;

	if( rc != 0)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Entities"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldClearItems( w ) ;

	if( rc != 0)
	{
		printf("ERROR:%s:%d:worldDelete() failed to delete Items"
		       ", rc=%d, w=%p \n",
		       __FILE__, __LINE__, rc, (void *) w);
	}

	rc = worldZero( w ) ;

	if( rc != 0 )
	{
		printf("ERROR:%s:%d:worldDelete():worldZero() failed w=%p\n",
		       __FILE__, __LINE__, (void *) w ) ;
	}

	return 0;
}

int worldClearPlayers( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearPlayers() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

int worldClearMaps( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

int worldClearEnts( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	return 0;
}

int worldClearItems( world w ) 
{
	if( w == NULL )
	{
		printf("ERROR:%s:%d:worldClearMaps() was passed NULL\n",
		       __FILE__, __LINE__);
	}

	

	return 0;
}

int worldAddMap(world w, map m )
{
	status rc;

	if( w == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL w\n");

		return -1;
	}

	if( m == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL m\n");

		return -1;
	}

	rc = insert( & MAPL(w), (void *) m);

	if(rc == OK) return 0;
	
	if(rc == ERROR)
	{
		printf("ERROR:%s:%d:worldAddMap(): insert() failed, "
		       "l=%p, m=%p\n", 
		       __FILE__, __LINE__, (void *) &MAPL(w), (void *) m);
	}

	return -1;
}

int worldDeleteMap(world w, map m ) 
{
	list L = NULL;
	map tempMap = NULL;

	status rc;

	if( w == NULL )
	{
		printf("ERROR:worldAddmap() was passed NULL w\n");

		return -1;
	}

	if(find_key(MAPL(w), m, mapEqual,  & L) == ERROR )
	{
		printf("ERROR:%s:%d:worldDeleteMap(): findkey() failed\n",
		       __FILE__, __LINE__ ) ;
		return -1;
	}

	rc = delete( & L, (generic_ptr *) &tempMap ) ;

	if( rc == ERROR ) return -1;

	return 0;
}

 
