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
STATUS game_set_enemy_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  return enemy_set_location(game->enemy, id);
}
/**
 * @brief devuelve el id del espacio con id == position
 * 
 * @param game puntero a game
 * @param position tipo int
 * @return Id del espacio
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief settea la localización del jugador
 * 
 * @param game puntero a Game
 * @param id tipo id
 * @return STATUS, OK si todo ha ido bien, ERROR de lo contrario 
 */
STATUS game_set_player_location(Game *game, Id id);
/**
 * @brief settea la localización de un objeto
 * 
 * @param game puntero a Game
 * @param space_id tipo id
 * @param object_id tipo id
 * @return STATUS , OK si todo ha ido bien, ERROR de lo contrario
 */
STATUS game_set_object_location(Game *game, Id space_id, Id object_id);

/**
 * @brief comando desconocido
 * 
 * @param game puntero a game
 */
void game_command_unknown(Game *game);
/**
 * @brief comando desconocido
 * 
 * @param game puntero a game
 */
void game_command_exit(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el sur
 * 
 * @param game puntero a game
 */
STATUS game_command_next(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el norte
 * 
 * @param game puntero a game
 */
STATUS game_command_back(Game *game);
/**
 * @brief comando para coger el objeto de la casilla actual si lo hay
 * 
 * @param game puntero a game
 */
STATUS game_command_take(Game *game);
/**
 * @brief comando para dejar el objeto del jugador en el espacio actual
 * 
 * @param game puntero a game
 */
STATUS game_command_drop(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el este
 * 
 * @param game puntero a game
 */
STATUS game_command_right(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el oeste
 * 
 * @param game puntero a game
 */
STATUS game_command_left(Game *game);
/**
 * @brief comando para atacar al enemigo, con probabilidad aleatoria de hacerle daño o de quitarle vida al jugador
 * 
 * @param game puntero a game
 */
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

  for(i=0; i < MAX_OBJECTS; i++){
    game->object[i] = NULL;
  }

  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_create_from_file(Game *game, char *filename)
{
  int i;

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR || game_load_objects(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  for(i=0; i < MAX_SET; i++){
    game_set_object_location(game, game_get_space_id_at(game, 0), game_get_object_location(game,game_get_space_id_at(game, 0)));
  }
  game_set_enemy_location(game, 13);

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
  for(i=0; i < MAX_OBJECTS && game->object[i] != NULL; i++){
    object_destroy(game->object[i]);
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

  for(i=0; i < MAX_SPACES && game->spaces[i] != NULL; i++){
    for(j=0; j < MAX_OBJECTS && game->object[j] != NULL; j++){
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
  player_print(game->player);
}

BOOL game_is_over(Game *game)
{
  if(player_get_health(game->player)==0){
    game_command_exit(game);
  }
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

STATUS game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
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
      return OK;
    }
  }
  return ERROR;
}

STATUS game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return ERROR;
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
      return OK;
    }
  }
  
  return ERROR;
}

STATUS game_command_take(Game *game)
{
  Id object_location;
  long object_id;

  if(!game) return ERROR;

  scanf(" 0%ld", &object_id);
  if (object_id == NO_ID) return ERROR;
  
  object_location = game_get_object_location(game, object_id);
  if(object_location == NO_ID) return ERROR;
  
  if(object_location != player_get_location(game->player)) return ERROR;/*deben estar en la misma casilla*/

  player_set_object_id(game->player, object_id);

  space_set_object(game_get_space(game, object_location), NO_ID);
  
  return OK;
}

STATUS game_command_drop(Game *game)
{
  Id object_id, space_id;

  if(!game) return ERROR;
  
  object_id = player_get_object_id(game->player);
  if(object_id == NO_ID) {
    return ERROR;
  }
  space_id = player_get_location(game->player);

  if(space_set_object(game_get_space(game, space_id), object_id) == ERROR) return ERROR;

  if(player_set_object_id(game->player, NO_ID) == ERROR) return ERROR;

  return OK;
}

STATUS game_command_right(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        player_set_location(game->player, current_id);
      }
      return ERROR;
    }
  }
  return OK;
}

STATUS game_command_left(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return ERROR;
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
      return OK;
    }
  }
  return ERROR;
}

STATUS game_command_attack(Game *game)
{
  int x=0;
  srand(time(NULL));

  if (game_get_player_location(game) != game_get_enemy_location(game)){
    /*printf("el enemigo no esta en el mismo espacio que el jugador");*/
    return ERROR; 
  }

  if(player_get_health(game->player)<=0){
    /*printf("el jugador ya esta a 0 de vida");*/
    return ERROR;
  }
  
  if(enemy_get_health(game->enemy)<=0){
    /*printf("el enemigo ya esta a 0 de vida");*/
    return ERROR;
  }

  x = rand() % MAX_RAND;

  if(x <= 4){
    player_set_health(game->player, (player_get_health(game->player)-1));
    if(player_get_health(game->player)==0){
        game_command_exit(game);
        return OK;
    }
    return OK;
  }

  else {
    if(enemy_set_health(game->enemy, (enemy_get_health(game->enemy)-1))==ERROR)return ERROR;
    return OK;
  }
}

STATUS game_add_object(Game* game, Id id){
  int i;
  if(!game) return ERROR;

  while(game->object[i] != NULL){
    i++;
  }

  if(i >= MAX_OBJECTS) return ERROR;

  game->object[i] = object_create(id);

  return OK;
}

int game_get_num_object(Game* game){
  int i=0;

  while(game->object[i] != NULL){
    i++;
  }

  return i;
}

Id game_get_object(Game* game, int position){
  if(!game) return NO_ID;
  return object_get_id(game->object[position]);
}