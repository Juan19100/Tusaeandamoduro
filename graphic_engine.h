/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief crea el motor grafico
  * @author Profesores pprog
  *
  * graphic_engine_create crea el motor grafico del juego
  *  
  * @param 
  * @return ge o NULL
  */
Graphic_engine *graphic_engine_create();

/**
  * @brief destruye el motor grafico
  * @author profesores pprog
  *
  * graphic_engine_destroy destruye el motor grafico del juego
  *  
  * @param ge puntero a graphic_engine
  * @return nada
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief imprime el juego
  * @author profesores pprog 
  *
  * graphic_engine_paint_game imprime el juego
  *  
  * @param ge puntero a graphic_engine
  * @param game puntero a la estructura juego
  * @return  nada
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
  * @brief escribe un comando en el juego
  * @author profesores pprog 
  *
  * graphic_engine_write_command escribe un comando en la pantalla
  *  
  * @param ge puntero a graphic_engine
  * @param str cadena de caracteres
  * @return nada
  */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif