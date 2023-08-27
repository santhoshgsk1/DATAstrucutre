#include <stdio.h>

int sum_fibonacci_iterative(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    int fib[2] = {0, 1};
    int total = 1,i;  

    for (i = 2; i < n; i++) {
        fib[i % 2] = fib[(i - 1) % 2] + fib[(i - 2) % 2];
        total += fib[i % 2];
    }

    return total;
}

int main() {
	printf("SANTHOSH KUMAR 192224286\n");
    int n = 10;  
    printf("Sum of Fibonacci series without recursion: %d\n", sum_fibonacci_iterative(n));
    return 0;
}

