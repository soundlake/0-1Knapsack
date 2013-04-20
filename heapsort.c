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
void heap_sort(lootPtr datas, int size){
    // variable declaration
    int i;
    int s = size;
    loot tmp;
#ifdef DEBUG_HEAP_SORT
    lootPtr test;
    fputs("heap_sort: original datas\n", stdout);
    fprintDs(stdout, datas, size);
#endif

    // build min-heap
    for(i = size/2 - 1; i >= 0; i--){
#ifdef DEBUG_HEAP_SORT
        fprintf(stdout, "heap_sort: building min-heap %d iteration\n", i);
        fprintDs(stdout, datas, size);
#endif
        reheap(datas, size, i);
    }
#ifdef DEBUG_HEAP_SORT
    fputs("heap_sort: min-heaped datas\n", stdout);
    fprintDs(stdout, datas, size);
#endif

    // sort!
    for(i = size - 1; i >= 0; i--){
        tmp = datas[0];
        datas[0] = datas[i];
        datas[i] = tmp;
        reheap(datas, --s, 0);
#ifdef DEBUG_HEAP_SORT
        fprintf(stdout, "heap_sort:heap_sort//sort! %5d iteration\n", i);
        fprintDs(stdout, datas, size);
#endif
    }
}
void reheap(lootPtr datas, int size, int root){
    // variable declaration
    int l = root * 2 + 1;
    int r = root * 2 + 2;
    int chosen;
    loot tmp;

    if(l < size){// in range
#ifdef DEBUG_HEAP_SORT
        fputs("heap_sort: reheaped datas\n", stdout);
        fprintDs(stdout, datas, size);
#endif
        // find smaller child
        if(r < size && datas[l].value_per_weight > datas[r].value_per_weight)
            chosen = r;
        else
            chosen = l;

        // compare root with smaller child
        if(datas[chosen].value_per_weight < datas[root].value_per_weight){
            tmp = datas[root];
            datas[root] = datas[chosen];
            datas[chosen] = tmp;
            reheap(datas, size, chosen);
        }
    }
}
