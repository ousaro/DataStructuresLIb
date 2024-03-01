#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "myHeader.h"


Heap *createHeap(int capacity){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if(heap != NULL){
        heap->size = 0;
        heap->capacity =capacity;
        heap->data=(int *)malloc(capacity * sizeof(int));
        if(heap->data == NULL){
            free(heap);
            return NULL;
        }
    }
    return heap;
}

PriorityHeap *createPriotiryHeap(int capacity){
    PriorityHeap *prHeap =(PriorityHeap *)malloc(sizeof(PriorityHeap));
    prHeap->heap = createHeap(capacity);
    prHeap->key = (int *)malloc(capacity * sizeof(int));
    if(prHeap->key == NULL){
            free(prHeap);
            return NULL;
        }

    return prHeap;
}

void maxHeapify(Heap *heap, int i){
    int g=2*i+1;
    int d=2*i+2;
    int max =i;

    if(g<heap->size && heap->data[g]>heap->data[i]){
        max=g;
    }

    if(d<heap->size && heap->data[d]>heap->data[max]){
        max=d;
    }

    if(max!=i){
        int temp=heap->data[i];
        heap->data[i] = heap->data[max];
        heap->data[max]=temp;
        maxHeapify(heap, max);

    }

}

void buildMaxHeap(Heap *heap){

    for (int i= heap->size/2; i>=0; i--){
        maxHeapify(heap,i);
    }
}

void insertVal(Heap *heap, int val){
    heap->size++;
    if(heap->size > heap->capacity){
        printf("Heap is overflowed\n");
        return;
    }
    else{
        heap->data[heap->size-1] = val;
    }

}

void printHeap(Heap *heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; ++i) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

void printPrHeap(PriorityHeap *prHeap) {
    printf("Priority Heap elements: ");
    for (int i = 0; i < prHeap->heap->size; ++i) {
        printf("%d ", prHeap->key[i]);
    }
    printf("\n");
}

void heapsort(Heap *heap) {
    int size = heap->size;
    for (int i = heap->size - 1; i >= 1; i--) {

        int temp = heap->data[0];
        heap->data[0] = heap->data[i];
        heap->data[i] = temp;

        heap->size--;
        maxHeapify(heap, 0);
    }

    heap->size=size;
}

int heapMaximum(Heap *heap){
    return heap->data[0];
}

int heapExtractMax(Heap *heap){
    if(heap->size<1){
        printf("Heap is empty");
        return;
    }

    int max=heap->data[0];
    heap->data[0]=heap->data[heap->size-1];
    heap->size = heap->size-1;
    maxHeapify(heap,0);
    return max;

}

void heapIncreaseKey(PriorityHeap *prheap, int i, int newKey) {
    prheap->key[i] = newKey;
    while (i > 0 && prheap->key[(i - 1) / 2] < prheap->key[i]) {
        // Swap keys with parent
        int parentIndex = (i - 1) / 2;
        int temp = prheap->key[parentIndex];
        prheap->key[parentIndex] = prheap->key[i];
        prheap->key[i] = temp;
        // Update index to parent
        i = parentIndex;
    }
}

void maxHeapInsert(PriorityHeap *prHeap,int k){
    prHeap->heap->size++;
    prHeap->key[prHeap->heap->size-1]=INT_MIN;
    heapIncreaseKey(prHeap, prHeap->heap->size -1,k);
}


int main()
{
    int capacity=10;
    Heap *heap = createHeap(capacity);
    PriorityHeap *prHeap = createPriotiryHeap(capacity);



    // Insert values into the heap
    insertVal(heap, 5);
    insertVal(heap, 3);
    insertVal(heap, 17);
    insertVal(heap, 10);
    insertVal(heap, 84);
    insertVal(heap, 19);
    insertVal(heap, 6);
    insertVal(heap, 22);
    insertVal(heap,9);


    buildMaxHeap(heap);

    /*
    heapsort(heap);


    int max=heapMaximum(heap);

    int maxEtr=heapExtractMax(heap);

    printf("The heap max extracted is : %d",maxEtr);



    */




    maxHeapInsert(prHeap,5);
    maxHeapInsert(prHeap,3);
    maxHeapInsert(prHeap,17);
    maxHeapInsert(prHeap,10);
    maxHeapInsert(prHeap,84);
    maxHeapInsert(prHeap,19);
    maxHeapInsert(prHeap,6);
    maxHeapInsert(prHeap,22);
    maxHeapInsert(prHeap,9);


    printHeap(heap);
    printPrHeap(prHeap);

    free(prHeap->key);
    free(heap->data);
    free(heap);
    return 0;
}
