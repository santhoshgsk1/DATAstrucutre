#include <stdio.h>
#include <string.h>
void sortString(char *str) {
    int n = strlen(str);
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
	printf("Mahesh 192210708\n");
    char inputStr[] = "zxyabc";

    printf("Original string: %s\n", inputStr);

    sortString(inputStr);

    printf("Sorted string: %s\n", inputStr);

    return 0;
}

