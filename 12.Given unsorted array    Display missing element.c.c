#include <stdio.h>

int findMissingElement(int arr[], int n, int minRange, int maxRange) {
    int missingElement = 0;
    int present[maxRange - minRange + 1];
    int i;
    for (i = 0; i < maxRange - minRange + 1; i++) {
        present[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (arr[i] >= minRange && arr[i] <= maxRange) {
            present[arr[i] - minRange] = 1;
        }
    }
    for (i = 0; i < maxRange - minRange + 1; i++) {
        if (present[i] == 0) {
            missingElement = i + minRange;
            break;
        }
    }

    return missingElement;
}

int main() {
    int arr[] = {5, 3, 1, 7, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int minRange = 1; 
    int maxRange = 10; 

    int missing = findMissingElement(arr, n, minRange, maxRange);

    if (missing != 0) {
        printf("Missing element: %d\n", missing);
    } else {
        printf("No missing element found.\n");
    }

    return 0;
}

