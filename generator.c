// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : generator.c
// dscr : generate data for each test.
//        {value | 1 <= value <= 500}
//        {weight| 1 <= weight <= 100}

#include "header.h"

lootPtr generate(int size){
    // variable declaration
    int i;
    lootPtr datas;

    // allocate memory for data
    datas = (lootPtr)calloc(size, sizeof(loot));
    // for debugging
    assert(datas != NULL);

    // randomize the data
    srand((unsigned)time(NULL));
    for(i = 0; i < size; i++){
        (datas+i)->value = rand() % MAX_VALUE + 1;
        (datas+i)->weight = rand() % MAX_WEIGHT + 1;
        (datas+i)->value_per_weight = (float)(datas+i)->value / (datas+i)->weight;
    }

    // sort the data with value_per_weight
    heap_sort(datas, size);

    // return the data
    return datas;
}
