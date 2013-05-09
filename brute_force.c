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

const unsigned int B = sizeof(long long int) * 8;// bound of _llint
typedef struct _llint {
    unsigned long long int h;
    unsigned long long int l;
} long_long_int;

result_t brute_force(lootPtr datas, int size){
    // variable declaration
    const int W = size * W_FACTOR;
    result_t result;
    int total_weight, total_value;
    int max_weight, max_value;
    long_long_int combination;
    int i;
    // start stop watch
    clock_t start_clock = clock();
    time_t start_time = time(NULL);

    // initialize result
    result.seconds = 0;
    result.max_value = 0;

    // make combination with binary number
    if(size <= B){
        for(combination.l = 1; combination.l < (1<<size); combination.l++){
            total_weight = total_value = 0;
            for(i = 0; i < size; i++){
                if(combination.h & (1<<i/B) || combination.l & (1<<i%B)){ // mask!
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
                result.max_value = total_value;

            // time check
            if(result.seconds < 100)
                result.seconds = (float)(clock() - start_clock) / CLOCKS_PER_SEC;
            else
                result.seconds = difftime(time(NULL), start_time);
            // if it takes too long, just quit
            if(result.seconds > TIME_LIMIT){
                result.seconds = -1;
                return result;
            }
        }
    } else{
        for(combination.h = 0; combination.h < (1<<(size-B)); combination.h++){
            for(combination.l = 1; combination.l < (ULLONG_MAX); combination.l++){
                total_weight = total_value = 0;
                for(i = 0; i < size; i++){
                    if(combination.h & (1<<i/B) || combination.l & (1<<i%B)){ // mask!
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
                    result.max_value = total_value;

                // time check
                if(result.seconds < 100)
                    result.seconds = (float)(clock() - start_clock) / CLOCKS_PER_SEC;
                else
                    result.seconds = difftime(time(NULL), start_time);
                // if it takes too long, just quit
                if(result.seconds > TIME_LIMIT){
                    result.seconds = -1;
                    return result;
                }
            }
        }
    }

    return result;
}
