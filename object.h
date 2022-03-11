#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
  * @brief crea un objeto
  * @author juan
  *
  * object_create crea un objeto con el id que le introduzcas
  *  
  * @param id de tipo id
  * @return puntero a objeto
  */
Object* object_create(Id id);

/**
  * @brief destruye un objeto
  * @author juan
  *
  * object_destroy destruye el objeto haciendo un free de su memoria
  *  
  * @param object puntero a object
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS object_destroy(Object* object);

/**
  * @brief  devuelve el id del objeto
  * @author juan
  *
  * object_get_id devuelve el id del objeto
  *  
  * @param object puntero a object
  * @return devuelve el id del objeto
  */
Id object_get_id(Object* object);

/**
  * @brief asigna un nombre al objeto
  * @author juan
  *
  * object_set_name asigna el nombre al objeto en cuestion
  *  
  * @param object puntero a object y puntero a char
  * @param name cadena de caracteres con el nuevo nombre
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief devuelve el nombre del objeto
  * @author juan
  *
  * object_get_name devuelve el nombre del objeto en caso de tenerlo
  *  
  * @param object puntero a object
  * @return el nombre del objeto
  */
const char* object_get_name(Object* object);

/**
  * @brief imprime los datos del objeto
  * @author juan 
  *
  * object_print imprime los datos del objeto
  *  
  * @param object puntero a object
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS object_print(Object* object);

#endif