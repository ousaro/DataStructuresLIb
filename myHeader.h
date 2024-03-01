#ifndef MYLIBRARY_H
#define MYLIBRARY_H


// Defining the heap data structure
typedef struct Heap{
    int size;
    int capacity;
    int *data;

} Heap;

// Defining the priority Heap data structure
typedef struct PriorityHeap{
    Heap *heap;
    int *key;
} PriorityHeap;

// functions for heap
Heap *createHeap(int capacity);

void maxHeapify(Heap *heap, int i);

void buildMaxHeap(Heap *heap);

void insertVal(Heap *heap, int val);

void printHeap(Heap *heap);

void heapsort(Heap *heap);

int heapExtractMax(Heap *heap);

int heapMaximum(Heap *heap);


//function for priority Heap

PriorityHeap *createPriotiryHeap(int capacity);

void heapIncreaseKey(PriorityHeap *prheap, int val, int newKey);

void maxHeapInsert(PriorityHeap *prheap,int k);




#endif // MYLIBRARY_H
