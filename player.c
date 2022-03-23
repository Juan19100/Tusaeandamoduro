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
#include "inventory.h"


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
    Inventory *inv; /*!<puntero a Inventory, puntero a todos los objetos que tiene player*/
};

Player* player_create(Id id){
    Player *newPlayer = NULL;

    newPlayer = (Player *) malloc(sizeof (Player));
    
    if (!newPlayer)return NULL;

    newPlayer->name[0] = '\0';
    newPlayer->id = id;
    newPlayer->health = 10;
    newPlayer->inv = inventory_create();
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

STATUS player_add_object(Player *player, Id object_id){
    if(!player || object_id < 0) return ERROR;

    return inventory_add_object(player->inv, object_id);
}

STATUS player_del_object(Player *player, Id object_id){
    if(!player || object_id < 0) return ERROR;

    return inventory_del_object(player->inv, object_id);
}

Id player_get_object_by_position(Player *player, int position){
    if(!player || position < 0) return NO_ID;

    return inventory_get_object(player->inv, position);
}

int player_get_num_objects(Player *player){
    if(!player) return -1;

    return inventory_get_num_objects(player->inv);
}

BOOL player_has_object(Player *player, Id object_id){
    int i = 0;
    if(!player || object_id < 0) return FALSE;

    while(i < player_get_num_objects(player)){
        if(player_get_object_by_position(player,i) == object_id) return TRUE;
        i++;
    }
    return FALSE;
}