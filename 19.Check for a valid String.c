#include <stdio.h>
#include <string.h>
int isValidString(const char *str) {
    if (str != NULL && str[0] != '\0') {
        return 1;
    }
    return 0;
}

int main() {
	printf("Mahesh 192210708\n");
    const char *inputStr = "Hello, world!";

    if (isValidString(inputStr)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}

