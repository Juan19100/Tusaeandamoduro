#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"


typedef struct _Enemy Enemy;

/**
  * @brief crea el enemy con el id correspondiente
  * @author Ignacio
  *
  * enemy_create crea el enemy con el id correspondiente
  *  y los demas valores de player inicializados 
  * @param id de tipo Id
  * @return el enemy ya creado 
  */
Enemy* enemy_create(Id id);

/**
  * @brief destruye el enemy
  * @author Ignacio
  *
  * enemy_destroy libera la memoria asignada para enemy
  *  
  * @param enemy puntero a enemy
  * @return  OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS enemy_destroy(Enemy* enemy);

/**
  * @brief busca el id del enemigo
  * @author Ignacio
  *
  * enemy_get_id busca el id del enemigo en cuestion
  *  
  * @param enemy puntero a enemy
  * @return el id del enemigo en caso de tenerlo
  */
Id enemy_get_id(Enemy* enemy);

/**
  * @brief asigna el nombre al enemy
  * @author Ignacio
  *
  * enemy_set_name asigna el nombre(name) al enemigo en cuastion
  *  
  * @param enemy puntero a enemy
  * @param name cadena de caracteres con el nombre del enemy
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS enemy_set_name(Enemy* enemy, char* name);

/**
  * @brief busca el nommbre del enemigo
  * @author Ignacio
  *
  * enemy_get_name busca el nombre del enemigo
  *  
  * @param  enemy puntero a enemy
  * @return el nombre del enemigo
  */
const char* enemy_get_name(Enemy* enemy);

/**
  * @brief imprime los datos del enemigo
  * @author Ignacio
  *
  * enemy_print imprime los datos del enemigo
  *  
  * @param enemy puntero a enemy
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS enemy_print(Enemy* enemy);

/**
  * @brief busca la localizacion del enemigo
  * @author Ignacio
  *
  * enemy_get_location busca la localizacion del enemigo
  *  
  * @param enemy puntero a enemy
  * @return la localizacion del enemigo
  */
Id enemy_get_location(Enemy* enemy);

/**
  * @brief asigna una localizacion al enemigo
  * @author Ignacio
  *
  * enemy_set_location asiga la localizacion indicada al enemigo
  *  
  * @param enemy puntero a enemy
  * @param id con la localización del enemigo
  * @return OK si todo ha ido bien, de lo contrario ERROR
  */
STATUS enemy_set_location(Enemy* enemy, Id location);

/**
 * @brief consigue la salud del enemigo
 * @author Ignacio
 * 
 * @param enemy puntero a Enemy
 * @return la salud actual del enemigo
 */
int enemy_get_health(Enemy* enemy); /*documentar*/
/**
 * @brief cambia la salud del enemigo
 * @author Ignacio
 * 
 * @param enemy puntero a Enemy
 * @param health tipo int
 * @return STATUS, OK si todo ha ido bien, ERROR de lo contrario
 */
STATUS enemy_set_health(Enemy* enemy, int health);

#endif
