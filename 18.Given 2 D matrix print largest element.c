#include <stdio.h>

int findLargestElement(int matrix[][3], int numRows, int numCols) {
    int maxElement = matrix[0][0];
	int i,j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }

    return maxElement;
}

int main() {
    int matrix[][3] = {{12, 23, 34}, {45, 56, 67}, {78, 89, 90}};
    int numRows = 3;
    int numCols = 3;

    int largestElement = findLargestElement(matrix, numRows, numCols);

    printf("The largest element in the matrix is: %d\n", largestElement);

    return 0;
}

