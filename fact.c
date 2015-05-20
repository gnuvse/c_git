#include <stdio.h>

int main() {
    int n, fact;

    printf("Please, enter number: \n");
    scanf("%i", &n);

    fact = 1;
    if (n >= 1) {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("%i! = %i\n", n, fact);
    }
    else {
        printf("Error, n = 0");
    }

    return 0;
}
