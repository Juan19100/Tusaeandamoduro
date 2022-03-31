#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"
#include "link.h"

/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Ignacio
 * @version 2.0
 * @date 12-02-2022
 * @copyright GNU Public License
 */

/**
  * @brief añade un espacio al juego
  * @author juan
  *
  * game_reader_add_space añade un espacio al juego, menos si ya contiene el maximo numero de espacios
  *  
  * @param game puntero a game
  * @param space puntero a space
  * @return OK si ha ido todo bien o ERROR si ocure algun error
  */
STATUS game_reader_add_space(Game *game, Space *space);


/**
  * @brief añade un objeto al juego
  * @author juan
  *
  * game_reader_add_object añade un objeto al juego, menos si ya contiene el maximo numero de objetos
  *  
  * @param game puntero a game
  * @param space puntero al espacio
  * @param Object puntero a objeto
  * @return OK si ha ido todo bien o ERROR si ocure algun error
  */
STATUS game_reader_add_object(Game *game, Object *object);

/**
 * @brief añade un link al juego
 * @author
 * 
 * @param game puntero a game 
 * @param l 
 * @return STATUS 
 */
STATUS game_reader_add_link(Game *game, Link *l);

STATUS game_reader_add_player(Game *game, Player *player){
  if(!player || !game) return ERROR;

  return game_add_player(game, player);
}


STATUS game_reader_add_enemy(Game *game, Enemy *enemy){
  if(!enemy || !game) return ERROR;

  return game_add_enemy(game, enemy);
}

STATUS game_reader_add_space(Game *game, Space *space)
{

  if (space == NULL)
  {
    return ERROR;
  }

  return game_add_space(game, space);
}

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char *toks = NULL, descr[MAX_HEIGHT][WORD_SIZE+1];
  Id id = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      for(i=0; i < MAX_HEIGHT; i++){
        toks = strtok(NULL, "|");
        strcpy(descr[i],toks);
      }
      toks = strtok(NULL, "|");
      strcpy(description, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west, description);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        for(i=0; i < MAX_HEIGHT ; i++){
          space_set_gdesc(space, i, descr[i]);
        }
        game_reader_add_space(game, space);
        space_set_description(space, description);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_add_object(Game *game, Object *object)
{
  if (object == NULL || game == NULL)
  {
    return ERROR;
  }

  return game_add_object(game, object_get_id(object)); 
}

STATUS game_reader_add_link(Game *game, Link *l){
  if(!game || !l) return ERROR;

  return game_add_link(game, l);
}

STATUS game_reader_load_links(Game *game, char* filename){
  FILE *f = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  long direccion, estado;
  /* DIRECTION dir = U; */
  Id orig_id = NO_ID, dest_id = NO_ID, link_id = NO_ID;
  STATUS st = OK, st_aux = OK;
  Link *l = NULL;


  
  if(!filename) return ERROR;

  f = fopen(filename, "r");
  if(!f) return ERROR;

  while(fgets(line, WORD_SIZE, f)){
    if(strncmp("#l:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      link_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      orig_id = atol(toks);
      toks = strtok(NULL, "|");
      dest_id = atol(toks);
      toks = strtok(NULL, "|");
      direccion = atol(toks);
      toks = strtok(NULL, "|");
      estado = atol(toks);
      if(estado == 0)
        st = OK;
      else
        st = ERROR;
#ifdef DEBUG
        printf("Leido: %ld|%s|%ld|%ld|%ld", link_id, name, orig_id, dest_id, direccion, estado);
#endif
      l = link_create();
      if(l){
        st_aux = link_set_destino(l, dest_id);
        st_aux = link_set_direction(l,direccion);
        st_aux = link_set_estado(l, st);
        st_aux = link_set_id(l, link_id);
        st_aux = link_set_name(l, name);
        st_aux = link_set_origen(l, orig_id);
        st_aux = game_reader_add_link(game, l);
      }
    }
  }

  if (ferror(f))
  {
    st_aux = ERROR;
  }

  fclose(f);
  return st_aux;
}
STATUS game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space_id = NO_ID;
  STATUS status = OK;
  Object *object = NULL;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s\n", id, name, space_id, description);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        object_set_description(object, description);
        space_add_object(game_get_space(game,space_id), id);
        game_reader_add_object(game, object);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}


STATUS game_reader_load_player(Game *game, char *filename)
{
  FILE *file = NULL;
  Player *player = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space_id = NO_ID;
  int health=0, obj_max=0;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }
  while (fgets(line, WORD_SIZE, file))
  {
  if (strncmp("#p:", line, 3) == 0)
  {
    toks = strtok(line + 3, "|");
    id = atol(toks);
    toks = strtok(NULL, "|");
    strcpy(name, toks);
    toks = strtok(NULL, "|");
    space_id = atol(toks);
    toks = strtok(NULL, "|");
    health = atol(toks);
    toks = strtok(NULL, "|");
    obj_max = atol(toks);
#ifdef DEBUG
    printf("Leido: %ld|%s|%ld\n", id, name, space_id);
#endif
    player = player_create(id);
    if (player != NULL)
    {
      player_set_name(player, name);
      player_set_location(player, space_id);
      player_set_health(player,health);
      player_set_max_objects(player, obj_max);
      game_reader_add_player(game, player);
    }
  }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_load_enemy(Game *game, char *filename)
{
  FILE *file = NULL;
  Enemy *enemy = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space_id = NO_ID;
  int health=0;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
  if (strncmp("#e:", line, 3) == 0)
  {
    toks = strtok(line + 3, "|");
    id = atol(toks);
    toks = strtok(NULL, "|");
    strcpy(name, toks);
    toks = strtok(NULL, "|");
    space_id = atol(toks);
    toks = strtok(NULL, "|");
    health = atol(toks);
#ifdef DEBUG
    printf("Leido: %ld|%s|%ld\n", id, name, space_id);
#endif
    enemy = enemy_create(id);
    if (enemy != NULL)
    {
      enemy_set_name(enemy, name);
      enemy_set_location(enemy, space_id);
      enemy_set_health(enemy,health);
      game_reader_add_enemy(game, enemy);
    }
  }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}
