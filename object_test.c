/** 
 * @brief It tests object module
 * 
 * @file object_test.c
 * @author Nacho
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 20

/** 
 * @brief Main function for object unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module object:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }

  }


  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test1_object_get_id();
  if (all || test == 4) test2_object_get_id();
  if (all || test == 5) test1_object_get_name();
  if (all || test == 6) test2_object_get_name();
  if (all || test == 7) test1_object_set_name();
  if (all || test == 8) test2_object_set_name();
  if (all || test == 9) test3_object_set_name();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_object_create(){
    int result;
    Object *o; 
    o = object_create(5);
    result = o !=NULL;
    PRINT_TEST_RESULT(result);
    object_destroy(o);
}
void test2_object_create(){
  Object *o;
  o = object_create(4);
  PRINT_TEST_RESULT(object_get_id(o) == 4);
  object_destroy(o);
}

void test1_object_get_id() {
  Object *o;
  o = object_create(25);
  PRINT_TEST_RESULT(object_get_id(o) == 25);
  object_destroy(o);
}

void test2_object_get_id() {
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_get_name(){
  Object *o;
  o = object_create(1);
  object_set_name(o, "adios");
  PRINT_TEST_RESULT(strcmp(object_get_name(o), "adios") == 0);
  object_destroy(o);
}
void test2_object_get_name(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_set_name(){
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_name(o, "hola") == OK);
  object_destroy(o);
}
void test2_object_set_name(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_set_name(o, "hola") == ERROR);
}
void test3_object_set_name(){
  Object *o;
  o = object_create(5);
  PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
  object_destroy(o);
}