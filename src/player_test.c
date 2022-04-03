/** 
 * @brief .c que sirve para comprobar el player
 * 
 * 
 * @file player_test.c
 * @author Juan
 * @version 2.0 
 * @date 10-3-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "player_test.h"
#include "player.h"
#include "test.h"

#define MAX_TESTS 28

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2) {
    printf("Running all test for module Player:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_player_create();
    if (all || test == 2) test2_player_create();
    if (all || test == 3) test1_player_set_name();
    if (all || test == 4) test2_player_set_name();
    if (all || test == 5) test3_player_set_name();
    if (all || test == 6) test1_player_get_name();
    if (all || test == 7) test2_player_get_name();
    if (all || test == 8) test1_player_get_id();
    if (all || test == 9) test2_player_get_id();
    if (all || test == 10) test1_player_set_location();
    if (all || test == 11) test2_player_set_location();
    if (all || test == 12) test3_player_set_location();
    if (all || test == 13) test1_player_get_location();
    if (all || test == 14) test2_player_get_location();
    if (all || test == 15) test1_player_set_health();
    if (all || test == 16) test2_player_set_health();
    if (all || test == 17) test3_player_set_health();
    if (all || test == 18) test1_player_get_health();
    if (all || test == 19) test2_player_get_health();
    if (all || test == 20) test1_player_set_object_id();
    if (all || test == 21) test2_player_set_object_id();
    if (all || test == 22) test3_player_set_object_id();
    if (all || test == 23) test1_player_get_object_id();
    if (all || test == 24) test2_player_get_object_id();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}


void test1_player_create(){
    int result;
    Player *p; 
    p = player_create(5);
    result = p !=NULL;
    PRINT_TEST_RESULT(result);
    player_destroy(p);
}
void test2_player_create(){
  Player *p;
  p = player_create(4);
  PRINT_TEST_RESULT(player_get_id(p) == 4);
  player_destroy(p);
}

void test1_player_set_name(){
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_name(p, "hola") == OK);
  player_destroy(p);
}
void test2_player_set_name(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_name(p, "hola") == ERROR);
}
void test3_player_set_name(){
  Player *p;
  p = player_create(5);
  PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
  player_destroy(p);
}

void test1_player_get_name(){
  Player *p;
  p = player_create(1);
  player_set_name(p, "adios");
  PRINT_TEST_RESULT(strcmp(player_get_name(p), "adios") == 0);
  player_destroy(p);
}
void test2_player_get_name(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_name(p) == NULL);
}

void test1_player_get_id() {
  Player *p;
  p = player_create(25);
  PRINT_TEST_RESULT(player_get_id(p) == 25);
  player_destroy(p);
}

void test2_player_get_id() {
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
}

void test1_player_set_location(){
  Player *p;
  p = player_create(1);
  PRINT_TEST_RESULT(player_set_location(p, 2) == OK);
  player_destroy(p);
}
void test2_player_set_location(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_set_location(p, 1) == ERROR);
}
void test3_player_set_location(){
  Player *p;
  p = player_create(25);
  PRINT_TEST_RESULT(player_set_location(p, -1) == ERROR);
  player_destroy(p);
}

void test1_player_get_location(){
  Player *p;
  p = player_create(5);
  player_set_location(p, 2);
  PRINT_TEST_RESULT(player_get_location(p) == 2);
  player_destroy(p);
}
void test2_player_get_location(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
}

void test1_player_get_health(){
  Player *p;
  p = player_create(1);
  player_set_health(p, 15);
  PRINT_TEST_RESULT(player_get_health(p)==15);
  player_destroy(p);
}
void test2_player_get_health(){
  Player *p=NULL;
  PRINT_TEST_RESULT(player_get_health(p)!=15);
  player_destroy(p);
}

void test1_player_set_health(){
  Player *p;
  p = player_create(1);
  player_set_health(p, 15);
  PRINT_TEST_RESULT(player_get_health(p)==15);
  player_destroy(p);
}
void test2_player_set_health(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_health(p) != 2);
}
void test3_player_set_health(){
  Player *p;
  p = player_create(1);
  PRINT_TEST_RESULT(player_set_health(p, -1)==ERROR);
  player_destroy(p);
}

void test1_player_get_object_id(){
  Player *p;
  p = player_create(1);
  player_set_object_id(p, 15);
  PRINT_TEST_RESULT(player_get_object_id(p)==15);
  player_destroy(p);
}
void test2_player_get_object_id(){
  Player *p=NULL;
  PRINT_TEST_RESULT(player_get_object_id(p)== NO_ID);
  player_destroy(p);
}

void test1_player_set_object_id(){
  Player *p;
  p = player_create(1);
  player_set_object_id(p, 15);
  PRINT_TEST_RESULT(player_get_object_id(p)==15);
  player_destroy(p);
}
void test2_player_set_object_id(){
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_object_id(p) == NO_ID);
}
void test3_player_set_object_id(){
  Player *p;
  p = player_create(1);
  PRINT_TEST_RESULT(player_set_object_id(p, -1)==ERROR);
  player_destroy(p);
}