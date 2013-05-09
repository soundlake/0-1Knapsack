// Handong University 2013-1
// School of Computer Science & Electronic Engineering
// Class: Algorithm Analysis
// HW   : Algorithm analysis with 0-1 Knapsack problem
//
// name : Sinyeol An
// stdId: 20200320
// date : 2013. 4. 18
// file : branch_and_bound.c
// dscr : Branch & Bound algorithm is here.
//        USING linked list for priority queue

//////////////////////////////////////// PRE_PROCESSOR
#include "header.h"
#define ROOT 0

//////////////////////////////////////// DATA_DECLARATION
typedef struct __vertex *vrtxPtr;
typedef struct __vertex{
    float benefit;
    int weight;
    int tot_weight;
    float bound;
    int depth;
    vrtxPtr link;
} vertex;
struct __queue{
    int length;
    vrtxPtr front;
    vrtxPtr rear;
} queue;
float max_benefit = 0;

//////////////////////////////////////// FUNCTION_DECLARATION
////////////////////////////// PRIORITY QUEUE()
void enqueue(vrtxPtr a);
vrtxPtr dequeue(void);
void cutTail(float b);
void clearQueue();
////////////////////////////// TOOL()
vrtxPtr new_lchild(vrtxPtr p, lootPtr datas, int size, int W);
vrtxPtr new_rchild(vrtxPtr p, lootPtr datas, int size, int W);
void swapVertex(vrtxPtr *a, vrtxPtr *b);

//////////////////////////////////////// FUNCTION_DEFINITION
////////////////////////////// MAIN()
result_t branch_and_bound(lootPtr datas, int size){
    // variable declaration
    int i, j;
    const int W = size * W_FACTOR;
    result_t result;
    vrtxPtr root;
    // start stop watch
    time_t start_time = time(NULL);
    clock_t start_clock = clock();

    // initialize result
    result.seconds = 0;
    result.max_value = 0;

    // initialize new vertext
    root = (vrtxPtr)calloc(sizeof(vertex), 1);
    root->depth = -1;

    // calculate 1st bound
    for(i = ROOT; i < size; i++){
        root->tot_weight += datas[i].weight;
        root->bound += datas[i].value;
        if(root->tot_weight > W){
            root->tot_weight -= datas[i].weight;
            root->bound -= datas[i].value;
            i--;
            break;
        }
    }
    root->bound += (W - root->tot_weight) * datas[i].value_per_weight;

    // enqueue 1st element
    enqueue(root);

    // loop
    while(queue.length > 0 && root->bound > max_benefit && root->depth < size){
        vrtxPtr lchild;
        root = dequeue();
        if(!root)   // queue is empty
            break;

        // update max_benefit
        if(root->benefit > max_benefit)
            max_benefit = root->benefit;

        // if root is promising, append
        if(root->bound > max_benefit){
            // append left child
            if(lchild = new_lchild(root, datas, size, W))
                enqueue(lchild);
            // append right child
            enqueue(new_rchild(root, datas, size, W));
        }

        free(root);

        // time check
        result.max_value = max_benefit;
        if(result.seconds < 100)
            result.seconds = (float)(clock() - start_clock) / CLOCKS_PER_SEC;
        else
            result.seconds = difftime(time(NULL), start_time);
        // if it takes too long, just quit
        if(result.seconds > TIME_LIMIT){
            while(queue.length > 0){
                root = dequeue();
                free(root);
            }
            result.seconds = -1;
            return result;
        }
    }

    // time check
    if(result.seconds > 100 || result.seconds < 0)
        result.seconds = difftime(time(NULL), start_time);

    // empty queue
    while(queue.length > 0){
        root = dequeue();
        free(root);
    }

    return result;
}
////////////////////////////// PRIORITY QUEUE()
void enqueue(vrtxPtr a){
    vrtxPtr trail = NULL;

    // process length
    queue.length++;

    // if the queue was empty...
    if(queue.length == 1 && !queue.front){
        queue.front = queue.rear = a;
        return;
    }
    // if the queue had only one element
    if(queue.length == 2 && queue.front == queue.rear){
        if(queue.front->bound > a->bound){
            queue.rear->link = a;
            queue.rear = a;
        } else{
            a->link = queue.front;
            queue.front = a;
        }
        return;
    }
    // if the queue had more than 2 elements
    // && a->bound > queue.front->bound
    if(queue.front->bound < a->bound){
        a->link = queue.front;
        queue.front = a;
        return;
    }
    // if the queue had more than 2 elements
    // && a->bound > queue.front->bound
    for(trail = queue.front; trail->link; trail = trail->link)
        if(trail->link->bound < a->bound)
            break;
    a->link = trail->link;
    trail->link = a;
    return;
}
vrtxPtr dequeue(void){
    vrtxPtr tmp = queue.front;
    queue.front = queue.front->link;
    tmp->link = NULL;
    queue.length--;

    return tmp;
}
void cutTail(float b){
    vrtxPtr trail = NULL, tmp = NULL;
    for(trail = queue.front; trail->link; trail = trail->link)
        if(trail->link->bound < b)
            break;
    if(trail == queue.front)
        if(trail->bound < b)
            trail = queue.front;
    while(trail->link){
        tmp = trail->link;
        trail->link = tmp->link;
        free(tmp);
    }
}
void clearQueue(){
    while(queue.front){
        vrtxPtr tmp = queue.front;
        queue.front = tmp->link;
        free(tmp);
    }
}
////////////////////////////// TOOL()
vrtxPtr new_lchild(vrtxPtr p, lootPtr datas, int size, int W){
    vrtxPtr tmp = (vrtxPtr)calloc(sizeof(vertex), 1);

    // inheretant from a parent
    tmp->depth = p->depth + 1;
    tmp->benefit = p->benefit + datas[tmp->depth].value;
    tmp->weight = p->weight + datas[tmp->depth].weight;
    tmp->bound = p->bound;
    tmp->tot_weight = p->tot_weight;
    
    // over-weight check
    if(tmp->weight > W){
        free(tmp);
        return NULL;
    }

    // link
    tmp->link = NULL;

    return tmp;
}
vrtxPtr new_rchild(vrtxPtr p, lootPtr datas, int size, int W){
    int i;
    vrtxPtr tmp = (vrtxPtr)calloc(sizeof(vertex), 1);
 
    // inheretant from a parent
    tmp->depth = p->depth + 1;
    tmp->benefit = p->benefit;
    tmp->weight = p->weight;
 
    // calculate 1st bound
    for(i = tmp->depth + 1; i < size; i++){
        tmp->tot_weight += datas[i].weight;
        tmp->bound += datas[i].value;
        if(tmp->tot_weight > W){
            tmp->tot_weight -= datas[i].weight;
            tmp->bound -= datas[i].value;
            i--;
            break;
        }
    }
    tmp->bound += (W - tmp->tot_weight) * datas[i].value_per_weight;

    // link
    tmp->link = NULL;

    return tmp;
}
void swapVertex(vrtxPtr *a, vrtxPtr *b){
    vrtxPtr tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
