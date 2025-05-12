// Irakli Eradze  ASU ID (emplid): 1222868231

#include "heap.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

// Function to maintain the heap property at index i
/*
MIN-HEAPIFY(A, i)
    l = LEFT(i)
    r = RIGHT(i)
    if l ≤ heap-size[A] and A[l] < A[i] then
        smallest = l
    else
        smallest = i
    if r ≤ heap-size[A] and A[r] < A[smallest] then
        smallest = r
    if smallest ≠ i then
        exchange A[i] and A[smallest]
        MIN-HEAPIFY(A, smallest)
*/
void MinHeapify(HEAP *heap, ELEMENT **V, int i) {
    int l = 2 * i;       // Left child
    int r = 2 * i + 1;   // Right child
    int smallest = i;    // Initialize smallest as the root

    // If left child is smaller than root
    if (l <= heap->size && V[heap->H[l]]->key < V[heap->H[smallest]]->key) {
        smallest = l;
    }

    // If right child is smaller than the smallest so far
    if (r <= heap->size && V[heap->H[r]]->key < V[heap->H[smallest]]->key) {
        smallest = r;
    }

    // If the smallest is not the root
    if (smallest != i) {
        // Swap the elements
        int temp = heap->H[i];
        heap->H[i] = heap->H[smallest];
        heap->H[smallest] = temp;

        // Update the positions in the ELEMENT array
         V[heap->H[i]]->pos = i;
         V[heap->H[smallest]]->pos = smallest;

        // Recursively heapify the affected subtree
        MinHeapify(heap, V, smallest);
    }
}

// Function to build the heap using the linear-time BuildHeap algorithm
/*
BUILD-MIN-HEAP(A)
    heap-size[A] = length[A]
    for i = \[ \text{length}[A]/2 \] down to 1 do
        MIN-HEAPIFY(A, i)
*/
void BuildMinHeap(HEAP *heap, ELEMENT **V) {
    // Set the size of the heap
    heap->size = heap->capacity;

    // Initialize the heap array
    for (int i = heap->size; i >= 1; i--) {
        heap->H[i] = i;
        V[i]->pos = i;
    }

    // Build the heap
    for (int i = heap->size / 2; i >= 1; i--) {
        MinHeapify(heap, V, i);
    }
}

// Function to extract the minimum element from the heap
/*
EXTRACT-MIN(A)
    if heap-size[A] < 1 then
        "error: heap empty"
    else
        min = A[1]
        A[1] = A[heap-size[A]]
        heap-size[A]--
        MIN-HEAPIFY(A, 1)
        return min
*/
void ExtractMin(HEAP *heap, ELEMENT **V) {
    // Check if the heap is empty
    if (heap->size < 1) {
        fprintf(stderr, "Error: heap is empty\n");
        return;
    }

    // The minimum element is at the root
    int minIndex = heap->H[1];
    V[minIndex]->pos = 0; // Mark the element as not in the heap

    // Move the last element to the root
    heap->H[1] = heap->H[heap->size];
    V[heap->H[1]]->pos = 1;
    heap->size--; // Decrease the size of the heap

    // Restore the heap property
    MinHeapify(heap, V, 1);
}

// Function to decrease the key of an element in the heap
/*
DECREASE-KEY(A, i, key)
    if key > A[i] then
        “error: new key is larger than current key”
    else
        A[i] := key
        while i > 1 and A[PARENT(i)] > A[i]
            exchange A[i] with A[PARENT(i)]
            i := PARENT(i)
*/
void DecreaseKey(HEAP *heap, ELEMENT **V, int index, double newKey, int n) {
    // Update the key
    V[index]->key = newKey;

    // Restore the heap property by moving the element up
    int i = V[index]->pos;
    while (i > 1 && V[heap->H[i / 2]]->key > V[heap->H[i]]->key) {
        // Swap the element with its parent
        int temp = heap->H[i];
        heap->H[i] = heap->H[i / 2];
        heap->H[i / 2] = temp;

        // Update the positions in the ELEMENT array
         V[heap->H[i]]->pos = i;
         V[heap->H[i / 2]]->pos = i / 2;
        // Move up to the parent (parent(i) = i/2)
        i = i / 2;
    }
}

// Function to insert an element into the heap
/*
MIN-HEAP-INSERT(A, key)
    heap-size[A]++
    i := heap-size[A]
    A[i] = ∞
    HEAP-DECREASE-KEY(A, i, key)
*/
void Insertion(HEAP *heap, ELEMENT **V, int index, int n) {
    // Insert the element into the heap
    heap->size++; // Increase heap size
    heap->H[heap->size] = index; // Add the element to the end of the heap array
     V[index]->pos = heap->size; // Update the position of the element in the heap

    // Decrease the key to the actual value
    DecreaseKey(heap, V, index, V[index]->key, n);
}
