#include <world.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * world_s has containers which will have ptr, and location of object on map.
 * mc is a ptr to a map, which will be a variable length array of maps.
 * maps are differentiated by their name, so maps having the same name are
 * not allowed.
 */
typedef struct item_s *item;
typedef struct entity_s *entity ;
typedef struct player_s *player ;

struct world_s {

	map    *maps    ;	
	item   *items   ;
	entity *ents    ;
	player *players ;

	size_t numMaps      ;
	size_t numCreatures ;
	size_t numItems     ;
	size_t numPlayers   ;

	
} ; 

#define NUMNPCS(w)    (w->numCreatures)
#define NUMPLAYERS(w) (w->numPlayers)
#define NUMITEMS(w)   (w->numItems)
#define NUMMAPS(w)    (w->numMaps)

#define MAPP(w)    (w->maps)
#define ITEMP(w)   (w->items)
#define NPCP(w)    (w->ents)
#define PLAYERP(w) (w->players)

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

	NUMNPCS    (w) = 0;
	NUMMAPS    (w) = 0;
	NUMPLAYERS (w) = 0;
	NUMITEMS   (w) = 0;

	MAPP   (w) = NULL;
	ITEMP  (w) = NULL;
	NPCP   (w) = NULL;
	PLAYERP(w) = NULL;

	return 0;
}
