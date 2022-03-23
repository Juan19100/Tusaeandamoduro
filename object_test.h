/** 
 * @brief It declares the tests for the object module
 * 
 * @file object_test.h
 * @author Juan
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H
#include "object.h"
#include "set.h"


/**
 * @test Test object creation
 * @pre object ID 
 * @post Non NULL pointer to object 
 */
void test1_object_create();
/**
 * @test Test object creation
 * @pre object ID 
 * @post object_ID == Supplied object Id
 */
void test2_object_create();

/**
 * @test prueba la funcionalidad de conseguir el id del objeto
 * @pre  puntero a objeto no nulo
 * @post output == 25
 */
void test1_object_get_id();
/**
 * @test prueba la funcionalidad de conseguir el id del objeto
 * @pre  puntero a objeto nulo
 * @post output == NO_ID
 */
void test2_object_get_id();

/**
 * @test Test function for object_name setting
 * @pre String with object name
 * @post Ouput==OK 
 */
void test1_object_set_name();
/**
 * @test Test function for object_name setting
 * @pre pointer to object = NULL 
 * @post Output==ERROR
 */
void test2_object_set_name();
/**
 * @test Test function for object_name setting
 * @pre pointer to object_name = NULL (point to object = NON NULL) 
 * @post Output==ERROR
 */
void test3_object_set_name();

/**
 * @test prueba la funcionalidad de conseguir el nombre del objeto
 * @pre  puntero a objeto no nulo
 * @post Output == 0
 */
void test1_object_get_name();
/**
 * @test prueba la funcionalidad de conseguir el nombre del objeto
 * @pre  puntero a objeto = NULL
 * @post Output == NULL
 */
void test2_object_get_name();

#endif