#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include <globals.h>
#include <map.h>
#include <location.h>
#include <player.h>
#include <entity.h>
#include <item.h>

typedef struct item_s *item;
typedef struct entity_s *entity ;
typedef struct player_s *player ;
typedef struct world_s *world;

extern status worldInit( world *w ) ;

extern status worldZero( world w ) ;

extern bool worldIsInitted( world w ) ;

extern status worldDelete( world w ) ;

extern status worldCopy( world dest, world src ) ;

extern status worldPrint(world w ) ;

extern status worldEqual(world lhs, world rhs ) ;

extern status worldName( world w, char **str_ptr ) ;

extern status worldAddMap   ( world w, map m ) ;
extern status worldDeleteMap( world w, map m ) ;

/* helper function for worldDeleteMap() which will iterate through other lists
 * and delete locations of objects originally in the deleted map
 */
extern status worldDeleteMapContents( world w, map m ) ;

extern status worldAddPlayer   ( world w, player p, location l ) ;
extern status worldDeletePlayer( world w, player p ) ;
extern status worldUpdatePlayer(world w, player p, location l ) ;


extern status worldAddEnt   ( world w, entity e, location l ) ;
extern status worldDeleteEnt( world w, entity e ) ;
extern status worldUpdateEnt(world w, entity e, location l ) ;

extern status worldAddItem   ( world w, item i, location l ) ;
extern status worldDeleteItem( world w, item i ) ;
extern status worldUpdateItem( world w, item i, location l ) ;

/* ClearMaps() will also delete all locations for items*/
extern status worldClearMaps( world w ) ;
extern status worldClearPlayers( world w ) ;
extern status worldClearEnts( world w ) ;
extern status worldClearItems( world w ) ;







#endif
