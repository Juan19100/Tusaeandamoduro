/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Nacho
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 20

/** 
 * @brief Main function for SET unit tests. 
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
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_set_create();
  if (all || test == 2) test1_set_add();
  if (all || test == 3) test2_set_add();
  if (all || test == 4) test3_set_add();
  if (all || test == 5) test1_set_del();
  if (all || test == 6) test2_set_del();
  if (all || test == 7) test3_set_del();
  if (all || test == 8) test1_set_get_num_ids();
  if (all || test == 9) test2_set_get_num_ids();
  if (all || test == 10) test1_set_get_object();
  if (all || test == 11) test2_set_get_object();
  if (all || test == 12) test3_set_get_object();
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
  int result;
  Set *s;
  s = set_create();
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test1_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 5) == OK);
  set_destroy(s);
}

void test2_set_add() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 5) == ERROR);
}

void test3_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, NO_ID) == ERROR);
  set_destroy(s);
}

void test1_set_del() {
  Set *s;
  s = set_create();
  set_add(s,5);
  PRINT_TEST_RESULT(set_del(s, 5) == OK);
  set_destroy(s);
}

void test2_set_del() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 5) == ERROR);
}

void test3_set_del() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
  set_destroy(s);
}

void test1_set_get_num_ids() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_num_ids(s) == 0);
}

void test2_set_get_num_ids() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_num_ids(s) == -1);
  set_destroy(s);
}

void test1_set_get_object() {
  Set *s;
  s = set_create();
  set_add(s,4);
  PRINT_TEST_RESULT(set_get_object(s, 0) != NO_ID);
}

void test2_set_get_object() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_object(s, 4) == NO_ID);
  set_destroy(s);
}

void test3_set_get_object() {
  Set *s;
  s = set_create();
  set_add(s,4);
  PRINT_TEST_RESULT(set_get_object(s, 5) != 4);
  set_destroy(s);
}
