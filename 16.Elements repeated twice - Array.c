#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Elements repeated twice: ");
    int i,j;
    for (i = 0; i < size; i++) {
        int count = 0;
        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        if (count == 2) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 5, 2, 6, 7, 4, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findDuplicates(arr, size);
    
    return 0;
}

