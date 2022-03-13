#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

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


STATUS game_reader_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL, descr[MAX_HEIGHT][WORD_SIZE+1];
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
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
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      for(i=0; i < MAX_HEIGHT; i++){
        toks = strtok(NULL, "|");
        strcpy(descr[i],toks);
      }
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        for(i=0; i < MAX_HEIGHT ; i++){
          space_set_gdesc(space, i, descr[i]);
        }
        game_reader_add_space(game, space);
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
  int i=0;
  if (object == NULL || game == NULL)
  {
    return ERROR;
  }

  while (i < MAX_OBJECTS && game->object[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_OBJECTS)
  {
    return ERROR;
  }
  
  game->object[i] = object;

  return OK; 

}

STATUS game_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
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
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, space_id);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        space_set_object(game_get_space(game,space_id), id);
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