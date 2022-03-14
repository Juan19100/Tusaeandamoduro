/** 
 * @brief It declares the tests for the space module
 * 
 * @file set_test.h
 * @author Ignacio
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */
#ifndef SET_TEST_H
#define SET_TEST_H
#include "set.h"


/**
 * @brief Test creación de set
 * @author Ignacio
 * @pre puntero a set distinto de NULL
 *@post puntero a set distinto de NULL
 */
void test1_set_create();
/**
 * @brief prueba el añadir un objeto a set
 * @author Ignacio
 * @pre puntero a set no nulo
 *@post OK si al set se le ha añadido el id
 */
void test1_set_add();

/**
 * @brief prueba el añadir un objeto a set
 * @author Ignacio
 * @pre puntero a set nulo
 *@post ERROR porque el set es nulo
 */
void test2_set_add();

/**
 * @brief prueba el añadir un objeto a set
 * @author Ignacio
 * @pre puntero a set no nulo
 *@post ERROR al añadirse NO_ID
 */
void test3_set_add();

/**
 * @brief prueba de eliminación de objeto
 * @author Ignacio
 * @pre Puntero a set no nulo
 *@post  OK al encontrarse el id ya añadido
 */
void test1_set_del();

/**
 * @brief prueba de eliminación de objeto
 * @author Ignacio
 * @pre Puntero a set nulo
 *@post ERROR al ser el set nulo
 */
void test2_set_del();

/**
 * @brief prueba de eliinación de objeto
 * @author Ignacio
 * @pre Puntero a set no nulo
 *@post ERROR al buscar un id no añadido
 */
void test3_set_del();

/**
 * @brief prueba del número de id 
 * @author Ignacio
 * @pre Puntero a set no nulo
 *@post Que el numero de ids sea 0
 */
void test1_set_get_num_ids();

/**
 * @brief prueba del número de id 
 * @author Ignacio
 * @pre Puntero a set nulo
 *@post -1 al ser el set nulo
 */
void test2_set_get_num_ids();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Ignacio
 * @pre Puntero a set con objeto id 4
 *@post Un id válido en la primera posición
 */
void test1_set_get_object();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Ignacio
 * @pre Puntero a set nulo
 *@post NO_ID ya que el set es nulo
 */
void test2_set_get_object();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Ignacio
 * @pre Puntero a set con objeto id 4
 *@post NO_ID ya que se busca el id 5
 */
void test3_set_get_object();

#endif