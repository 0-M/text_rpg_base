#ifndef __WORLD_H__
#define __WORLD_H__

/* main API for the displayed world */

#include <map.h>
#include <location.h>
#include <player.h>
#include <entity.h>
#include <item.h>

typedef struct item_s *item;
typedef struct entity_s *entity ;
typedef struct player_s *player ;
typedef struct world_s *world;

extern int worldInit( world *w ) ;

extern int worldZero( world w ) ;

extern int worldIsInitted( world w ) ;

extern int worldDelete( world w ) ;

extern int worldCopy( world dest, world src ) ;

extern int worldPrint(world w ) ;

extern int worldEqual(world lhs, world rhs ) ;

extern int worldName( world w, char **str_ptr ) ;

extern int worldAddMap   ( world w, map m ) ;
extern int worldDeleteMap( world w, map m ) ;


extern int worldAddPlayer   ( world w, player p, location l ) ;
extern int worldDeletePlayer( world w, player p ) ;
extern int worldUpdatePlayer(world w, player p, location l ) ;


extern int worldAddEnt   ( world w, entity e, location l ) ;
extern int worldDeleteEnt( world w, entity e ) ;
extern int worldUpdateEnt(world w, entity e, location l ) ;

extern int worldAddItem   ( world w, item i, location l ) ;
extern int worldDeleteItem( world w, item i ) ;
extern int worldUpdateItem( world w, item i, location l ) ;

extern int worldClearPlayers( world w ) ;
extern int worldClearMaps( world w ) ;
extern int worldClearEnts( world w ) ;
extern int worldClearItems( world w ) ;







#endif
