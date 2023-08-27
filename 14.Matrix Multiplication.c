#include <stdio.h>

void matrixMultiply(int A[][3], int B[][2], int C[][2], int rowsA, int colsA, int colsB) {
	int i,j,k;
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][2], int rows, int cols) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][3] = {{2, 3, 4}, {5, 6, 7}};
    int B[3][2] = {{1, 2}, {2, 3}, {3, 4}};
    int C[2][2];

    int rowsA = 2;
    int colsA = 3;
    int colsB = 2;

    matrixMultiply(A, B, C, rowsA, colsA, colsB);

    printf("Matrix A:\n");
    printMatrix(A, rowsA, colsA);

    printf("\nMatrix B:\n");
    printMatrix(B, colsA, colsB);

    printf("\nMatrix C (Result of A * B):\n");
    printMatrix(C, rowsA, colsB);

    return 0;
}

