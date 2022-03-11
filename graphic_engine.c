/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 23
#define COLUMNS 80


struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, 13); /*9*/
  ge->descript = screen_area_init(50, 1, 29, 13);/*5*/
  ge->banner = screen_area_init(28, 15, 23, 1);
  ge->help = screen_area_init(1, 16, 78, 2);
  ge->feedback = screen_area_init(1, 19, 78, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  int i, j, k;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, print_obj;
  Space *space_act = NULL;
  char print_aux[MAX_HEIGHT][MAX_WIDTH];
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);


    
    for(i=0; i < MAX_SPACES; i++){
      if(space_get_id(game->spaces[i]) == id_back){
        k = i;
        break;
        /*for(j=0; j < MAX_HEIGHT; j++){
        strcpy(print_aux[j], space_get_gdesc(game->spaces[i], j));
          if(space_set_gdesc(game->spaces[i], j, "\0") == ERROR){
            printf("SANTA MARIA D EJESUS RUEGA POR NOSOTROS PECADORES AMEN");
          }
          printf(" CALVOOOOOOO %s ERES UN CAVLOISADVOIJALKSJD", space_get_gdesc(game->spaces[i], j));
          strcpy(print_aux[j], space_get_gdesc(game->spaces[i], j));
        }*/
      }
    }

    if (id_back != NO_ID)
    {
      sprintf(str, "  |        %3d|", (int)id_back);
      screen_area_puts(ge->map, str);
      for(i=0; i < MAX_HEIGHT ;i++){
        sprintf(str, "  |%s          |", space_get_gdesc(game->spaces[k], i));
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
    
    for(i=0; i < MAX_SPACES; i++){
      if(space_get_id(game->spaces[i]) == id_act){
        for(j=0; j < MAX_HEIGHT; j++){
          strcpy(print_aux[j], space_get_gdesc(game->spaces[i], j));
        }
      }
    }

    if (id_act != NO_ID)
    {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      /*\\(\")/ CODIFICACION HORMIGA */
      sprintf(str, "  | gpp0^  %3d|", (int)id_act);
      screen_area_puts(ge->map, str);
      for(i=0; i < MAX_HEIGHT ;i++){
        sprintf(str, "  |%s          |", print_aux[i]);
        screen_area_puts(ge->map, str);
      }
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    /*hay que hacer un bucle para detectar todos los objetos que esten en ese espacio*/
    
    for(i=0; i < MAX_SPACES; i++){
      if(space_get_id(game->spaces[i]) == id_next){
        k = i;
        break;
        /*for(j=0; j < MAX_HEIGHT; j++){
          strcpy(print_aux[j], space_get_gdesc(game->spaces[i], j));
          space_set_gdesc(game->spaces[i], j, "         ");
          printf(" CALVOOOOOOO %s ERES UN CAVLOISADVOIJALKSJD", space_get_gdesc(game->spaces[i], j));
          strcpy(print_aux[j], space_get_gdesc(game->spaces[i], j));  
        }*/
      }
    }

    if (id_next != NO_ID)
    {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |        %3d|", (int)id_next);
      screen_area_puts(ge->map, str);
      for(i=0; i < MAX_HEIGHT ;i++){
        sprintf(str, "  |%s          |", space_get_gdesc(game->spaces[k], i));
        screen_area_puts(ge->map, str);
      }
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str, "Objects location : ");
  screen_area_puts(ge->descript, str);
  
  for(i=0; i < MAX_SPACES; i++){
    for(j=0; j < MAX_HEIGHT; j++){
      print_obj = game_get_object_location(game, set_get_object (game->set[i], j));
      if(print_obj != NO_ID){
        sprintf(str, "  %ld:%ld, ", set_get_object(game->set[i],j), print_obj);
        screen_area_puts(ge->descript, str);
      }
    }
  } 

  sprintf(str, "  Player location: %ld", player_get_location(game->player));
  screen_area_puts(ge->descript, str);
  if (player_get_object_id(game->player) == NO_ID)
  {
    sprintf(str, "  Player object: vacio");
    screen_area_puts(ge->descript, str);
    /*break;*/
  }

  else
  {
    sprintf(str, "  Player object: %ld", player_get_object_id(game->player));
    screen_area_puts(ge->descript, str);
  }
  sprintf(str, "  Player health: %d", player_get_health(game->player));
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Enemy location: %ld", enemy_get_location(game->enemy));
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy health: %d", enemy_get_health(game->enemy));
  screen_area_puts(ge->descript, str);

  

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The anthill game");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, take or t, drop or d, right or r, left or l, attack or a, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
