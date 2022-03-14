/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Juan
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test prueba la creacion del espacio
 * @pre id del espacio
 * @post comprueba que el puntero es no nulo
 */
void test1_space_create();

/**
 * @test prueba la creacion del espacio
 * @pre id del espacio 
 * @post comprueba el id del espacio
 */
void test2_space_create();

/**
 * @test prueba la funcionalidad de cambiar el nombre del espacio
 * @pre cambio de nombre a "hola"
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test prueba la funcionalidad de cambiar el nombre del espacio
 * @pre puntero a espacio = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test prueba la funcionalidad de cambiar el nombre del espacio
 * @pre puntero a espacio != NULL, cambioo de nombre a NULL 
 * @post Output==ERROR
 */
void test3_space_set_name();
/**
 * @brief prueba la funcionalidad de cambiar el espacio norte por el id proporcionado
 * @pre puntero a espacio no nulo
 * @post output == OK
 */
void test1_space_set_north();
/**
 * @brief prueba la funcionalidad de cambiar el espacio norte por el id proporcionado
 * @pre puntero a espacio nulo
 * @post output == ERROR
 */
void test2_space_set_north();
/**
 * @brief prueba la funcionalidad de cambiar el espacio sur por el id proporcionado
 * @pre puntero a espacio no nulo
 * @post output == OK
 */
void test1_space_set_south();
/**
 * @brief prueba la funcionalidad de cambiar el espacio sur por el id proporcionado
 * @pre puntero a espacio nulo
 * @post output == ERROR
 */
void test2_space_set_south();
/**
 * @brief prueba la funcionalidad de cambiar el espacio este por el id proporcionado
 * @pre puntero a espacio no nulo
 * @post output == OK
 */
void test1_space_set_east();
/**
 * @brief prueba la funcionalidad de cambiar el espacio este por el id proporcionado
 * @pre puntero a espacio nulo
 * @post output == ERROR
 */
void test2_space_set_east();
/**
 * @brief prueba la funcionalidad de cambiar el espacio oeste por el id proporcionado
 * @pre puntero a espacio no nulo
 * @post output == OK
 */
void test1_space_set_west();
/**
 * @brief prueba la funcionalidad de cambiar el espacio oeste por el id proporcionado
 * @pre puntero a espacio nulo
 * @post output == ERROR
 */
void test2_space_set_west();
/**
 * @brief prueba la funcionalidad de conseguir el id del espacio
 * @pre puntero a espacio no nulo (con id == 25)
 * @post output == 25
 */
void test1_space_get_id();
/**
 * @brief prueba la funcionalidad de conseguir el id del espacio
 * @pre puntero a espacio nulo 
 * @post id del espacio == NO_ID
 */
void test2_space_get_id();
/**
 * @brief prueba la funcionalidad de cambiar el objeto del espacio
 * @pre puntero a espacio no nulo
 * @post output == OK
 */
void test1_space_set_object();
/**
 * @brief prueba la funcionalidad de cambiar el objeto del espacio
 * @pre puntero a espacio nulo
 * @post output == ERROR
 */
void test2_space_set_object();
/**
 * @test prueba la funcionalidad de conseguir el nombre del espacio
 * @pre  puntero a espacio no nulo
 * @post Output == 0
 */
void test1_space_get_name();
/**
 * @test prueba la funcionalidad de conseguir el nombre del espacio
 * @pre  puntero a espacio nulo
 * @post Output == NULL
 */
void test2_space_get_name();
/**
 * @brief prueba la funcionalidad de conseguir el espacio norte del espacio actual
 * @pre puntero a espacio no nulo
 * @post espacio norte == espacio norte setteado
 */
void test1_space_get_north();
/**
 * @brief prueba la funcionalidad de conseguir el espacio norte del espacio actual
 * @pre puntero a espacio nulo
 * @post espacio norte == NO_ID
 */
void test2_space_get_north();
/**
 * @brief prueba la funcionalidad de conseguir el espacio sur del espacio actual
 * @pre  puntero a espacio no nulo
 * @post  espacio sur == espacio sur setteado
 */
void test1_space_get_south();
/**
 * @brief prueba la funcionalidad de conseguir el espacio sur del espacio actual
 * @pre puntero a espacio nulo
 * @post espacio sur == NO_ID
 */
void test2_space_get_south();
/**
 * @brief prueba la funcionalidad de conseguir el espacio este del espacio actual
 * @pre puntero a espacio no nulo
 * @post espacio este == espacio este setteado
 */
void test1_space_get_east();
/**
 * @brief prueba la funcionalidad de conseguir el espacio este del espacio actual
 * @pre puntero a espacio nulo
 * @post espacio este == NO_ID
 */
void test2_space_get_east();
/**
 * @brief prueba la funcionalidad de conseguir el espacio oeste del espacio actual
 * @pre puntero a espacio no nulo
 * @post  espacio oeste == espacio oeste setteado
 */
void test1_space_get_west();
/**
 * @brief prueba la funcionalidad de conseguir el espacio oeste del espacio actual
 * @pre puntero a espacio nulo
 * @post espacio oeste == NO_ID
 */
void test2_space_get_west();
/**
 * @brief prueba la funcionalidad de conseguir el objeto del espacio actual
 * @pre puntero a espacio no nulo
 * @post objeto del espacio == FALSE
 */
void test1_space_get_object();
/**
 * @brief  prueba la funcionalidad de conseguir el objeto del espacio actual
 * @pre puntero a espacio no nulo
 * @post objeto del espacio(TRUE) == objeto setteado en el espacio(TRUE)
 */
void test2_space_get_object();
/**
 * @brief  prueba la funcionalidad de conseguir el objeto del espacio actual
 * @pre puntero a espacio nulo
 * @post objeto del espacio == FALSE
 */
void test3_space_get_object();

#endif