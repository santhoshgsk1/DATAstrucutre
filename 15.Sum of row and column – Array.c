#include <stdio.h>

void calculateRowSum(int matrix[][3], int numRows, int numCols, int rowSum[]) {
	int i,j;
    for (i = 0; i < numRows; i++) {
        rowSum[i] = 0;  
        for (j = 0; j < numCols; j++) {
            rowSum[i] += matrix[i][j];
        }
    }
}

void calculateColumnSum(int matrix[][3], int numRows, int numCols, int colSum[]) {
	int i,j;
    for (j = 0; j < numCols; j++) {
        colSum[j] = 0;  
        for (i = 0; i < numRows; i++) {
            colSum[j] += matrix[i][j];
        }
    }
}

void printArray(int arr[], int size) {
	int i,j;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int numRows = 3;
    int numCols = 3,i,j;
    
    int rowSum[numRows];
    int colSum[numCols];
    
    calculateRowSum(matrix, numRows, numCols, rowSum);
    calculateColumnSum(matrix, numRows, numCols, colSum);
    
    printf("Matrix:\n");
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRow Sums:\n");
    printArray(rowSum, numRows);
    
    printf("\nColumn Sums:\n");
    printArray(colSum, numCols);
    
    return 0;
}

