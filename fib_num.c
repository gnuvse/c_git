// генерация чисел Фибоначчи с помощью массиов переменной длины
#include <stdio.h>


int main() {
	int num_fibs;
    printf("How many Fibonacci numbers do you wand(1 and 75): \n");
    scanf("%i", &num_fibs);

	int fib_num[num_fibs];
	fib_num[0] = 0;
	fib_num[1] = 1;


    for (int i = 2; i < num_fibs; i++) {
		fib_num[i] = fib_num[i - 2] + fib_num[i - 1];
    }

	for (int i = 0; i < num_fibs; i++) {
		printf("fib_num = %i\n", fib_num[i]);
    }

	return 0;
}

