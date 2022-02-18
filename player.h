#ifndef PROYECT_H
#define PROYECT_H

#include "types.h"

typedef struct _Player Player;
Player* player_create(Id id);
STATUS player_destroy(Player* player);
Id player_get_id(Player* player);
STATUS player_set_name(Player* player, char* name);
const char* player_get_name(Player* player);
STATUS player_print(Player* player);

#endif
