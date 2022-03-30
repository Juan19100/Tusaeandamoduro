
#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "space.h"
#include "link.h"


#include "types.h"

/**
  * @brief carga espacios
  * @author juan
  *
  * game_load_spaces carga los espacios de un fichero en el juego, inicializando
  *  los valores del juego a 0 y luego cargando los datos del archivo
  * @param game puntero a game
  * @param filename puntero a char
  * @return OK si ha ido todo bien o ERROR si ocure algun error
  */
STATUS game_load_spaces(Game *game, char *filename);


/**
  * @brief carga objetos
  * @author juan
  *
  * game_load_objects carga los objetos de un fichero en el juego, inicializando
  *  los valores del juego a 0 y luego cargando los datos del archivo
  * @param game puntero a game
  * @param filename puntero a char
  * @return OK si ha ido todo bien o ERROR si ocure algun error
  */
STATUS game_load_objects(Game *game, char *filename);

/**
 * @brief carga los links desde el fichero
 * @author
 * 
 * @param game puntero a game 
 * @param filename nombre del fichero con la información
 * @return OK si todo va bien, ERROR en caso cotrario
 */
STATUS game_reader_load_links(Game *game, char *filename);

STATUS game_reader_load_player(Game *game, char *filename);

STATUS game_reader_add_player(Game *game, Player *player);

STATUS game_reader_load_enemy(Game *game, char *filename);

STATUS game_reader_add_enemy(Game *game, Enemy *enemy);



#endif