#include <stdio.h>
#include <stdbool.h>

void prime_num(int limit_sequence_prime_num);

int main() {
	int limit_sequence_prime_num;

	printf("---------------------------------------------------\n");
	printf("This program displays the sequence of prime numbers\n");
	printf("---------------------------------------------------\n");

	printf("Please enter limit_sequence_prime_num: \n");
	scanf("%i", &limit_sequence_prime_num);
	printf("---------------------------------------------------\n");

	prime_num(limit_sequence_prime_num);

	return 0;
}

void prime_num(int limit_sequence_prime_num) {
	bool is_prime;

	for (int p = 2; p <= limit_sequence_prime_num; p++) {
		is_prime = 1;

		// Если больше двух и четное
        if ( (p > 2) && (p % 2 == 0) ) {
			continue;
		}
        else {
			for (int q = 2; (q < p) && (is_prime != 0) ; q++)
				if (p % q == 0) {
					is_prime = 0;
					break;
				}
		}

		if (is_prime != 0)
			printf("%i, ", p);
	}

	printf("\n");
	printf("---------------------------------------------------\n");
}
