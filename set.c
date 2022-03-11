#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct _Set{
    Id id[MAX_SET];
    int n_ids;
};

Set* set_create(){
    Set *s = NULL;
    int i;

    s = (Set*) malloc(sizeof(Set));
    if(!s) return NULL;
    
    for(i=0; i < MAX_SET; i++){
        s->id[i] = NO_ID;
    }
    s->n_ids = 0;

    return s;
}

STATUS set_destroy(Set* set){
    if(!set) return ERROR;
    free(set);
    set = NULL;

    return OK;
}

STATUS set_add(Set* set, Id id){
    if(!set || id < 0 || set->n_ids >= MAX_SET) return ERROR;

    set->n_ids++;
    set->id[set->n_ids-1] = id;

    return OK;
}

STATUS set_del(Set*set, Id id){
    int i;

    if(!set || id <= 0) return ERROR;

    for(i=0; i < set->n_ids; i++){
        if(set->id[i] == id){
            set->id[i] = set->id[set->n_ids - 1];
            set->id[set->n_ids - 1] = NO_ID;
            set->n_ids--;
            return OK;
        }
    }

    return ERROR;
}

int set_get_num_ids(Set* set){
    if(!set) return -1;
    return set->n_ids;
}

Id set_get_object(Set* set, int position){
    if(!set || position < 0) return NO_ID;

    return set->id[position];
}

int set_get_position(Set* set, Id object_id){
    int i;

    if(!set || object_id == NO_ID) return -1;

    for(i=0; i < set->n_ids; i++){
        if(set->id[i] == object_id) return i;
    }

    return -1;
}
STATUS set_print(Set* set){
    int i;
    if(!set) return ERROR;

    fprintf(stdout, "Total de ids: %d\n", set->n_ids);

    for(i=0; i < set->n_ids; i++){
        fprintf(stdout, "Object con id: %ld en posición %d\n", set->id[i], i+1);
    }
    return OK;
}