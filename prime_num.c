#include <stdio.h>
#include <stdbool.h>

void prime_num(int max_prime);

int main() {
	int max_prime;

	printf("---------------------------------------------------\n");
	printf("This program displays the sequence of prime numbers\n");
	printf("---------------------------------------------------\n");

	printf("Please enter max_prime: \n");
	scanf("%i", &max_prime);
	printf("---------------------------------------------------\n");


	prime_num(max_prime);

	return 0;
}

void prime_num(int max_prime) {
	bool is_prime;

	for (int p = 2; p <= max_prime; p++) {
		is_prime = 1;

		// Если больше двух и четное
		if ( (p > 2) && (p % 2 == 0) ) {
			continue;
		}
		else {
			for (int q = 2; (q < p) && (is_prime) ; q++)
				if (p % q == 0) {
					is_prime = 0;
					break;
				}
		}


		if (is_prime)
			printf("%i, ", p);
	}

	printf("\n");
	printf("---------------------------------------------------\n");
}
