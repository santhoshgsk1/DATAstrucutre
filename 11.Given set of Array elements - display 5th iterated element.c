#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (n >= 5) {
        int fifthElement = arr[4];  
        printf("The 5th iterated element is: %d\n", fifthElement);
    } else {
        printf("The array doesn't have enough elements for the 5th iteration.\n");
    }
    
    return 0;
}

