// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : header.h

#ifndef __HEADER_H__
#define __HEADER_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define NUMBER_OF_TESTS 10
#define NUMBER_OF_ALGORITHMS 4
#define MAX_VALUE 500
#define MAX_WEIGHT 100
#define W_FACTOR 25
#define TIME_LIMIT 300 // 5*60 seconds

typedef struct _loot{
    int value;
    int weight;
    float value_per_weight;
} loot, *lootPtr;
typedef struct _result{
    float seconds;
    int max_value;
} result_t;

// function prototypes for algorithms
result_t brute_force(lootPtr datas, int size);
result_t greedy(lootPtr datas, int size);
result_t dynamic_programming(lootPtr datas, int size);
result_t branch_and_bound(lootPtr datas, int size);
// function prototypes from generator.c
lootPtr generate(int size);
// function prototypes from heapsort.c
void reheap(lootPtr datas, int size, int root);
void heap_sort(lootPtr datas, int size);
// function prototypes from test.c
void fprintD(FILE* target, loot data);
void fprintDs(FILE* target, lootPtr datas, int size);

#endif
