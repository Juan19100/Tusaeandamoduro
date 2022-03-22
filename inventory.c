#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#define MAX_OBJS 5

struct _Inventory{
    Set* objects;
    int max_objs;
};

Inventory* inventory_create(){
    Inventory *inv = NULL;

    inv = (Inventory*) malloc(sizeof(Inventory));
    if(!inv) return NULL;

    inv->objects = set_create();
    inv->max_objs = MAX_OBJS;

    return inv;
}

STATUS inventory_destroy(Inventory *inv){
    if(!inv) return OK;

    if(set_destroy(inv->objects)){
        free(inv);
        inv = NULL;
        return OK;
    }

    return ERROR;
}

STATUS inventory_add_object(Inventory *inv, Id object){
    if(!inv || object == NO_ID) return ERROR;
    
    return set_add(inv->objects, object);
}

STATUS inventory_del_object(Inventory * inv, Id object){
    if(!inv) return ERROR;

    return set_del(inv->objects, object);
}

int inventory_get_num_objects(Inventory *inv){
    if(!inv) return -1;

    return set_get_num_ids(inv->objects);
}

Id inventory_get_object(Inventory *inv, int position){
    if(!inv || position < 0) return NO_ID;

    return set_get_object(inv->objects, position);
}

int inventory_get_max_objects(Inventory *inv){
    if(!inv) return -1;

    return inv->max_objs;
}

STATUS inventory_print(Inventory *inv){
    if(!inv) return ERROR;

    set_print(inv->objects);
    fprintf(stdout, "Maximo de objetos: %d\n", inv->max_objs);

    return OK;
}