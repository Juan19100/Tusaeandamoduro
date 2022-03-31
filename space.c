/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "set.h"

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  char description[WORD_SIZE + 1]; /*!< Name of the space */
  Set *objects;              /*!< Id of all objects in the space */
  char gdesc[MAX_HEIGHT][MAX_WIDTH+1]; /*!< tabla para la representacion de cada space */
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space *newSpace = NULL;
  int i;

  /* Error control */
  if (id == NO_ID) return NULL;

  newSpace = (Space *) malloc(sizeof (Space));
  if (newSpace == NULL) return NULL;

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->description[0] = '\0';
  newSpace->objects = set_create();
  for(i = 0; i < MAX_HEIGHT ; i++){
    newSpace->gdesc[i][0] = '\0';
  }

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  if (!space) return ERROR;

  set_destroy(space->objects); /*Posible error*/
  free(space);
  space = NULL;
  return OK;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}
/** It gets the name of a space
  */
const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

STATUS space_set_description(Space* space, char* description) {
  if (!space || !description) {
    return ERROR;
  }

  if (!strcpy(space->description, description)) {
    return ERROR;
  }
  return OK;
}
/** It gets the description of a space
  */
char * space_get_description(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->description;
}


/** It sets to the space an object
  */
STATUS space_add_object(Space* space, Id value) {
  if (!space) {
    return ERROR;
  }
  
  return set_add(space->objects, value);
}

STATUS space_del_object(Space* space, Id value){
  if(!space) return ERROR;

  return set_del(space->objects, value);
}
/** It gets the space object with an id
  */
Id space_get_object(Space* space, int position) {
  if (!space) {
    return FALSE;
  }
  return set_get_object(space->objects, position);
}

/** It prints the space information
  */
STATUS space_print(Space* space) {

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /*HACER CON LINK LAS CONEXIONES*/

  /* 3. Print if there is an object in the space or not */
  /*if (space_get_object(space) != NO_ID) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }*/

  set_print(space->objects);

  return OK;
}

char *space_get_gdesc(Space *space, int position){
  if(!space)return NULL;

  if(position < 0)return NULL;

  return space->gdesc[position];
}

STATUS space_set_gdesc(Space *space, int position, char *gdesc){
  if(!space|| !gdesc)return ERROR;
  
  strcpy(space->gdesc[position], gdesc);
  return OK;

}

BOOL space_has_object(Space *space, Id id){
  int i;
  for(i=0; i < MAX_SET; i++){
    if(set_get_object(space->objects,i)  == id) return TRUE;
  }

  return FALSE;
}
