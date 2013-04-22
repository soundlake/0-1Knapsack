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
result_t dynamic_programming(lootPtr datas, int size){
    // variable declaration
    const int W = size * W_FACTOR;
    result_t result;
    // start stop watch
    time_t start_time = time(NULL);

    // if it takes too long, just quit
    if((int)difftime(time(NULL), start_time) > TIME_LIMIT)
        break;

    // time check
    result.seconds = (float)difftime(time(NULL), start_time);

    return result;
}
