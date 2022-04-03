/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define MAX_WIDTH 9
#define MAX_HEIGHT 5

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space
  * @author Profesores PPROG
  *
  * space_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the description of a space
  * @author Juan
  * 
  * @param space a pointer to the space
  * @param name a string with the description to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_description(Space* space, char* description);

/**
  * @brief It gets the description of a space
  * @author Juan
  * 
  * @param space a pointer to the space
  * @return  a string with the description of the space
  */
char* space_get_description(Space* space);


/**
  * @brief It sets whether the space has an object or not
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param value a boolean, specifying if in the space there is an object (TRUE) or not (FALSE)
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_add_object(Space* space, Id value);

/**
  * @brief It gets whether the space has an object or not
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param position position of the object
  * @return an Id of the object
  */
Id space_get_object(Space* space, int position);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

/**
 * @brief devuelve la cadena de caracteres de la fila del espacio correspondiente
 * 
 * @param space puntero a space
 * @param position fila correspondiente de gdesc
 * @return char* la fila que se busca
 */
char *space_get_gdesc(Space *space, int position);

/**
 * @brief 
 * 
 * @param space 
 * @param position 
 * @param gdesc 
 * @return STATUS 
 */
STATUS space_set_gdesc(Space *space, int position, char *gdesc);

/**
 * @brief comprueba si un espacio tiene un objeto con un id
 * @author Ignacio
 * 
 * @param space puntero a space
 * @param id id del objeto a buscar
 * @return TRUE si está en el espacio, FALSE en caso contrario
 */
BOOL space_has_object(Space *space, Id id);

/**
 * @brief elimina el objeto de un espacio
 * @author Ignacio
 * 
 * @param space puntero a space
 * @param value Id del objeto a eliminar
 * @return OK si se ha eiminado, ERROR en caso contrario
 */
STATUS space_del_object(Space* space, Id value);



#endif
