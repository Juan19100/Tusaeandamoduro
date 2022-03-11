/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
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


void test1_enemy_get_name();
void test2_enemy_get_name();


void test1_enemy_get_id();
void test2_enemy_get_id();

void test1_enemy_set_location();
void test2_enemy_set_location();
void test3_enemy_set_location();

void test1_enemy_get_location();
void test2_enemy_get_location();

void test1_enemy_get_health();
void test2_enemy_get_health();

void test1_enemy_set_health();
void test2_enemy_set_health();
void test3_enemy_set_health();

#endif
