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
    int **B;
    result_t result;
    // start stop watch
    time_t start_time = time(NULL);

    // make a table
    B = (int**)calloc(size + 1, sizeof(int*));    // [1, size]
    for(k = 0; k <= size; k++)
        B[k] = (int*)calloc(W + 1, sizeof(int));  // [1, W]

    // initialize the table
    for(w = 0; w <= W; w++)
        B[0][w] = 0;
    for(k = 1; k <= size; k++)
        B[k][0] = 0;

    for(w = 1; w <= W; w++){
        for(k = 1; k <= size; k++){
            // temporal local variable
            int wi = datas[k-1].weight; // range of index: [0, size-1]
            int vi = datas[k-1].value;

            if((wi <= w) && (vi + B[k-1][w-wi] > B[k-1][w]))
                B[k][w] = vi + B[k-1][w-wi];
            else
                B[k][w] = B[k-1][w];

            // if it takes too long, just quit
            if((int)difftime(time(NULL), start_time) > TIME_LIMIT)
                break;
        }
    }
    result.max_value = B[size][W];

    // reallocate table
    for(k = 0; k < size; k++)
        free(B[k]);
    free(B);

    // time check
    result.seconds = (float)difftime(time(NULL), start_time);

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
