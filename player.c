#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "object.h"
#include "player.h"

struct _Player{
    Id id;
    Id location;
    char name[WORD_SIZE + 1];
    Id object_id;
};

Player* player_create(Id id){
    Player *newPlayer = NULL;

    newPlayer = (Player *) malloc(sizeof (Player));
    
    if (!newPlayer)return NULL;

    newPlayer->name[0] = '\0';
    newPlayer->id = id;
    newPlayer->object_id = NO_ID;
    newPlayer->location = NO_ID;

    return newPlayer;
}

STATUS player_destroy(Player* player){
    if (!player) return ERROR;

    free(player);
    player = NULL;

    return OK;
}

Id player_get_id(Player* player){
    if(!player) return NO_ID;

    return player->id;
}

STATUS player_set_name(Player* player, char* name){
    if(!player || !name) return ERROR;

    if(!strcpy(player->name,name)) return ERROR;

    return OK;
}

const char* player_get_name(Player* player){
    if(!player) return NULL;

    return player->name;
}

Id player_get_location(Player* player){
    if(!player) return NO_ID;
    
    return player->location; 
}

STATUS player_set_location(Player *player, Id location){
    if(!player || location == NO_ID) return ERROR;

    player->location = location;
    
    return OK;
}

Id player_get_object_id(Player *player){
    if(!player) return NO_ID;

    return player->object_id;
}

STATUS player_set_object_id(Player *player, Id id){
    if(!player || id == NO_ID) return ERROR;

    player->object_id = id;

    return OK;
}
