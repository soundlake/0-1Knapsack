// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 19
// file : test.c
// dscr : test functions are here.

#include "header.h"

int main(void){
    int num = 10;
    int i;
    FILE* cout = stdout;
    lootPtr datas;

    datas = generate(num);
    fprintDs(stdout, datas, num);

    free(datas);

    return 0;
}
void fprintD(FILE* target, loot data){
    fprintf(target, "|%7d|%7d|%7.3f|\n", data.value,
                                         data.weight,
                                         data.value_per_weight);
}
void fprintDs(FILE* target, lootPtr datas, int size){
    int i;
    fputs("| VALUE | WEIGHT|    V/W|\n", target);
    fputs("=========================\n", target);
    for(i = 0; i < size; i++)
        fprintD(target, datas[i]);
    fputs("\n", target);
}
