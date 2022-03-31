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

#define ROWS 35 /*+5+7*/
#define COLUMNS 90 /*+9+1*/


struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback;
};

/**FUNCION PRIVADA**/
void graphic_engine_paint_game_act(Game *game, Area *map, char *str, Id id_act, Id enemy_id, Id id_right, Id id_left, int k, int i, int j);
void graphic_engine_paint_game_back(Game *game, Area *map, char *str, Id id_back, int k);
void graphic_engine_paint_game_next(Game *game, Area *map, char *str, Id enemy_id, Id id_next, int k);
void graphic_engine_paint_game_right(Game *game, Area *map, char *str, Id id_right, int k);

int graphic_engine_find_space(Game *game, Id id){
  int i;
    for(i=0; i < MAX_SPACES; i++){
      if(game_get_space_id_at(game, i) == id){
        return i;
      }
    }
  return NO_ID;
}

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 57, 25); /*sumo 9 y 5, era antes 1,1,48,13*/
  ge->descript = screen_area_init(59, 1, 29, 13);/*creo que hay que cambiar los dos primeros solo. 50, 1, 29, 13 || 59, 1, 29, 13*/
  ge->banner = screen_area_init(28, 27, 23, 1);/*creo que solo hay que cambiar el de altura (15). 28, 15, 23, 1 || 28, 10, 23, 1*/
  ge->help = screen_area_init(1, 28, 87, 2);/*añado uno mas en y (17), y al widht añado 9 (87). 1, 16, 78, 2 || 1, 21, 87, 2*/
  ge->feedback = screen_area_init(1, 31, 87, 3);/*1, 19, 78, 3 || 1, 24, 87, 3*/

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

void graphic_engine_paint_game_back(Game *game, Area *map, char *str, Id id_back, int k){
  int i = 0, width_aux = 0;
  Id obj_id;
  char str_aux[255];

   if (id_back != NO_ID)
    {
      sprintf(str, "                      |        %3d|", (int)id_back);
      screen_area_puts(map, str);
      for(i=0; i < MAX_HEIGHT ;i++){
        sprintf(str, "                      | %s |", space_get_gdesc(game_get_space_by_position(game,k), i));
        screen_area_puts(map, str);
      }
      
      width_aux = strlen(str);

      sprintf(str,"                      |");
      for(i=0; i < MAX_SET ; i++){
        if((obj_id = space_get_object(game_get_space(game, id_back), i)) != NO_ID){
          sprintf(str_aux, " %ld", obj_id);
          strcat(str, str_aux);
        }
      }
      i=strlen(str);
      while( i< (width_aux-1)){
        sprintf(str_aux, " ");
        strcat(str, str_aux);
        i++;
      }
      sprintf(str_aux,"|");
      strcat(str,str_aux);
      screen_area_puts(map,str);
      sprintf(str, "                      +-----------+");
      screen_area_puts(map, str);
      sprintf(str, "                            ^");
      screen_area_puts(map, str);
    }
}

