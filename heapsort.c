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

#include "header.h"
void heapsort(lootPtr datas, int size){
    // variable declaration
    int i;
    int s = size;
    loot tmp;

    // build max-heap
    for(i = size / 2; i >= 0; i--)
        reheap(datas, size, i);

    // sort!
    for(i = size - 1; i >= 0; i--){
        tmp = datas[0];
        datas[0] = datas[i];
        datas[i] = tmp;
        reheap(datas, --s, 0);
    }
}
void reheap(lootPtr datas, int size, int root){
    // variable declaration
    int l = root * 2 + 1;
    int r = root * 2 + 2;
    int chosen;
    lootPtr son;
    loot tmp;

    if(l < size){// in range
        // find bigger child
        if(datas[l].value_per_weight > datas[r].value_per_weight){
            chosen = l;
        else
            chosen = r;
        son = datas+chosen;

        // compare root with bigger child
        if(son->value_per_weight > datas[root].value_per_weight){
            tmp = datas[root];
            datas[root] = *son;
            *son = tmp;
            reheap(datas, size, chosen);
        }
    }
}
