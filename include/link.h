#ifndef LINK_H
#define LINK_H
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 255
#define MAX_LINK 40

typedef struct _Link Link;

/**
  * @brief crea un link
  * @author juan
  *
  * link_create crea un objeto con el id que le introduzcas
  *  
  * @return puntero al link
  */
Link *link_create();

/**
  * @brief destruye un link
  * @author juan
  *
  * link_destroy destruye el link haciendo un free de su memoria
  *  
  * @param link puntero a link
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS link_destroy(Link *l);

/**
  * @brief  devuelve el id del link
  * @author juan
  *
  * link_get_id devuelve el id del link
  *  
  * @param link puntero a link
  * @return devuelve el id del link
  */
Id link_get_id(Link *l);

/**
  * @brief asigna un id al link
  * @author juan
  *
  * link_set_id asigna el id al link en cuestion
  *  
  * @param link puntero a link 
  * @param id a id
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_id(Link *l, Id id);

/**
  * @brief devuelve el nombre del link
  * @author juan
  *
  * link_get_name devuelve el nombre del link en caso de tenerlo
  *  
  * @param link puntero a link
  * @return el nombre del link
  */
char* link_get_name(Link *l);

/**
  * @brief asigna un nombre al link
  * @author juan
  *
  * link_set_name asigna el nombre al link en cuestion
  *  
  * @param link puntero a link y puntero a char
  * @param name cadena de caracteres con el nuevo nombre
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_name(Link *l, char* name);

/**
  * @brief  devuelve el origen del link
  * @author juan
  *
  * link_get_origen devuelve el origen del link
  *  
  * @param link puntero a link
  * @return devuelve el origen del link
  */
Id link_get_origen(Link *l);

/**
  * @brief asigna un origen al link
  * @author juan
  *
  * link_set_origen asigna el origen al link en cuestion
  *  
  * @param link puntero a link e id a origen
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_origen(Link *l, Id origen);

/**
  * @brief  devuelve el destino del link
  * @author juan
  *
  * link_get_destino devuelve el destino del link
  *  
  * @param link puntero a link
  * @return devuelve el destino del link
  */
Id link_get_destino(Link *l);

/**
  * @brief asigna un destino al link
  * @author juan
  *
  * link_set_destino asigna el origen al link en cuestion
  *  
  * @param link puntero a link e id a destino
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_destino(Link *l, Id destino);

/**
  * @brief asigna una direccion al link
  * @author juan
  *
  * link_set_direction asigna el origen al link en cuestion
  *  
  * @param link puntero a link y DIRECTION a una direccion
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_direction(Link *l, DIRECTION dir);

/**
  * @brief  devuelve la direccion del link
  * @author juan
  *
  * link_get_direction devuelve la direccion del link
  *  
  * @param link puntero a link
  * @return devuelve la direccion del link
  */
DIRECTION link_get_direction(Link* l);

/**
  * @brief asigna un estado al link
  * @author juan
  *
  * link_set_estado asigna el estado al link en cuestion
  *  
  * @param link puntero a link y Status a st
  * @return OK si todo ha id bien, de lo contrario ERROR
  */
STATUS link_set_estado(Link *l, STATUS st);

/**
  * @brief  devuelve el estado del link
  * @author juan
  *
  * link_get_estado devuelve el estado del link
  *  
  * @param link puntero a link
  * @return devuelve el estado del link
  */
STATUS link_get_estado(Link *l);
#endif