void graphic_engine_paint_game_act(Game *game, Area *map, char *str, Id id_act, Id enemy_id, Id id_right, Id id_left, int k, int right, int left){
  int i = 0, width_aux = 0;
  Id obj_id;
  char str_aux[255], enemy = ' ';


  if(enemy_id == id_act)
    enemy = '@';

      
  if(id_right != NO_ID && id_left == NO_ID){
    sprintf(str, "                      +-----------+  +---------");
    screen_area_puts(map, str);
    /*\\(\")/ CODIFICACION HORMIGA */
    sprintf(str, "                      |%c gpp0^ %3d|  |", enemy, (int)id_act);
    screen_area_puts(map, str);
    for(i=0; i < MAX_HEIGHT ;i++){
      sprintf(str, "                      | %s |  | %s", space_get_gdesc(game_get_space_by_position(game,k), i),
                                                          space_get_gdesc(game_get_space(game,id_right), i));
      screen_area_puts(map, str);
    }
        
    width_aux = strlen(str);
    sprintf(str,"                      |");
    for(i=0; i < MAX_SET ; i++){
      if((obj_id = space_get_object(game_get_space(game, id_act), i)) != NO_ID){
        sprintf(str_aux, " %ld", obj_id);
        strcat(str, str_aux);
      }
    }
    width_aux = strlen(str);
    
    i=strlen(str);
    
    while( i< (width_aux-1)){
      sprintf(str_aux, " ");
      strcat(str, str_aux);
      i++;
    }
    
    sprintf(str_aux,"        |>>|");
    strcat(str,str_aux);
    screen_area_puts(map,str);  
    sprintf(str, "                      +-----------+  +----------");
    screen_area_puts(map, str);
  }

  else if(id_left != NO_ID && id_right == NO_ID){     
    sprintf(str, "          ---------+  +-----------+");
    screen_area_puts(map, str);
    /*\\(\")/ CODIFICACION HORMIGA */
    sprintf(str, "                %3d|  |%c gpp0^ %3d|", (int)id_left, enemy, (int)id_act);
    screen_area_puts(map, str);
    for(i=0; i < MAX_HEIGHT ;i++){
      sprintf(str, "         %s |  | %s |", space_get_gdesc(game_get_space_by_position(game,left), i),
                                                    space_get_gdesc(game_get_space_by_position(game,k), i));
      screen_area_puts(map, str);
    }
      
    width_aux = strlen(str);
    sprintf(str,"                   |<<|");
    for(i=0; i < MAX_SET ; i++){
      if((obj_id = space_get_object(game_get_space(game, id_act), i)) != NO_ID){
        sprintf(str_aux, " %ld", obj_id);
        strcat(str, str_aux);
      }
    }
    
    i=strlen(str);
    
    while( i< (width_aux-1)){
        sprintf(str_aux, " ");
        strcat(str, str_aux);
        i++;
    }
    
    sprintf(str_aux,"|");
    strcat(str,str_aux);
    screen_area_puts(map,str); 
    sprintf(str, "          ---------+  +-----------+");
    screen_area_puts(map, str);
  }

  else if(id_right != NO_ID && id_left != NO_ID){
    sprintf(str, "         ---------+  +-----------+  +---------");
    screen_area_puts(map, str);
    /*\\(\")/ CODIFICACION HORMIGA */
    sprintf(str, "               %3d|  |%c gpp0^ %3d|  |", (int)id_left, enemy, (int)id_act);
    screen_area_puts(map, str);
    for(i=0; i < MAX_HEIGHT ;i++){
      sprintf(str, "        %s |  | %s |  | %s", space_get_gdesc(game_get_space_by_position(game,left), i), 
                                                          space_get_gdesc(game_get_space_by_position(game,k), i),
                                                          space_get_gdesc(game_get_space_by_position(game,right), i));
      screen_area_puts(map, str);
    }
    
    width_aux = strlen(str);
    sprintf(str,"                  |<<|");
    for(i=0; i < MAX_SET ; i++){
      if((obj_id = space_get_object(game_get_space(game, id_act), i)) != NO_ID){
        sprintf(str_aux, " %ld", obj_id);
        strcat(str, str_aux);
      }
    }
    width_aux = strlen(str);
    
    i=strlen(str);
    
    while( i< (width_aux-1)){
        sprintf(str_aux, " ");
        strcat(str, str_aux);
        i++;
    }
    
    sprintf(str_aux,"           |>>|");
    strcat(str,str_aux);
    screen_area_puts(map,str); 
    sprintf(str, "         ---------+  +-----------+  +---------");
    screen_area_puts(map, str);
  }
      
  else{
    sprintf(str, "                      +-----------+");
    screen_area_puts(map, str);
    /*\\(\")/ CODIFICACION HORMIGA */
    sprintf(str, "                      |%c gpp0^ %3d|", enemy, (int)id_act);
    screen_area_puts(map, str);
    for(i=0; i < MAX_HEIGHT ;i++){
      sprintf(str, "                      | %s |", space_get_gdesc(game_get_space_by_position(game,k), i));
      screen_area_puts(map, str);
    }
        
    width_aux = strlen(str);
    sprintf(str,"                      |");
    for(i=0; i < MAX_SET ; i++){
      if((obj_id = space_get_object(game_get_space(game, id_act), i)) != NO_ID){
        sprintf(str_aux, " %ld", obj_id);
        strcat(str, str_aux);
      }
    }
        
    i=strlen(str);
        
    while( i< (width_aux-1)){
      sprintf(str_aux, " ");
      strcat(str, str_aux);
      i++;
    }
        
    sprintf(str_aux,"|");
    strcat(str,str_aux);
    screen_area_puts(map,str);
    sprintf(str, "                      +-----------+");
    screen_area_puts(map, str);
  }
  
  /* sprintf(str, "                      +-----------+");
  screen_area_puts(map, str); */
}

