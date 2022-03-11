/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "game.h"
#include "game_reader.h"
#include "player.h"
#include "object.h"
#include "set.h"
#include "enemy.h"

#define MAX_RAND 9

/**
   Private functions
*/
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id space_id, Id object_id);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);
void game_command_right(Game *game);
void game_command_left(Game *game);
STATUS game_command_attack(Game *game);

/**
   Game interface implementation
*/

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player= player_create(11);
  game->enemy = enemy_create(31);
  for(i=0; i < MAX_SET; i++){
    game->set[i] = NULL;
  }
  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{
  int i;

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  for(i=0; i < MAX_SET; i++){
    game_set_object_location(game, game_get_space_id_at(game, 0), set_get_object(game->set[i],0));
  }
  

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }
  player_destroy(game->player);
  enemy_destroy(game->enemy);
  for(i=0; i < MAX_SPACES && game->set[i] != NULL; i++){
    set_destroy(game->set[i]);
  }

  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  return player_set_location(game->player, id);
}

STATUS game_set_enemy_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  return enemy_set_location(game->enemy, id);
}

STATUS game_set_object_location(Game *game, Id space_id, Id object_id)
{
  Space *location = NULL;

  if (space_id == NO_ID || object_id == NO_ID)
  {
    return ERROR;
  }

  location = game_get_space(game, space_id);
  space_set_object(location, object_id);

  return OK;
}

Id game_get_player_location(Game *game)
{
  if(!game) return NO_ID;

  return player_get_location(game->player);
}

Id game_get_enemy_location(Game *game)
{
  if(!game) return NO_ID;

  return enemy_get_location(game->enemy);
}

Id game_get_object_location(Game *game, Id id)
{
  int i, j;

  if(!game) return NO_ID;

  /*for(i = 0; i < MAX_SPACES; i++){
    if(space_get_object(game->spaces[i]) == object_get_id(game->object)){
      return space_get_id(game->spaces[i]);
    }
  }*/

  for(i=0; i < MAX_SPACES; i++){
    for(j=0; j < 10/*MAX_SET*/; j++){
      if(space_get_object(game->spaces[i], j) == id){
        return space_get_id(game->spaces[i]);
      }
    }
  }
  
  return NO_ID;
}

STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    case RIGHT:
      game_command_right(game);
      break;

    case LEFT:
      game_command_left(game);
      break;

    case ATTACK:
      game_command_attack(game);
      break;

    default:
      break;
  }

  return OK;
}

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  for(i=0; i < MAX_SET; i++){
    set_print(game->set[i]);
  }
  player_print(game->player);
}

BOOL game_is_over(Game *game)
{
  if(player_get_health(game->player)==0)return FALSE;

  return FALSE;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game)
{
}

void game_command_exit(Game *game)
{
  
}

void game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_command_take(Game *game)
{
  Id object_location;
  long object_id;

  if(!game) return;

  scanf(" 0%ld", &object_id);
  if (object_id == NO_ID) return;
  
  object_location = game_get_object_location(game, object_id);
  if(object_location == NO_ID) return;
  
  if(object_location != player_get_location(game->player)) return;/*deben estar en la misma casilla*/

  player_set_object_id(game->player, object_id);

  space_set_object(game_get_space(game, object_location), NO_ID);
}

void game_command_drop(Game *game)
{
  Id object_id, space_id;

  if(!game) return;
  
  object_id = player_get_object_id(game->player);
  if(object_id == NO_ID) {
    return;
  }
  space_id = player_get_location(game->player);

  if(space_set_object(game_get_space(game, space_id), object_id) == ERROR) return;

  if(player_set_object_id(game->player, NO_ID) == ERROR) return;
}

void game_command_right(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_command_left(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

STATUS game_command_attack(Game *game)
{
  int x=0;
  srand(time(NULL));

  if (game_get_player_location(game) != game_get_enemy_location(game)){
    printf("el enemigo no esta en el mismo espacio que el jugador");
    return ERROR; 
  }
  
  if(enemy_get_health(game->enemy)<=0){
    printf("el enemigo ya esta a 0 de vida");
    return ERROR;
  }

  x = rand() % MAX_RAND;

  if(x <= 4){
    player_set_health(game->player, (player_get_health(game->player)-1));
    if(player_get_health(game->player)==0){
        if(game_is_over(game)==FALSE);
        return OK;
    }
    return OK;
  }

  else {
    enemy_set_health(game->enemy, (enemy_get_health(game->enemy)-1));
    return OK;
  }
  /*posible error*/
}