// Irakli Eradze  ASU ID (emplid): 1222868231

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H 1

#include <stdio.h>
#include <stdlib.h>


typedef struct TAG_ELEMENT{
int index; // index of the element
double key; // key value of the element
int pos; // index in the heap-array, 0 if not in the heap
// Other fields as you see fit
}ELEMENT;

typedef struct TAG_HEAP{
int capacity; // capacity of the heap
int size; // current size of the heap
int *H; // array of pointers to indices of the ELEMENT array
       // int H; // array of indices to the ELEMENT array
// Other fields as you see fit
}HEAP;

// ELEMENT **V;
// HEAP *pHeap;

#endif

