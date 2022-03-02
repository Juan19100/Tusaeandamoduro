
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

STATUS game_load_objects(Game *game, char *filename);



#endif