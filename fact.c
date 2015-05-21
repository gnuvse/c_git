#include <stdio.h>

int main() {
    unsigned long long fact;
    unsigned int n;

    printf("Please, enter number(1-20): \n");
    scanf("%ulli", &n);

    fact = 1;
    if (n >= 1 && n <= 20) {
        for (unsigned int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("%i! = %lli\n", n, fact);
    }
    else {
        printf("Error, n = 0");
    }

    return 0;
}
