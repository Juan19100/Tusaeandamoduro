
#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "space.h"


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
  * @brief añade un espacio al juego
  * @author juan
  *
  * game_add_space añade un espacio al juego, menos si ya contiene el maximo numero de espacios
  *  
  * @param game puntero a game
  * @param space puntero a space
  * @return OK si ha ido todo bien o ERROR si ocure algun error
  */
STATUS game_add_space(Game *game, Space *space);


#endif