/** 
 * @brief .c que sirve para comprobar el enemy
 * 
 * 
 * @file enemy_test.c
 * @author Juan
 * @version 2.0 
 * @date 10-3-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "enemy_test.h"
#include "enemy.h"
#include "test.h"

#define MAX_TESTS 28

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2) {
    printf("Running all test for module Enemy:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_enemy_create();
    if (all || test == 2) test2_enemy_create();
    if (all || test == 3) test1_enemy_set_name();
    if (all || test == 4) test2_enemy_set_name();
    if (all || test == 5) test3_enemy_set_name();
    if (all || test == 6) test1_enemy_get_name();
    if (all || test == 7) test2_enemy_get_name();
    if (all || test == 8) test1_enemy_get_id();
    if (all || test == 9) test2_enemy_get_id();
    if (all || test == 10) test1_enemy_set_location();
    if (all || test == 11) test2_enemy_set_location();
    if (all || test == 12) test3_enemy_set_location();
    if (all || test == 13) test1_enemy_get_location();
    if (all || test == 14) test2_enemy_get_location();
    if (all || test == 15) test1_enemy_set_health();
    if (all || test == 16) test2_enemy_set_health();
    if (all || test == 17) test3_enemy_set_health();
    if (all || test == 18) test1_enemy_get_health();
    if (all || test == 19) test2_enemy_get_health();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_enemy_create(){
    int result;
    Enemy *e; 
    e = enemy_create(5);
    result = e !=NULL;
    PRINT_TEST_RESULT(result);
    enemy_destroy(e);
}
void test2_enemy_create(){
  Enemy *e;
  e = enemy_create(4);
  PRINT_TEST_RESULT(enemy_get_id(e) == 4);
  enemy_destroy(e);
}

void test1_enemy_set_name(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(e, "hola") == OK);
  enemy_destroy(e);
}
void test2_enemy_set_name(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_set_name(e, "hola") == ERROR);
}
void test3_enemy_set_name(){
  Enemy *e;
  e = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(e, NULL) == ERROR);
  enemy_destroy(e);
}

void test1_enemy_get_name(){
  Enemy *e;
  e = enemy_create(1);
  enemy_set_name(e, "adios");
  PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "adios") == 0);
  enemy_destroy(e);
}
void test2_enemy_get_name(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_name(e) == NULL);
}

void test1_enemy_get_id() {
  Enemy *e;
  e = enemy_create(25);
  PRINT_TEST_RESULT(enemy_get_id(e) == 25);
  enemy_destroy(e);
}

void test2_enemy_get_id() {
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_id(e) == NO_ID);
}

void test1_enemy_set_location(){
  Enemy *e;
  e = enemy_create(1);
  PRINT_TEST_RESULT(enemy_set_location(e, 2) == OK);
  enemy_destroy(e);
}
void test2_enemy_set_location(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_set_location(e, 1) == ERROR);
}
void test3_enemy_set_location(){
  Enemy *e;
  e = enemy_create(25);
  PRINT_TEST_RESULT(enemy_set_location(e, -1) == ERROR);
  enemy_destroy(e);
}

void test1_enemy_get_location(){
  Enemy *e;
  e = enemy_create(5);
  enemy_set_location(e, 2);
  PRINT_TEST_RESULT(enemy_get_location(e) == 2);
  enemy_destroy(e);
}
void test2_enemy_get_location(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_location(e) == NO_ID);
}

void test1_enemy_get_health(){
  Enemy *e;
  e = enemy_create(1);
  enemy_set_health(e, 15);
  PRINT_TEST_RESULT(enemy_get_health(e)==15);
  enemy_destroy(e);
}
void test2_enemy_get_health(){
  Enemy *e=NULL;
  PRINT_TEST_RESULT(enemy_get_health(e)!=15);
  enemy_destroy(e);
}

void test1_enemy_set_health(){
  Enemy *e;
  e = enemy_create(1);
  enemy_set_health(e, 15);
  PRINT_TEST_RESULT(enemy_get_health(e)==15);
  enemy_destroy(e);
}
void test2_enemy_set_health(){
  Enemy *e = NULL;
  PRINT_TEST_RESULT(enemy_get_health(e) != 2);
}
void test3_enemy_set_health(){
  Enemy *e;
  e = enemy_create(1);
  PRINT_TEST_RESULT(enemy_set_health(e, -1)==ERROR);
  enemy_destroy(e);
}
