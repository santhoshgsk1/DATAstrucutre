#include <stdio.h>

void merge(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter elements of the first array:\n");
    int arr1[size1];
    int i;
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter elements of the second array:\n");
    int arr2[size2];
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[size1 + size2];

    merge(arr1, size1, arr2, size2, merged);

    printf("Merged Array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

