#include <stdio.h>

int main() {
    int regNos[] = {123, 456, 789, 101, 202};
    int size = sizeof(regNos) / sizeof(regNos[0]);
    int regNoToSearch = 789;
    int found = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (regNos[i] == regNoToSearch) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Registration number %d found in the array.\n", regNoToSearch);
    } else {
        printf("Registration number %d not found in the array.\n", regNoToSearch);
    }

    return 0;
}

