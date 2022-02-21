#ifndef PROYECT_H
#define PROYECT_H

#include "types.h"


typedef struct _Player Player;

/**
  * @brief crea el jugador con el id correspondiente
  * @author Ignacio
  *
  * player_create crea el jugador con el id correspondiente
  *  y los demas valores de player inicializados 
  * @param id de tipo Id
  * @return el jugador ya creado 
  */
Player* player_create(Id id);

/**
  * @brief destruye el jugador 
  * @author Ignacio
  *
  * player_destroy libera la memoria asignada para player
  *  
  * @param player puntero a player
  * @return  OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS player_destroy(Player* player);

/**
  * @brief busca el id del jugador
  * @author Ignacio
  *
  * player_get_id busca el id del jugador en cuestion
  *  
  * @param player puntero a player
  * @return el id del jugador en caso de tenerlo
  */
Id player_get_id(Player* player);

/**
  * @brief asigna el nombre al jugador
  * @author Ignacio
  *
  * player_set_name asigna el nombre(name) al jugador en cuastion
  *  
  * @param player puntero a player
  * @param name cadena de caracteres con el nombre del player
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS player_set_name(Player* player, char* name);

/**
  * @brief busca el nommbre del jugador
  * @author Ignacio
  *
  * player_get_name busca el nombre del jugador
  *  
  * @param  player puntero a player
  * @return el nombre del jugador
  */
const char* player_get_name(Player* player);

/**
  * @brief imprime los datos del jugador
  * @author Ignacio
  *
  * player_print imprime los datos del jugador
  *  
  * @param player puntero a player
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS player_print(Player* player);

/**
  * @brief busca la localizacion del jugador
  * @author Ignacio
  *
  * player_get_location busca la localizacion del jugador
  *  
  * @param player puntero a player
  * @return la localizacion del jugador
  */
Id player_get_location(Player* player);

/**
  * @brief asigna una localizacion al jugador
  * @author Ignacio
  *
  * player_set_location asiga la localizacion indicada al jugador
  *  
  * @param player puntero a player
  * @param id con la localización del jugador
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS player_set_location(Player *player, Id location);

/**
  * @brief busca el id del objeto que tiene el jugador
  * @author Ignacio
  *
  * player_get_object_id busca el id del objeto que tiene el jugador
  *  
  * @param player puntero a player
  * @return el id del objeto del jugador
  */
Id player_get_object_id(Player *player);

/**
  * @brief asigna un id al objeto del jugador
  * @author Ignacio
  *
  * player_set_object_id asigna el id al objeto del jugador
  *  
  * @param player puntero a player 
  * @param id del objeto
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS player_set_object_id(Player *player, Id id);


#endif
