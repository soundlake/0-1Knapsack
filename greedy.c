// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : greedy.c
// dscr : Greedy algorithm is here.

#include "header.h"
result_t greedy(lootPtr datas, int size){
    // variable declaration
    const int W = size * W_FACTOR;
    result_t result;
    int total_weight = 0;
    int i;
    // start stop watch
    clock_t start_clock = clock();
    time_t start_time = time(NULL);

    // algorithm body
    result.max_value = 0;
    for(i = 0; i < size; i++){
        total_weight += datas[i].weight;
        // if the last one make knapsack over,
        // don't put that one and try next one.
        if(total_weight > W){
            total_weight -= datas[i].weight;
            continue;
        }
        result.max_value += datas[i].value;
        result.seconds = (float)(clock() - start_clock) / CLOCKS_PER_SEC;
    }

    // time check
    if(result.seconds > 100 || result.seconds < 0)
        result.seconds = difftime(time(NULL), start_time);

    return result;
}
