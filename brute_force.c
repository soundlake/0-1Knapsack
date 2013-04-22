// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : brute_force.c
// dscr : Brute Force algorithm is here.

#include "header.h"
result_t brute_force(lootPtr datas, int size){
    // variable declaration
    const int W = size * W_FACTOR;
    result_t result;
    int total_weight, total_value;
    int max_weight, max_value;
    long long int combination;
    int i;
    // start stop watch
    time_t start_time = time(NULL);

    if(size == 30){
        puts("BOOOOOOOOOM!!!!!!");
        fprintDs(stdout, datas, size);
    }
    // make combination with binary number
    for(combination = 1; combination < (1<<size); combination++){
        total_weight = total_value = 0;
        for(i = 0; i < size; i++){
            if(combination & (1<<i)){ // mask!
                // if there is 1 on the i-th position
                total_weight += datas[i].weight;
                // if over-weighted, don't add value but quit
                if(total_weight > W)
                    break;
                total_value  += datas[i].value;
            }
        }
        // find maximum value
        if(total_value > result.max_value)
        {
            result.max_value = total_value;
            printf("%d\n", total_value);
        }
        // if it takes too long, just quit
        if((int)difftime(time(NULL), start_time) > TIME_LIMIT)
            break;
    }
    // time check
    result.seconds = (float)difftime(time(NULL), start_time);

    return result;
}
