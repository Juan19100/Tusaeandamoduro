/** 
 * @brief .c que sirve para todo lo relacionado con 
 * el jugador
 * 
 * @file player.c
 * @author Ignacio
 * @version 2.0 
 * @date 17-2-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "player.h"


/**
 * @brief Player
 *
 * Almacena la información de player.
 */
struct _Player{
    Id id;  /*!<Variable Id, identificador del player*/
    Id location;/*!<Variable Id, identificador de la localizacion*/
    int health; /*!<Variable int, identificador de la vida del player*/
    char name[WORD_SIZE + 1]; /*!<Variable char, nombre del player*/
    Id object_id; /*!<Variable Id, identificador de la id del objeto del jugador*/
};

Player* player_create(Id id){
    Player *newPlayer = NULL;

    newPlayer = (Player *) malloc(sizeof (Player));
    
    if (!newPlayer)return NULL;

    newPlayer->name[0] = '\0';
    newPlayer->id = id;
    newPlayer->health = 10;
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
    if(!player || id < 0) return ERROR;

    player->object_id = id;

    return OK;
}

STATUS player_print(Player* player){
    if(!player) return ERROR;
    fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
    return OK;
}

int player_get_health(Player *player){
    if(!player) return -1;

    return player->health;
}

STATUS player_set_health(Player *player, int health){
    if(!player || health < 0) return ERROR;

    player->health = health;

    return OK;
}