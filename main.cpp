// Irakli Eradze  ASU ID (emplid): 1222868231

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "data_structures.h"
#include "util.h"
#include "main.h"
// #include "heap.cpp"

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <I-File> <O-File>\n", argv[0]);
        exit(1);
    }

    // Initialize variables
    ELEMENT **V = NULL;
    HEAP *pHeap = NULL;
    int n = 0;
    char Word[100];
    int index;
    double newKey;

    // Main loop to process instructions
    while (1) {
        int returnV = nextInstruction(Word, &index, &newKey);

        if (returnV == 0) {
            fprintf(stdout, "Warning: Invalid instruction\n");
            continue;
        }

        if (strcmp(Word, "Stop") == 0) {
            fprintf(stdout, "Instruction: Stop\n");
            break;
        }

        if (strcmp(Word, "Read") == 0) {
            handleRead(&pHeap, &V, &n, argv[1]);
            continue;
        }

        if (strcmp(Word, "PrintArray") == 0) {
            handlePrintArray(V, n);
            continue;
        }

        if (strcmp(Word, "PrintHeap") == 0) {
            handlePrintHeap(pHeap);
            continue;
        }

        if (strcmp(Word, "BuildHeap") == 0) {
            handleBuildHeap(pHeap, V);
            continue;
        }

        if (strcmp(Word, "Insert") == 0) {
            handleInsert(pHeap, V, index, n);
            continue;
        }

        if (strcmp(Word, "ExtractMin") == 0) {
            handleExtractMin(pHeap, V);
            continue;
        }

        if (strcmp(Word, "DecreaseKey") == 0) {
            handleDecreaseKey(pHeap, V, index, newKey, n);
            continue;
        }

        if (strcmp(Word, "Write") == 0) {
            handleWrite(V, n, argv[2]);
            continue;
        }
    }

    // Free allocated memory
    if (V) {
        for (int i = 1; i <= n; i++) {
            free(V[i]);
        }
        free(V);
    }
    if (pHeap) {
        free(pHeap->H);
        free(pHeap);
    }

    return 0;
}

// Function to handle the Read instruction
void handleRead(HEAP **pHeap, ELEMENT ***V, int *n, const char *inputFile) {
    fprintf(stdout, "Instruction: Read\n");

    FILE *fp = fopen(inputFile, "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", inputFile);
        return;
    }

    // Read the number of elements
    fscanf(fp, "%d", n);

    // Allocate memory for the array of elements
    *V = (ELEMENT **)calloc(*n + 1, sizeof(ELEMENT *));
    for (int i = 1; i <= *n; i++) {
        (*V)[i] = (ELEMENT *)calloc(1, sizeof(ELEMENT));
        fscanf(fp, "%lf", &(*V)[i]->key);
        (*V)[i]->index = i;
        (*V)[i]->pos = 0;
    }

    fclose(fp);

    // Allocate memory for the heap
    *pHeap = (HEAP *)calloc(1, sizeof(HEAP));
    (*pHeap)->capacity = *n;
    (*pHeap)->size = 0;
    (*pHeap)->H = (int *)calloc(*n + 1, sizeof(int));
}

// Function to handle the PrintArray instruction
void handlePrintArray(ELEMENT **V, int n) {
    fprintf(stdout, "Instruction: PrintArray\n");

    if (V == NULL) {
        fprintf(stderr, "Error: array is NULL\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        fprintf(stdout, "%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
    }
}

// Function to handle the PrintHeap instruction
void handlePrintHeap(HEAP *pHeap) {
    fprintf(stdout, "Instruction: PrintHeap\n");

    if (pHeap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }

    fprintf(stdout, "Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);
    for (int i = 1; i <= pHeap->size; i++) {
        fprintf(stdout, "H[%d] = %d\n", i, pHeap->H[i]);
    }
}

// Function to handle the BuildHeap instruction
void handleBuildHeap(HEAP *pHeap, ELEMENT **V) {
    fprintf(stdout, "Instruction: BuildHeap\n");

    if (pHeap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }

    pHeap->size = pHeap->capacity;
    for (int i = 1; i <= pHeap->size; i++) {
        V[i]->pos = i;
        pHeap->H[i] = i;
    }

    BuildMinHeap(pHeap, V);
}

// Function to handle the Insert instruction
void handleInsert(HEAP *pHeap, ELEMENT **V, int index, int n) {
    fprintf(stdout, "Instruction: Insert %d\n", index);

    if (index < 1 || index > n) {
        fprintf(stderr, "Error: index out of bound\n");
        return;
    }

    if (V[index]->pos != 0) {
        fprintf(stderr, "Error: V[%d] already in the heap\n", index);
        return;
    }

    Insertion(pHeap, V, index, n);
    fprintf(stdout, "Element V[%d] inserted into the heap\n", index);
}

// Function to handle the ExtractMin instruction
void handleExtractMin(HEAP *pHeap, ELEMENT **V) {
    fprintf(stdout, "Instruction: ExtractMin\n");

    if (pHeap == NULL) {
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }

    if (pHeap->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return;
    }

    ExtractMin(pHeap, V);
}

// Function to handle the DecreaseKey instruction
void handleDecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey, int n) {
    fprintf(stdout, "Instruction: DecreaseKey %d %lf\n", index, newKey);

    if (index < 1 || index > n) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }

    if (V[index]->pos == 0) {
        fprintf(stderr, "Error: V[%d] not in the heap\n", index);
        return;
    }

    if (newKey >= V[index]->key) {
        fprintf(stderr, "Error: invalid call to DecreaseKey\n");
        return;
    }

    DecreaseKey(pHeap, V, index, newKey, n);
}

// Function to handle the Write instruction
void handleWrite(ELEMENT **V, int n, const char *outputFile) {
    fprintf(stdout, "Instruction: Write\n");

    FILE *fp = fopen(outputFile, "w");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", outputFile);
        return;
    }

    for (int i = 1; i <= n; i++) {
        fprintf(fp, "%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
    }

    fclose(fp);
}
