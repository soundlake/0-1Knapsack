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

#include "header.h"

lootPtr generate(int size){
    // variable declaration
    int i;
    lootPtr datas;

    // allocate memory for data
    datas = (lootPtr)calloc(size, sizeof(loot));

    // randomize the data
    srand((unsigned)time(NULL));
    for(i = 0; i < size; i++){
        (datas+i)->value = rand() % MAX_VALUE + 1;
        (datas+i)->weight = rand() % MAX_WEIGHT + 1;
        (datas+i)->value_per_weight = (float)value / weight;
    }

    // sort the data with value_per_weight
    heapsort(datas);

    // return the data
    return datas;
}
