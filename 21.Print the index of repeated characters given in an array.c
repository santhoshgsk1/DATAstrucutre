#include <stdio.h>
#include <string.h>
void printRepeatedIndices(const char *str, const int *indices, int numIndices) {
    int n = strlen(str);
    int i;
    for (i = 0; i < numIndices; i++) {
        if (indices[i] >= 0 && indices[i] < n) {
            printf("Index of repeated character '%c': %d\n", str[indices[i]], indices[i]);
        }
    }
}

int main() {
    const char *inputStr = "programming";
    int repeatedIndices[] = {1, 3, 5, 8}; 

    int numIndices = sizeof(repeatedIndices) / sizeof(repeatedIndices[0]);

    printRepeatedIndices(inputStr, repeatedIndices, numIndices);

    return 0;
}

