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

typedef struct _Game
{
  Id player_location;
  Id object_location;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;


/**
  * @brief It creates a new game
  * @author 
  *
  * game_create allocates memory for a new game
  *  and initializes its members
  * @param game pointer to the new game
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_create(Game *game);

/**
  * @brief It creates a new space
  * @author
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
STATUS game_create_from_file(Game *game, char *filename);
STATUS game_update(Game *game, T_Command cmd);
STATUS game_destroy(Game *game);
BOOL game_is_over(Game *game);
void game_print_data(Game *game);
Space *game_get_space(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game);
T_Command game_get_last_command(Game *game);
#endif
