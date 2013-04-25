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
    time_t start_time = time(NULL);

    // if size is too big, just quit.
    if(size > 2*B){
        result.seconds = 999.999;
        result.max_value = -1;
        return result;
    }

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
            // if it takes too long, just quit
            if(difftime(time(NULL), start_time) > TIME_LIMIT)
                break;
        }
    } else{
        for(combination.h = 0; combination.h < (1<<(size-B)); combination.h++){
            for(combination.l = 1; combination.l < (1<<B); combination.l++){
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
                // if it takes too long, just quit
                if(difftime(time(NULL), start_time) > TIME_LIMIT)
                    break;
            }
            // if it takes too long, just quit
            if(difftime(time(NULL), start_time) > TIME_LIMIT)
                break;
        }
    }

    // time check
    result.seconds = difftime(time(NULL), start_time);

    return result;
}
