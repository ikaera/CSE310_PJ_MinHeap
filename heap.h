// Irakli Eradze  ASU ID (emplid): 1222868231

#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

// Function prototypes for heap operations
void MinHeapify(HEAP *heap, ELEMENT **V, int i); // MIN-HEAPIFY
void BuildMinHeap(HEAP *heap, ELEMENT **V);  // BUILD-MIN-HEAP
void ExtractMin(HEAP *heap, ELEMENT **V);
void DecreaseKey(HEAP *heap, ELEMENT **V, int index, double newKey, int n);
void Insertion(HEAP *heap, ELEMENT **V, int index, int n);

#endif // HEAP_H
