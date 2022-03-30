#include <stdio.h>
#include "types.h"
#include "link.h"

struct _Link{
    Id id;
    char name[MAX_NAME];
    Id origen;
    Id destino;
    DIRECTION direction;
    STATUS estado;
};

Link *link_create(){
    Link *l = NULL;

    l = (Link*) malloc(sizeof(Link));
    if(!l) return NULL;

    l->id = NO_ID;
    l->name[0] = '\0';
    l->origen = NO_ID;
    l->destino = NO_ID;
    l->direction = U;
    l->estado = ERROR;

    return l;
}

STATUS link_destroy(Link *l){
    free(l);
    return OK;
}

Id link_get_id(Link *l){
    if(!l) return ERROR;

    return l->id;
}

STATUS link_set_id(Link *l, Id id){
    if(!l) return ERROR;

    l->id = id;

    return OK;
}

char* link_get_name(Link *l){
    if(!l) return ERROR;

    return l->name;
}

STATUS link_set_name(Link *l, char* name){
    if(!l || !name) return ERROR;

    strcpy(l->name, name);

    return OK;
}


Id link_get_origen(Link *l){
    if(!l) return ERROR;

    return l->origen;
}

STATUS link_set_origen(Link *l, Id origen){
    if(!l) return ERROR;

    l->origen = origen;

    return OK;
}

Id link_get_destino(Link *l){
    if(!l) return ERROR;

    return l->destino;
}

STATUS link_set_destino(Link *l, Id destino){
    if(!l) return ERROR;

    l->destino = destino;

    return OK;
}

STATUS link_set_direction(Link *l, DIRECTION dir){
    if(!l) return ERROR;

    l->direction = dir;

    return OK;
}

DIRECTION link_get_direction(Link* l){
    if(!l) return U;

    return l->direction;
}

STATUS link_set_estado(Link *l, STATUS st){
    if(!l) return ERROR;

    l->estado = st;

    return OK;
}

STATUS link_get_estado(Link *l){
    if(!l) return ERROR;

    return l->estado;
}