/** 
 * @brief .c que sirve para todo lo relacionado con 
 * el jugadenemigoor
 * 
 * @file enemy.c
 * @author Juan
 * @version 2.0 
 * @date 2-3-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "object.h"
#include "enemy.h"


/**
 * @brief Enemy
 *
 * Almacena la información de Enemy.
 */
struct _Enemy{
    Id id;  /*!<Variable Id, identificador del enemy*/
    Id location;/*!<Variable Id, identificador de la localizacion*/
    int health; /*!<Variable int, identificador de la vida del enemigo*/
    char name[WORD_SIZE + 1]; /*!<Variable char, nombre del enemy*/
};

Enemy* enemy_create(Id id){
    Enemy *newEnemy = NULL;

    newEnemy = (Enemy *) malloc(sizeof (Enemy));
    
    if (!newEnemy)return NULL;

    newEnemy->name[0] = '\0';
    newEnemy->id = id;
    newEnemy->location = NO_ID;

    return newEnemy;
}

STATUS enemy_destroy(Enemy* enemy){
    if (!enemy) return ERROR;

    free(enemy);
    enemy = NULL;

    return OK;
}

Id enemy_get_id(Enemy* enemy){
    if(!enemy) return NO_ID;

    return enemy->id;
}

STATUS enemy_set_name(Enemy* enemy, char* name){
    if(!enemy || !name) return ERROR;

    if(!strcpy(enemy->name,name)) return ERROR;

    return OK;
}

const char* enemy_get_name(Enemy* enemy){
    if(!enemy) return NULL;

    return enemy->name;
}

Id enemy_get_location(Enemy* enemy){
    if(!enemy) return NO_ID;
    
    return enemy->location; 
}

STATUS enemy_set_location(Enemy* enemy, Id location){
    if(!enemy || location == NO_ID) return ERROR;

    enemy->location = location;
    
    return OK;
}

STATUS enemy_print(Enemy* enemy){
    if(!enemy) return ERROR;
    fprintf(stdout, "--> Enemy (Id: %ld; Name: %s)\n", enemy->id, enemy->name);
    return OK;
}

int enemy_get_health(Enemy *enemy){
    if(!enemy) return -1;

    return enemy->health;
}

STATUS enemy_set_health(Enemy *enemy, int health){
    if(!enemy || health <= 0) return ERROR;

    enemy->health = health;

    return OK;
}