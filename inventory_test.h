/** 
 * @brief It declares the tests for the inventory module
 * 
 * @file inventory_test.h
 * @author Alberto
 * @version 2.0 
 * @date 22-03-2021
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H
#include "inventory.h"

/**
 * @brief Test creación de inventory
 * @author Alberto
 * @pre puntero a inventory distinto de NULL
 *@post puntero a inventory distinto de NULL
 */
void test1_inventory_create();
/**
 * @brief prueba el añadir un objeto a inventory
 * @author Alberto
 * @pre puntero a inventory no nulo
 *@post OK si al inventory se le ha añadido el id
 */
void test1_inventory_add();

/**
 * @brief prueba el añadir un objeto a inventory
 * @author Alberto
 * @pre puntero a inventory nulo
 *@post ERROR porque el inventory es nulo
 */
void test2_inventory_add();

/**
 * @brief prueba el añadir un objeto a inventory
 * @author Alberto
 * @pre puntero a inventory no nulo
 *@post ERROR al añadirse NO_ID
 */
void test3_inventory_add();

/**
 * @brief prueba de eliminación de objeto
 * @author Alberto
 * @pre Puntero a inventory no nulo
 *@post  OK al encontrarse el id ya añadido
 */
void test1_inventory_del();

/**
 * @brief prueba de eliminación de objeto
 * @author Alberto
 * @pre Puntero a inventory nulo
 *@post ERROR al ser el inventory nulo
 */
void test2_inventory_del();

/**
 * @brief prueba de eliminación de objeto
 * @author Alberto
 * @pre Puntero a inventory no nulo
 *@post ERROR al buscar un id no añadido
 */
void test3_inventory_del();

/**
 * @brief prueba del número de id 
 * @author Alberto
 * @pre Puntero a inventory no nulo
 *@post Que el numero de objects sea 0
 */
void test1_inventory_get_num_objects();

/**
 * @brief prueba del número de id 
 * @author Alberto
 * @pre Puntero a inventory nulo
 *@post -1 al ser el inventory nulo
 */
void test2_inventory_get_num_objects();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Alberto
 * @pre Puntero a inventory con objeto id 4
 *@post Un id válido en la primera posición
 */
void test1_inventory_get_object();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Alberto
 * @pre Puntero a inventory nulo
 *@post NO_ID ya que el inventory es nulo
 */
void test2_inventory_get_object();

/**
 * @brief prueba de que se obtienen bien los objetos
 * @author Alberto
 * @pre Puntero a inventory con objeto id 4
 *@post NO_ID ya que se busca el id 5
 */
void test3_inventory_get_object();

/**
 * @brief prueba de que se obtiene bien el máximo de objetos
 * @author Alberto
 * @pre Puntero a inventory
 *@post 5 ya que es el máximo numero de objetos
 */
void test1_inventory_get_max_objects();

/**
 * @brief prueba de que se obtiene bien el máximo de objetos
 * @author Alberto
 * @pre Puntero a inventory nulo
 *@post -1 ya que le entra un inventory nulo
 */
void test2_inventory_get_max_objects();


#endif