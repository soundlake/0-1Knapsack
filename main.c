// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : main.c
// dscr : main functions are here.

//////////////////////////////////////// PRE-PROCESS
#include "header.h"
const int SIZES_OF_DATA[] = {10, 20, 30, 40, 50, 100, 500, 1000, 5000, 10000};

//////////////////////////////////////// LOCAL FUNCTION DECLARATION
void fprintr(FILE* target, result_t **r, int rows, int cols);

//////////////////////////////////////// MAIN FUNCTION DEFINITION
#ifndef DEBUG_TEST
int main(int argc, const char** args){
    // variable declaration
    int i, j;
    result_t **results;
    lootPtr datas;

    // allocate memory for result datas
    results = (result_t**)calloc(NUMBER_OF_TESTS, sizeof(result_t*));
    assert(results != NULL);
    for(i = 0; i < NUMBER_OF_TESTS; i++){
        results[i] = (result_t*)calloc(NUMBER_OF_ALGORITHMS, sizeof(result_t));
        assert(results[i] != NULL);
        for(j = 0; j < NUMBER_OF_ALGORITHMS; j++){
            results[i][j].seconds = 0;
            results[i][j].max_value = 0;
        }
    }
#ifdef DEBUG_MAIN
    fputs("CHECK memory allocation for 'result'.\n", stdout);
    fprintr(stdout, results, NUMBER_OF_TESTS, NUMBER_OF_ALGORITHMS);
#endif

    // test!
    //for(i = 0; i < NUMBER_OF_TESTS; i++){
    for(i = 0; i < 3; i++){
        datas = generate(SIZES_OF_DATA[i]);
#ifdef DEBUG_MAIN
        fprintDs(stdout, datas, SIZES_OF_DATA[i]);
#endif
        results[i][0] = brute_force(datas, SIZES_OF_DATA[i]);
        results[i][1] = greedy(datas, SIZES_OF_DATA[i]);
        /*
         * To Do
         */

        fprintr(stdout, results, NUMBER_OF_TESTS, NUMBER_OF_ALGORITHMS);
        free(datas);
    }

    // deallocate memory for result datas
    for(i = 0; i < NUMBER_OF_TESTS; i++){
        free(results[i]);
    }
    free(results);

    return 0;
}
#endif

//////////////////////////////////////// MAIN FUNCTION DEFINITION
void fprintr(FILE* target, result_t **r, int rows, int cols){
    int row, col;

    // format
    fputs("+---------+---------------------------------------------------------------+\n", target);
    fputs("|         |      Processing time in second / Maximum benefit value        |\n", target);
    fputs("|Number of+---------------+---------------+---------------+---------------+\n", target);
    fputs("|  items  |  Brute Force  |     Greedy    |  Dynamic Prog.|  Branch & Bnd.|\n", target);
    fputs("+---------+---------------+---------------+---------------+---------------+\n", target);
    for(row = 0; row < rows; row++){
        fprintf(target, "|  %5d  |", SIZES_OF_DATA[row]);
        for(col = 0; col < cols; col++){
            fprintf(target, " T: %8.3f s |", r[row][col].seconds);
        }
        fputs("\n|         |", target);
        for(col = 0; col < cols; col++){
            fprintf(target, " V: %8d W |", r[row][col].max_value);
        }
        fputs("\n+---------+---------------+---------------+---------------+---------------+\n", target);
    }
    fputs("\n", target);
}
