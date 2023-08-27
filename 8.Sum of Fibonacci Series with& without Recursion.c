#include <stdio.h>

int fibonacciIterative(int n) {
	int i;
    if (n <= 0) {
        return 0;
    }

    int prev = 0, curr = 1;
    int sum = prev + curr;

    for (i = 2; i <= n; i++) {
        int next = prev + curr;
        sum += next;
        prev = curr;
        curr = next;
    }

    return sum;
}

int fibonacciRecursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int main() {
    int n = 5;
    int iterativeSum = fibonacciIterative(n);
    printf("\nSum of first %d Fibonacci numbers (iterative): %d\n", n, iterativeSum);
    int recursiveSum = fibonacciRecursive(n);
    printf("\nSum of first %d Fibonacci numbers (recursive): %d\n", n, recursiveSum);

    return 0;
}

