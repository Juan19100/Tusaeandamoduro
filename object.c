/**
 * @brief It defines the game loop
 *
 * @file object.c
 * @author Juan
 * @version 2.0
 * @date 17-02-2022
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

/**
 * @brief Object
 *
 * Almacena la información del objeto.
 */
struct _Object{
    Id id; /*!<Variable Id, identificador del objeto*/
    char name[WORD_SIZE+1]; /*!<cadena de caracteres con el nombre del objeto*/
    char description[WORD_SIZE+1];/*!<cadena de caracteres con la descripcion del objeto*/
};

Object* object_create(Id id){
    Object *newObject = NULL;

    newObject = (Object *) malloc(sizeof(Object));  
    if (!newObject) return NULL;

    newObject->id = id;
    newObject->name[0] = '\0';
    newObject->description[0] = '\0';

    return newObject;
}

STATUS object_destroy(Object* object){
    if (!object) return ERROR;

    free(object);
    object = NULL;
    
    return OK;
}

Id object_get_id(Object* object){
    if (!object) return NO_ID;
    
    return object->id;
}


STATUS object_set_name(Object* object, char* name){
    if(!object || !name) return ERROR;

    if(!strcpy(object->name,name)) return ERROR;

    return OK;
}

const char* object_get_name(Object* object){
    if (!object) return NULL;

    return object->name;
}

STATUS object_set_description(Object* object, char* description){
    if(!object || !description) return ERROR;

    if(!strcpy(object->description,description)) return ERROR;

    return OK;
}

const char* object_get_description(Object* object){
    if (!object) return NULL;

    return object->description;
}

STATUS object_print(Object* object){
    if(!object) return ERROR;
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
    return OK;
}

