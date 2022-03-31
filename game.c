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
#include "link.h"

#define MAX_RAND 9

struct _Game{
  Player *player; /*!<Puntero a la estructura player*/
  Enemy *enemy; /*!<Puntero a la estructura enemy*/
  Object *object[MAX_OBJECTS]; /*!<Puntero a la estructura object*/
  Space *spaces[MAX_SPACES]; /*!<Puntero a array de la estructura spaces*/
  Link *link[MAX_LINK];
  T_Command last_cmd; /*!<Variable tipo T_Command*/
  STATUS status_last_cmd;/*!<Variable tipo STATUS*/
  char last_description[WORD_SIZE]; /*cadena de caracteres de descripciones*/
};

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
void game_command_next(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el norte
 * 
 * @param game puntero a game
 */
void game_command_back(Game *game);
/**
 * @brief comando para coger el objeto de la casilla actual si lo hay
 * 
 * @param game puntero a game
 */
void game_command_take(Game *game);
/**
 * @brief comando para dejar el objeto del jugador en el espacio actual
 * 
 * @param game puntero a game
 */
void game_command_drop(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el este
 * 
 * @param game puntero a game
 */
void game_command_right(Game *game);
/**
 * @brief comando para avanzar de casilla hacia el oeste
 * 
 * @param game puntero a game
 */
void game_command_left(Game *game);
/**
 * @brief comando para atacar al enemigo, con probabilidad aleatoria de hacerle daño o de quitarle vida al jugador
 * 
 * @param game puntero a game
 */
void game_command_attack(Game *game);

Id game_get_object_by_name(Game *game, char* name);

char *game_get_descr_by_name(Game *game, char *name);

char *game_get_descr_of_space(Game *game, Space *space);


/**
   Game interface implementation
*/

Game* game_create()
{
  Game *game = NULL;
  int i;

  game = (Game*) malloc(sizeof(Game));
  if(!game) return NULL;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }
  game->player = NULL;
  game->enemy = NULL;

  for(i=0; i < MAX_OBJECTS; i++){
    game->object[i] = NULL;
  }

  for(i=0; i < MAX_LINK; i++)
    game->link[i] = NULL;

  game->last_cmd = NO_CMD;
  game->status_last_cmd = OK;

  return game;
}

Game *game_create_from_file(char *filename)
{
  Game *newGame = NULL;


  if ((newGame = game_create()) == ERROR)
    return NULL;

  if (game_reader_load_links(newGame, filename) == ERROR || game_reader_load_enemy(newGame, filename) == ERROR || game_reader_load_player(newGame, filename) == ERROR || game_reader_load_spaces(newGame, filename) == ERROR || game_reader_load_objects(newGame, filename) == ERROR)
    return NULL;


  return newGame;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    space_destroy(game->spaces[i]);
  

  player_destroy(game->player);
  enemy_destroy(game->enemy);

  for(i=0; i < MAX_OBJECTS && game->object[i] != NULL; i++)
    object_destroy(game->object[i]);
  
  for(i=0; i < MAX_LINK && game->link[i] != NULL; i++)
    link_destroy(game->link[i]);


  free(game);
  game = NULL;

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
  space_add_object(location, object_id);

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

/*     case INSPECT:
      game_command_inspect(game);
      break; */

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
  if(player_get_health(game->player) == 0) return TRUE;
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
  STATUS st;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    game->status_last_cmd = ERROR;
    return;
  }

  for(i = 0; i < MAX_LINK && game->link[i] != NULL; i++){
    current_id = link_get_origen(game->link[i]);
    if(current_id == space_id){
      st = game_get_connection_status(game,space_id, S);
      if(st){
        current_id = game_get_connection(game, space_id, S);
        player_set_location(game->player,current_id);
        game->status_last_cmd = OK;
        return;
      }
      else{
        game->status_last_cmd = ERROR;
        return;
      }
    }
  }

  game->status_last_cmd = OK;
}

void game_command_back(Game *game)
{
  int i = 0;
  STATUS st;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    game->status_last_cmd = ERROR;
    return;
  }

  for(i = 0; i < MAX_LINK && game->link[i] != NULL; i++){
    current_id = link_get_origen(game->link[i]);
    if(current_id == space_id){
      st = game_get_connection_status(game,space_id, N);
      if(st){
        current_id = game_get_connection(game, space_id, N);
        player_set_location(game->player,current_id);
        game->status_last_cmd = OK;
        return;
      }
      else{
        game->status_last_cmd = ERROR;
        return;
      }
    }
  }

  game->status_last_cmd = OK;

}

