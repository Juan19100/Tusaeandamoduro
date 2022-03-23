/** 
 * @brief .c que sirve para comprobar el inventory
 * 
 * 
 * @file inventory_test.c
 * @author Ignacio
 * @version 2.0 
 * @date 22-3-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "inventory_test.h"
#include "test.h"
#include "set.h"

#define MAX_TESTS 28

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2) {
    printf("Running all test for module inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test2_inventory_create();
    if (all || test == 3) test1_inventory_add_object();
    if (all || test == 4) test2_inventory_add_object();
    if (all || test == 5) test3_inventory_add_object();
    if (all || test == 6) test1_inventory_del_object();
    if (all || test == 7) test2_inventory_del_object();
    if (all || test == 8) test3_inventory_del_object();
    if (all || test == 9) test1_inventory_get_num_objects();
    if (all || test == 10) test2_inventory_get_num_objects();
    if (all || test == 11) test1_get_object();
    if (all || test == 12) test2_get_object();
    if (all || test == 13) test3_get_object();
    if (all || test == 14) test1_inventory_get_max_objects();
    if (all || test == 15) test2_inventory_get_max_objects();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inventory_create(){
    int result;
    Inventory *inv;
    inv = inventory_create();
    result = inv != NULL;
    PRINT_TEST_RESULT(result);
    inventory_destroy(inv);
}
void test2_inventory_create(){
    Inventory *inv = NULL;
    inv = inventory_create(4);
    PRINT_TEST_RESULT(inventory_get_id(inv) == 4);
    inventory_destroy(inv);
}
void test1_inventory_add() {
    Inventory *inv;
    inv = inventory_create();
    PRINT_TEST_RESULT(inventory_add(inv, 5) == OK);
    inventory_destroy(inv);
}

void test2_inventory_add() {
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_add(inv, 5) == ERROR);
}

void test3_inventory_add() {
    Inventory *inv;
    inv = inventory_create();
    PRINT_TEST_RESULT(inventory_add(inv, NO_ID) == ERROR);
    inventory_destroy(inv);
}
void test1_inventory_del() {
    Inventory *inv;
    inv = inventory_create();
    inventory_add(inv,5);
    PRINT_TEST_RESULT(inventory_del(inv, 5) == OK);
    inventory_destroy(inv);
}

void test2_inventory_del() {
    Inventory *inv = NULL;
    PRINT_TEST_RESULT(inventory_del(inv, 5) == ERROR);
}

void test3_inventory_del() {
    Inventory *inv;
    inv = inventory_create();
    PRINT_TEST_RESULT(inventory_del(inv, 4) == ERROR);
    inventory_destroy(inv);
}
void test1_inventory_get_num_objects() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_get_num_objects(inv) == 0);
}

void test2_inventory_get_num_objects() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_get_num_objects(inv) == -1);
  inventory_destroy(inv);
}

void test1_inventory_get_object() {
  Inventory *inv;
  inv = inventory_create();
  inventory_add(inv,4);
  PRINT_TEST_RESULT(inventory_get_object(inv, 0) != NO_ID);
}

void test2_inventory_get_object() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_get_object(inv, 4) == NO_ID);
  inventory_destroy(inv);
}

void test3_inventory_get_object() {
  Inventory *inv;
  inv = inventory_create();
  inventory_add(inv,4);
  PRINT_TEST_RESULT(inventory_get_object(inv, 5) != 4);
  inventory_destroy(inv);
}
void test1_inventory_get_max_objects() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_get_max_objects(inv)==5);
  inventory_destroy(inv);
}
void test2_inventory_get_max_objects() {
  Inventory *inv = NULL;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_get_max_objects(inv)==-1);
  inventory_destroy(inv);
}