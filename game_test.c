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
#include "game_test.h"
#include "game.h"
#include "test.h"

#define MAX_TESTS 28

int main (int argc, char** argv){
    int test = 0;
    int all = 1;

    if (argc < 2) {
    printf("Running all test for module Game:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_game_create();
    if (all || test == 2) test1_game_create_from_file();
    if (all || test == 3) test2_game_create_from_file();
    if (all || test == 4) test1_game_get_space_id_at();
    if (all || test == 5) test2_game_get_space_id_at();
    if (all || test == 6) test1_game_get_space();
    if (all || test == 7) test2_game_get_space();
    if (all || test == 8) test1_game_set_player_location();
    if (all || test == 9) test2_game_set_player_location();

    PRINT_PASSED_PERCENTAGE;


    return 1;
}

void test1_game_create(){
    int result;
    Game *g; 
    g = game_create();
    result = g !=NULL;
    PRINT_TEST_RESULT(result);
    object_destroy(g);
}

void test1_game_create_from_file(){
    Game *g;
    FILE *pf = fopen("hormioguero.dat", "r");
    g = game_create();
    game_load_spaces(g, pf);
    PRINT_TEST_RESULT(game_create_from_file(pf) == OK);
    game_destroy(g);
}

void test2_game_create_from_file(){
    Game *g;
    FILE *pf = NULL;
    g = game_create();
    game_load_spaces(g, pf);
    PRINT_TEST_RESULT(game_create_from_file(pf) == ERROR);
    game_destroy(g);
}

void test1_game_get_space_id_at(){
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(game_get_space_id_at(s, 0) == 1);
    space_destroy(s);
}

void test2_game_get_space_id_at(){
    Space *s = NULL;
    PRINT_TEST_RESULT(enemy_get_id(s) == NO_ID);
}

void test1_game_get_space(){
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(game_get_space(s, 1) == s);
    space_destroy(s);
}

void test2_game_get_space(){
    Space *s = NULL;
    PRINT_TEST_RESULT(game_get_space(s, 1) == NULL);
    space_destroy(s);
}

void test1_game_set_player_location(){
    Player *p;
    p = player_create(1);
    PRINT_TEST_RESULT(player_set_location(p, 2) == OK);
    player_destroy(p);
}

void test2_game_set_player_location(){
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_location(p, 1) == ERROR);
}

void test1_game_set_object_location(){

}

void test1_game_set_object_location(){
    
}

