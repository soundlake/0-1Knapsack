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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_TESTS 10
#define MAX_VALUE 500
#define MAX_WEIGHT 100
#define W_FACTO 25

typedef struct _loot{
    int value;
    int weight;
    float value_per_weight;
} loot, *lootPtr;

// function prototypes from generator.c
lootPtr generate(int size);
// function prototypes from heapsort.c
void heapsort(lootPtr datas, int size);

#endif
