#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Please, enter number: \n");
    scanf("%i", &n);

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    printf("Sum digits = %i\n", sum);

    return 0;
}
