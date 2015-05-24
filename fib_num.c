// генерация чисел Фибоначчи с помощью массиов переменной длины
#include <stdio.h>


int main() {
	int num_fibs;
	printf("How many Fibonacci numbers do you wand(1 and 75): \n");
	scanf("%i", &num_fibs);

	if (num_fibs < 1 || num_fibs > 75) {
		printf("Error! Bad number.");
		return 1;
	}

	unsigned long long fib[num_fibs];
	fib[0] = 0;
	fib[1] = 1;


	for (int i = 2; i < num_fibs; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}

	for (int i = 0; i < num_fibs; i++) {
		printf("fib[%i] = %llu\n", i, fib[i]);
	}

	return 0;
}

