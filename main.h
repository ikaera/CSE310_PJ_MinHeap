// Irakli Eradze  ASU ID (emplid): 1222868231

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
#include "util.h"

// Function prototypes
int nextInstruction(char *Word, int *index, double *newKey);
void handleRead(HEAP **pHeap, ELEMENT ***V, int *n, const char *inputFile);
void handlePrintArray(ELEMENT **V, int n);
void handlePrintHeap(HEAP *pHeap);
void handleBuildHeap(HEAP *pHeap, ELEMENT **V);
void handleInsert(HEAP *pHeap, ELEMENT **V, int index, int n);
void handleExtractMin(HEAP *pHeap, ELEMENT **V);
void handleDecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey, int n);
void handleWrite(ELEMENT **V, int n, const char *outputFile);

#endif // MAIN_H
