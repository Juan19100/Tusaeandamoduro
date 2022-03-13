#ifndef SET_H
#define SET_H

#include "types.h"
#define MAX_SET 5

typedef struct _Set Set;
/**
 * @brief Crea a inicializa un Set
 * @author Ignacio
 * 
 * @return puntero a la estructura set creada 
 */
Set *set_create();

/**
 * @brief Destruye un set
 * @author Ignacio
 * 
 * @param set puntero a set
 * @return STATUS si todo ha ido bien, ERROR en caso contrario
 */
STATUS set_destroy(Set* set);

/**
 * @brief añade un id nuevo a set
 * @author Ignacio
 * 
 * @param set puntero a set
 * @param id Id del objeto a añadir
 * @return STATUS si todo ha ido bien, ERROR en caso contrario
 */
STATUS set_add(Set* set, Id id);

/**
 * @brief elimina un objeto de set
 * @author Ignacio
 * 
 * @param set puntero a set
 * @param id id del objeto a eliminar
 * @return STATUS si todo ha ido bien, ERROR en caso contrario
 */
STATUS set_del(Set* set, Id id);

/**
 * @brief devuelve el numero total de ids
 * @author Ignacio
 * 
 * @param set puntero a la función set
 * @return int correspondiente al numero de ids, -1 en caso de error
 */
int set_get_num_ids(Set* set);

/**
 * @brief devuelve el id de un objeto dada su posición
 * @author Ignacio
 * 
 * @param set puntero a set
 * @param position posición correspondiente
 * @return Id si todo va bien, NO_ID en caso contrario
 */
Id set_get_object(Set* set, int position);

/**
 * @brief imprime lo correspondiente  a set
 * @author Ignacio
 * 
 * @param set puntero a set
 * @return STATUS si todo ha ido bien, ERROR en caso contrario
 */
STATUS set_print(Set* set);

/**
 * @brief devuelve la posición dada un id
 * @author Ignacio
 * 
 * @param set puntero a set 
 * @param object_id id del objeto a buscar
 * @return la  posición del objeto, en caso de error -1
 */
int set_get_position(Set* set, Id object_id);

#endif