void game_command_take(Game *game)
{
  Id object_location;
  long object_id;

  if(!game){
    game->status_last_cmd = ERROR;
    return;
  } 

  scanf(" O%ld", &object_id);
  if (object_id == NO_ID){
    game->status_last_cmd = ERROR;
    return;
  } 
  
  object_location = game_get_object_location(game, object_id);
  if(object_location == NO_ID){
    game->status_last_cmd = ERROR;
    return;
  } 
  
  if(object_location != player_get_location(game->player)) {
    game->status_last_cmd = ERROR;
    return;/*deben estar en la misma casilla*/
  }
  player_add_object(game->player, object_id);

  /*space_set_object(game_get_space(game, object_location), NO_ID);*/
  space_del_object(game_get_space(game, object_location), object_id);

  game->status_last_cmd = OK;
}

void game_command_drop(Game *game)
{
  Id object_id, space_id;

  if(!game){
    game->status_last_cmd = ERROR;
    return;
  } 

  scanf(" O%ld", &object_id);
  
  if(player_has_object(game->player, object_id) == FALSE){
    game->status_last_cmd = ERROR;
    return;
  } 
  if(object_id == NO_ID) {
    game->status_last_cmd = ERROR;
    return;
  }
  space_id = player_get_location(game->player);

  if(space_add_object(game_get_space(game, space_id), object_id) == ERROR){
    game->status_last_cmd = ERROR;
    return ;
  } 

  if(player_del_object(game->player, object_id) == ERROR){
    game->status_last_cmd = ERROR;
    return ;
  }
  game->status_last_cmd = OK;
}

void game_command_right(Game *game)
{
  int i = 0;
  STATUS st;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    game->status_last_cmd = ERROR;
    return;
  }

  for(i = 0; i < MAX_LINK && game->link[i] != NULL; i++){
    current_id = link_get_origen(game->link[i]);
    if(current_id == space_id){
      st = game_get_connection_status(game,space_id, E);
      if(st){
        current_id = game_get_connection(game, space_id, E);
        player_set_location(game->player,current_id);
        game->status_last_cmd = OK;
        return;
      }
      else{
        game->status_last_cmd = ERROR;
        return;
      }
    }
  }
  game->status_last_cmd = OK;
}

void game_command_left(Game *game)
{
  int i = 0;
  STATUS st;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    game->status_last_cmd = ERROR;
    return;
  }

  for(i = 0; i < MAX_LINK && game->link[i] != NULL; i++){
    current_id = link_get_origen(game->link[i]);
    if(current_id == space_id){
      st = game_get_connection_status(game,space_id, W);
      if(st){
        current_id = game_get_connection(game, space_id, W);
        player_set_location(game->player,current_id);
        game->status_last_cmd = OK;
        return;
      }
      else{
        game->status_last_cmd = ERROR;
        return;
      }
    }
  }
  game->status_last_cmd = OK;
}

void game_command_attack(Game *game)
{
  int x=0;
  srand(time(NULL));

  if (game_get_player_location(game) != game_get_enemy_location(game)){
    /*printf("el enemigo no esta en el mismo espacio que el jugador");*/
    game->status_last_cmd = ERROR;
    return; 
  }

  if(player_get_health(game->player)<=0){
    /*printf("el jugador ya esta a 0 de vida");*/
    game->status_last_cmd = ERROR;
    return;
  }
  
  if(enemy_get_health(game->enemy)<=0){
    /*printf("el enemigo ya esta a 0 de vida");*/
    game->status_last_cmd = ERROR;
    return;
  }

  x = rand() % MAX_RAND;

  if(x <= 4){
    player_set_health(game->player, (player_get_health(game->player)-1));
    if(player_get_health(game->player)==0){
        /*game_command_exit(game);*/
        game_is_over(game);
        game->status_last_cmd = ERROR;
        return;
    }
    game->status_last_cmd = OK;
    return;
  }

  else {
    if(enemy_set_health(game->enemy, (enemy_get_health(game->enemy)-1))==ERROR){
    game->status_last_cmd = ERROR;
    return;
    }
  }
  game->status_last_cmd = OK;
}

