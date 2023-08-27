#include <stdio.h>

void printFrequentNumbers(int arr[], int size) {
    int maxNumber = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }
    int frequency[maxNumber + 1];
    for (i = 0; i <= maxNumber; i++) {
        frequency[i] = 0;
    }
    for (i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }
    
    printf("Frequently repeated numbers and their counts:\n");
    for (i = 0; i <= maxNumber; i++) {
        if (frequency[i] > 1) {
            printf("%d (Count: %d)\n", i, frequency[i]);
        }
    }
}

int main() {
    int arr[] = {2, 3, 4, 5, 2, 6, 7, 4, 8, 9, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printFrequentNumbers(arr, size);
    
    return 0;
}

