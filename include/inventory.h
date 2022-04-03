#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include "set.h"
#include "types.h"

typedef struct _Inventory Inventory;

/**
 * @brief Crea un nuevo inventory
 * @author Ignacio
 * 
 * @return puntero al nuevo inventario
 */
Inventory* inventory_create();

/**
 * @brief destruye un inventory
 * @author Ignacio
 * 
 * @param inv puntero al inventory 
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS inventory_destroy(Inventory *inv);

/**
 * @brief añade un objeto al inventory
 * @author Ignacio
 * 
 * @param inv puntero al inventory
 * @param object id del objeto a añadir
 * @return OK si todo ha ido bien, ERROR en caso contrario
 */
STATUS inventory_add_object(Inventory *inv, Id object);

/**
 * @brief elimina un objeto del inventario
 * @author Ignacio
 * 
 * @param inv puntero al inventory
 * @param object Id del objeto a eliminar
 * @return OK si todo ha ido bien, ERROR en caso contrario 
 */
STATUS inventory_del_object(Inventory *inv, Id object);

/**
 * @brief devuelve el número de objetos de un inventory
 * @author Ignacio
 * 
 * @param inv puntero a inventory
 * @return el número de objetos, -1 en caso de error
 */
int inventory_get_num_objects(Inventory *inv);

/**
 * @brief devuelve un objeto dada su posición
 * @author Ignacio
 * 
 * @param inv puntero al inventory
 * @param position posición de un objeto
 * @return Id del objeto dada su posición, NO_ID en caso de error
 */
Id inventory_get_object(Inventory *inv, int position);

/**
 * @brief devuelve el máximo de objetos del inventory
 * @author Ignacio
 * 
 * @param inv puntero al inventario
 * @return máximo de objetos, -1 en caso de error
 */
int inventory_get_max_objects(Inventory *inv);

/**
 * @brief imprime el inventario
 * @author Ignacio
 * 
 * @param inv puntero a inventory
 * @return OK si ha ido todo bien, ERROR en caso contrario
 */
STATUS inventory_print(Inventory *inv);

/**
 * @brief settea la capacidad maxima del inventario
 * @author Alberto
 * 
 * @param inv puntero a inventory
 * @param obj_max capacidad maxima del inventario
 * @return OK si ha ido todo bien, ERROR en caso contrario
 */
STATUS inventory_set_max_objects(Inventory *inv, int obj_max);

/**
 * @brief comprueba si un inventory tiene un objeto
 * @author Alex
 * 
 * @param inv puntero al inventario 
 * @param obj_id id del objeto a buscar
 * @return TRUE si lo contiene, FALSE en caso contrario
 */
BOOL inventory_has_object(Inventory *inv, Id obj_id);
#endif