/* void game_command_inspect(Game *game){

  char opcion, name[WORD_SIZE];

  scanf(" %c", &opcion);
    
  if(opcion == "o"){
    scanf(" %s", name);
    strcpy (game->last_description, game_get_descr_by_name(game, name));
    game->status_last_cmd = OK;
  }
  else if(opcion == "s"){
    strcpy (game->last_description, game_get_descr_of_space(game, game_get_space(game, player_get_location(game->player))));
    game->status_last_cmd = OK;
  }
  else{
    game->status_last_cmd = ERROR;
  }
  return;
}  */

STATUS game_add_object(Game* game, Object *object){
  int i = 0;
  if(!game) return ERROR;

  while(game->object[i] != NULL)
    i++;

  if(i >= MAX_OBJECTS) return ERROR;

  game->object[i] = object;

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

Player *game_get_player(Game *game){
  if(!game)return NULL;

  return (game->player);
}

Enemy * game_get_enemy(Game *game){
  if(!game) return NULL;
  
  return game->enemy;
}

STATUS game_add_space(Game *game, Space *space){
  int i = 0;
  if(!game || !space) return ERROR;

  while(game->spaces[i] != NULL)
    i++;

  if(i >= MAX_SPACES) return ERROR;

  game->spaces[i] = space;
  
  return OK;
}

Space *game_get_space_by_position(Game *game, int position){
  if(!game || position < 0 || position >= MAX_SPACES) return NULL;

  return game->spaces[position];
}

Object *game_get_object_by_position(Game *game, int position){
  if(!game || position < 0 || position >= MAX_OBJECTS) return NULL;

  return game->object[position];
}

STATUS game_add_player(Game* game, Player *player){
  if(!game || !player) return ERROR;

  game->player = player;

  return OK;
}

STATUS game_add_enemy(Game* game, Enemy *enemy){
  if(!game || !enemy) return ERROR;

  game->enemy = enemy;

  return OK;
}

STATUS game_get_status_last_cmd(Game *game){
  if(!game) return ERROR;

  return game->status_last_cmd;
}

STATUS game_add_link(Game *game, Link *l){
  int i = 0;
  if(!game || !l) return ERROR;

  while(i < MAX_LINK && game->link[i] != NULL)
    i++;
  
  game->link[i] = l;
  
    return OK;
}

Id game_get_object_by_name(Game *game, char* name){
  int i = 0;

  if(!game || !name) return NO_ID;

  while(i < MAX_OBJECTS && game->object[i] != NULL){
    if(strcmp(object_get_name(game->object[i]), name) == 0)
      return object_get_id(game->object[i]);
    i++;
  }

  return NO_ID;
}

char *game_get_descr_by_name(Game *game, char *name){
  int i = 0;
  if(!game || !name) return NULL;

  while(i < MAX_OBJECTS && game->object[i] != NULL){
    if(strcmp(object_get_name(game->object[i]), name) == 0)
      return object_get_description(game->object[i]);
    i++;
  }
  return NULL;
}

char *game_get_descr_of_space(Game *game, Space *space){
  int i = 0;
  if(!game || !space) return NULL;

  while(i < MAX_SPACES && game->spaces[i] != NULL){
    if(game->spaces[i] == space)
      return space_get_description(game->spaces[i]);
    i++;
  }

  return NULL;
}

char *game_get_last_description(Game *game){
 if (!game) return NULL;

 return game->last_description;
}

STATUS game_get_connection_status(Game *game, Id space_id, DIRECTION dir){
  int i = 0;
  if(!game || space_id == NO_ID || dir == U) return ERROR;

  while(i < MAX_LINK && game->link[i] != NULL){
    if(link_get_origen(game->link[i]) == space_id && link_get_direction(game->link[i]) == dir){
      printf("%ld con dirección %d hacia %ld\n", link_get_origen(game->link[i]), link_get_direction(game->link[i]), link_get_destino(game->link[i]));
      return link_get_estado(game->link[i]);
    }
    i++;  
  }
  return ERROR;
}

Id game_get_connection(Game *game, Id space_id, DIRECTION dir){
  int i = 0;
  if(!game || space_id == NO_ID || dir == U) return NO_ID;

  while(i < MAX_LINK && game->link[i] != NULL){
    if(link_get_origen(game->link[i]) == space_id && dir == link_get_direction(game->link[i]))
      return link_get_destino(game->link[i]);
    i++;
  }
  return NO_ID;
}
