/** 
 * @brief It declares the tests for the enemy module
 * 
 * @file space_test.h
 * @author Juan
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H
#include "set.h"

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_enemy_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_enemy_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_enemy_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_enemy_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_enemy_set_name();


/**
 * @test prueba la funcionalidad de conseguir el nombre del enemigo
 * @pre  puntero a enemigo no nulo
 * @post Output == 0
 */
void test1_enemy_get_name();
/**
 * @test prueba la funcionalidad de conseguir el nombre del enemigo
 * @pre  puntero a enemigo = NULL
 * @post Output == NULL
 */
void test2_enemy_get_name();

/**
 * @test prueba la funcionalidad de conseguir el id del enemigo
 * @pre  puntero a enemigo no nulo
 * @post output == 25
 */
void test1_enemy_get_id();
/**
 * @test prueba la funcionalidad de conseguir el id del enemigo
 * @pre  puntero a enemigo nulo
 * @post output == NO_ID
 */
void test2_enemy_get_id();
/**
 * @test prueba la funcionalidad de cambiar la localizacion del enemigo
 * @pre  puntero a enemigo no nulo
 * @post output == OK
 */
void test1_enemy_set_location();
/**
 * @test prueba la funcionalidad de cambiar la localizacion del enemigo
 * @pre  puntero a enemigo nulo
 * @post output == ERROR
 */
void test2_enemy_set_location();
/**
 * @test prueba la funcionalidad de cambiar la localizacion del enemigo
 * @pre  puntero a enemigo no nulo
 * @post output == ERROR
 */
void test3_enemy_set_location();
/**
 * @test prueba la funcionalidad de conseguir la localizacion del enemigo
 * @pre  puntero a enemigo no nulo
 * @post localizacion del enemigo == localizacion setteada
 */
void test1_enemy_get_location();
/**
 * @test prueba la funcionalidad de conseguir la localizacion del enemigo
 * @pre  puntero a enemigo nulo
 * @post output == NO_ID
 */
void test2_enemy_get_location();
/**
 * @test prueba la funcionalidad de conseguir la salud del enemigo
 * @pre  puntero a enemigo no nulo
 * @post salud del enemigo == salud setteada
 */
void test1_enemy_get_health();
/**
 * @test prueba la funcionalidad de conseguir la salud del enemigo
 * @pre  puntero a enemigo nulo
 * @post salud del enemigo != 15
 */
void test2_enemy_get_health();
/**
 * @test prueba la funcionalidad de cambiar la salud del enemigo
 * @pre  puntero a enemigo no nulo
 * @post salud del enemigo == salud setteada
 */
void test1_enemy_set_health();
/**
 * @test prueba la funcionalidad de cambiar la salud del enemigo
 * @pre  puntero a enemigo nulo
 * @post salud del enemigo != 2
 */
void test2_enemy_set_health();
/**
 * @test prueba la funcionalidad de cambiar la salud del enemigo
 * @pre  puntero a enemigo no nulo
 * @post settea la salud a -1 == ERROR
 */
void test3_enemy_set_health();

#endif
