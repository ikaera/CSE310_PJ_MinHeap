// Irakli Eradze  ASU ID (emplid): 122286823i1
//
#include <stdio.h>
#include <string.h>
#include "util.h"

// Function to parse the next instruction from stdin
int nextInstruction(char *Word, int *index, double *newKey) {
    int returnV;
    char line[256];

    // Read a line from stdin
    if (fgets(line, sizeof(line), stdin)) {
        // Parse the first word (instruction)
        returnV = sscanf(line, "%s", Word);

        // Check the instruction and parse additional parameters if necessary
        if (strcmp(Word, "Stop") == 0) {
            return 1;
        } else if (strcmp(Word, "Read") == 0) {
            return 1;
        } else if (strcmp(Word, "PrintArray") == 0) {
            return 1;
        } else if (strcmp(Word, "PrintHeap") == 0) {
            return 1;
        } else if (strcmp(Word, "BuildHeap") == 0) {
            return 1;
        } else if (strcmp(Word, "Insert") == 0) {
            returnV = sscanf(line, "%s %d", Word, index);
            if (returnV == 2) {
                return 1;
            } else {
                return 0;
            }
        } else if (strcmp(Word, "ExtractMin") == 0) {
            return 1;
        } else if (strcmp(Word, "DecreaseKey") == 0) {
            returnV = sscanf(line, "%s %d %lf", Word, index, newKey);
            if (returnV == 3) {
                return 1;
            } else {
                return 0;
            }
        } else if (strcmp(Word, "Write") == 0) {
            return 1;
        } else {
            return 0; // Invalid instruction
        }
    } else {
        return -1; // End of input
    }
}
