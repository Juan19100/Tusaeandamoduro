
/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"
#include "set.h"
#include "enemy.h"
#include "link.h"

typedef struct _Game Game;


/**
  * @brief crea un nuevo juego
  * @author Ignacio
  *
  * game_create guarda memoria para un nuevo juego e inicializa sus parametros
  * @return devuelve puntero a game ya creado, NULL en caso de error
  */
Game* game_create();

/**
  * @brief crea un nuevo juego cargando los datos de un fichero
  * @author profesores de pprog
  *
  * game_create_from_file crea un nuevo juego con los datos de un fichero
  * inicializando el objeto y el jugador en la primera posicion 
  * @param game puntero a game
  * @param filename puntero a char
  * @return OK si todo ha ido bien, o ERROR si ha ocurrido algun error
  */
STATUS game_create_from_file(Game *game, char *filename);

/**
  * @brief actualiza el juego 
  * @author profesores de pprog
  *
  * game_update actualiza el juego segun la 
  *  entrada del jugador
  * @param game puntero a game
  * @param cmd de tipo T_Command
  * @return OK
  */
STATUS game_update(Game *game, T_Command cmd);

/**
  * @brief destruye los datos del juego
  * @author Juan
  *
  * game_destroy destruye los datos del juego destruyendo cada space
  *  y destruyendo tambien al jugador y objeto del juego
  * @param game puntero a game
  * @return OK si todo ha ido bien
  */
STATUS game_destroy(Game *game);

/**
  * @brief de momento no hace nada
  * @author profesores pprog
  *
  * game_is_over de momento no hace nada
  *  
  * @param game puntero a game
  * @return de momento FALSE
  */
BOOL game_is_over(Game *game);

/**
  * @brief imprime los datoss del juego en pantalla
  * @author profesores pprog
  *
  * game_print_data imprime los espacios ademas de la localización del
  *  jugador y del objeto
  * @param  game puntero a game
  * @return nada
  */
void game_print_data(Game *game);

/**
  * @brief busca un espacio en concreto
  * @author Ignacio
  *
  * game_get_space busca el espacio en ej juego que tenga ese id
  *  
  * @param game puntero a game
  * @param id de tipo Id
  * @return NULL si no hay id o si ningun espacio tiene ese id, o devuelve el espacio con el id en cuestion
  */

Space *game_get_space(Game *game, Id id);

/**
  * @brief busca la localizacion del jugador
  * @author Ignacio
  *
  * game_get_player_location busca la localizacion del jugador
  *  
  * @param game puntero a game 
  * @return la localizacion del jugador
  */
Id game_get_player_location(Game *game);

/**
  * @brief busca la localizacion del objeto
  * @author Ignacio
  *
  * game_get_object_location busca la localizacion del objeto recorriendose todos 
  *  los espacios hasta encontrar uno con el id objeto igual que el id del objeto
  * @param game puntero a game 
  * @return el espacio en el que se encuentra el objeto
  */
Id game_get_object_location(Game *game, Id id);

/**
  * @brief busca el ultimo comando usado
  * @author profesores de pprog
  *
  * game_get_last_command busca el ultimo comando introducido por el jugador
  *  
  * @param game puntero a game
  * @return el ultimo comando utilizado
  */
T_Command game_get_last_command(Game *game);
/**
 * @brief añade un objeto al juego
 * @author Ignacio
 * 
 * @param game puntero a game
 * @param id del objeto a añadir
 * @return OK si se ha añadido, ERROR en caso contrario
 */
STATUS game_add_object(Game* game, Id id);

/**
 * @brief devuelce el número de objetos que contiene game
 * @author Ignacio
 * 
 * @param game puntero a game
 * @return número de objetos y -1 en caso de error
 */
int game_get_num_object(Game* game);

/**
 * @brief devuelve el objeto de una posición
 * @author Ignacio
 * 
 * @param game puntero a game
 * @param position posición buscada
 * @return Id del objeto, NO_ID en caso de error 
 */
Id game_get_object(Game* game, int position);

/**
 * @brief devuelve la posicion del player
 * @author Juan
 * 
 * @param game puntero a game
 * @return puntero a player 
 */
Player* game_get_player(Game* game);

/**
 * @brief devuelve el enemy
 * @author Juan
 * 
 * @param game puntero a game
 * @return enemy si todo ha ido bien, NULL en caso de error 
 */
Enemy* game_get_enemy(Game* game);

/**
 * @brief devuelve el id del espacio con id == position
 * 
 * @param game puntero a game
 * @param position tipo int
 * @return Id del espacio
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief añade un espacio al juego
 * @author Ignacio
 * 
 * @param game puntero a game
 * @param space puntero a space
 * @return OK si se ha añadido, ERROR en caso contrario
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief devuelve el espacio dada una posicion
 * @author Ignacio
 * 
 * @param game puntero a game
 * @param position posición del espacio
 * @return el espacio buscado
 */
Space *game_get_space_by_position(Game *game, int position);

/**
 * @brief devuelve el objeto dada una posición
 * @author Juan
 * 
 * @param game puntero a game
 * @param position posicion buscada
 * @return el objeto, y NULL en caso de error 
 */
Object *game_get_object_by_position(Game *game, int position);

/**
 * @brief comprueba el estado del ultimo comando
 * @author Juan
 * 
 * @param game puntero a game
 * @return OK si se ha ejecutado bien, ERROR en caso contrario
 */
STATUS game_get_status_last_cmd(Game *game);

/**
 * @brief añade un link al juego
 * @author
 * 
 * @param game puntero a game 
 * @param l puntero a link
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS game_add_link(Game *game, Link *l);

#endif