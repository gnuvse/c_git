#include <stdio.h>

int main() {
    const int limit = 5;
    char c = '$';

    for (int i = 1; i <= limit; i++) {
        for (int j = 0; j < i; j++)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}
