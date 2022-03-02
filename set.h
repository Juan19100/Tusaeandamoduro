#ifndef SET_H
#define SET_H

#include "types.h"
#define MAX_SET 10

typedef struct _Set Set;

Set *set_create();
STATUS set_destroy(Set* set);
STATUS set_add(Set* set, Id id);
STATUS set_del(Set* set, Id id);
int set_get_num_ids(Set* set);
Id set_get_object(Set* set, int position);
STATUS set_print(Set* set);
int set_get_position(Set* set, Id object_id);

#endif