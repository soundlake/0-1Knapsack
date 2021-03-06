// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : dynamic_programming.c
// dscr : Dynamic Programming algorithm is here.

#include "header.h"
void fprintB(FILE* target, int ** B, int w, int k);
result_t dynamic_programming(lootPtr datas, int size){
    // variable declaration
    const int W = size * W_FACTOR;
    int k, w;
    int *B0, *B1;
    result_t result;
    // start stop watch
    clock_t start_clock = clock();
    time_t start_time = time(NULL);

    // initialize result
    result.seconds = 0;
    result.max_value = 0;

    // make a table
    B0 = (int*)calloc(W + 1, sizeof(int));  // [1, W]
    B1 = (int*)calloc(W + 1, sizeof(int));  // [1, W]

    // initialize the table
    for(w = 0; w <= W; w++)
        B0[w] = B1[w] = 0;

    for(k = 1; k <= size; k++){
        // exchange B0 with B1
        int *tmp = B0;
        B0 = B1;
        B1 = tmp;

        for(w = 1; w <= W; w++){
            // temporal local variable
            int wi = datas[k-1].weight; // range of index: [0, size-1]
            int vi = datas[k-1].value;

            if((wi <= w) && (vi + B0[w-wi] > B0[w]))
                B1[w] = vi + B0[w-wi];
            else
                B1[w] = B0[w];

            if(result.seconds < 100)
                result.seconds = (float)(clock() - start_clock) / CLOCKS_PER_SEC;
            else
                result.seconds = difftime(time(NULL), start_time);
            // if it takes too long, just quit
            if(result.seconds > TIME_LIMIT){
                result.seconds = -1;
                break;
            }
        }
    }
    result.max_value = B1[W];

    // reallocate table
    free(B0);
    free(B1);

    return result;
}
void fprintB(FILE* target, int ** B, int W, int N){
    int k, w;
    for(k = 0; k <= N; k++){
        for(w = 0; w <= W; w++){
            fprintf(target, " %d", B[k][w]);
        }
        fputs("\n", target);
    }
}
