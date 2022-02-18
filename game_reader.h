#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "space.h"
#include "types.h"


STATUS game_load_spaces(Game *game, char *filename);
STATUS game_add_space(Game *game, Space *space);


#endif