void graphic_engine_paint_game_next(Game *game, Area *map, char *str, Id enemy_id, Id id_next, int k){
  int i = 0, width_aux = 0;
  Id obj_id;
  char str_aux[255], enemy = ' ';

  if(enemy_id == id_next){
    enemy = '@';
  }

  sprintf(str, "                            v");
  screen_area_puts(map, str);
  sprintf(str, "                      +-----------+");
  screen_area_puts(map, str);
  sprintf(str, "                      | %c      %3d|", enemy, (int)id_next);
  screen_area_puts(map, str);
  for(i=0; i < MAX_HEIGHT ;i++){
    sprintf(str, "                      | %s |", space_get_gdesc(game_get_space_by_position(game,k), i));
    screen_area_puts(map, str);
  }
  
  width_aux = strlen(str);
  sprintf(str,"                      |");
  for(i=0; i < MAX_SET ; i++){
    if((obj_id = space_get_object(game_get_space(game, id_next), i)) != NO_ID){
      sprintf(str_aux, " %ld", obj_id);
      strcat(str, str_aux);
    }
  }
  
  i=strlen(str);
  
  while( i< (width_aux-1)){
    sprintf(str_aux, " ");
    strcat(str, str_aux);
    i++;
  }
  
  sprintf(str_aux,"|");
  strcat(str,str_aux);
  screen_area_puts(map,str);
}



void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  int i, j, k;
  STATUS st;
  Id enemy_id = NO_ID, id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_right = NO_ID, id_left = NO_ID, obj_id = NO_ID;
  char str[255], str_aux[255], *last_description;
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {

    st = game_get_connection_status(game, id_act, N);
    if(st)
      id_back = game_get_connection(game, id_act,N);
    
    st = game_get_connection_status(game, id_act, S);
    if(st){
      id_next = game_get_connection(game, id_act,S);
    }
    st = game_get_connection_status(game, id_act, E);
    if(st)
      id_right = game_get_connection(game, id_act,E);
    
    st = game_get_connection_status(game, id_act, W);
    if(st)
      id_left = game_get_connection(game, id_act,W);
    
    enemy_id = enemy_get_location(game_get_enemy(game));

    k = graphic_engine_find_space(game, id_back);
    if (id_back != NO_ID)
    {
      graphic_engine_paint_game_back(game, ge->map, str, id_back, k);
    }

    k = graphic_engine_find_space(game, id_act);
    i = graphic_engine_find_space(game, id_right);
    j = graphic_engine_find_space(game, id_left);
    if (id_act != NO_ID)
    {
      graphic_engine_paint_game_act(game, ge->map, str, id_act, enemy_id, id_right,id_left, k, i, j);
    }
    
    k = graphic_engine_find_space(game, id_next);
    if (id_next != NO_ID)
    {
      graphic_engine_paint_game_next(game, ge->map, str, enemy_id, id_next, k);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str, "  Objects location : ");
  screen_area_puts(ge->descript, str);
  if(game_get_num_object(game) != 0){
    for(i=0; i < MAX_OBJECTS && game_get_object_by_position(game, i) != NULL; i++){
      for(j=0; j < MAX_SPACES && game_get_space_by_position(game,j) != NULL; j++){
        if(space_has_object(game_get_space_by_position(game,j), game_get_object(game,i))){
          for(k=0; k < MAX_SET; k++){
            if(space_get_object(game_get_space_by_position(game,j),k) == game_get_object(game,i)){
              sprintf(str, "  %ld:%ld, ", space_get_object(game_get_space_by_position(game,j), k), game_get_space_id_at(game,j));
              screen_area_puts(ge->descript, str);
            }
          }
        }
      }
    }
  }

  else{
    sprintf(str, "  No objects in the game");
    screen_area_puts(ge->descript, str);
  }

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Player location: %ld", player_get_location(game_get_player(game)));
  screen_area_puts(ge->descript, str);
  if (player_get_num_objects(game_get_player(game)) == 0)
  {
    sprintf(str, "  Player object: vacio");
    screen_area_puts(ge->descript, str);
  }

  else
  {
    sprintf(str, "  Player objects:");
    for(i=0; i < player_get_num_objects(game_get_player(game)) ; i++){
        if((obj_id = player_get_object_by_position(game_get_player(game), i)) != NO_ID){
          sprintf(str_aux, " %ld", obj_id);
          strcat(str, str_aux);
        }
    }
    screen_area_puts(ge->descript, str);
  }
  
  sprintf(str, "  Player health: %d", player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Enemy location: %ld", enemy_get_location(game_get_enemy(game)));
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Enemy health: %d", enemy_get_health(game_get_enemy(game)));
  screen_area_puts(ge->descript, str);

  last_description = game_get_last_description(game);

  sprintf(str, "  description: %s", last_description);
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
  if (last_cmd == NO_CMD || last_cmd == UNKNOWN) {
    sprintf(str, " %s (%s)", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  } else if (game_get_status_last_cmd(game) == OK) {
    sprintf(str, " %s (%s): OK", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  } else {
    sprintf(str, " %s (%s): ERROR", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
