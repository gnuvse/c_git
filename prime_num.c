#include <stdio.h>
#include <stdbool.h>

void prime_num(int sequence);

int main() {
	int sequence;

	printf("---------------------------------------------------\n");
	printf("This program displays the sequence of prime numbers\n");
	printf("---------------------------------------------------\n");

	printf("Please enter sequence: \n");
	scanf("%i", &sequence);
	printf("---------------------------------------------------\n");

	prime_num(sequence);

	return 0;
}

void prime_num(int sequence) {
	bool is_prime;

	for (int p = 2; p <= sequence; p++) {
		is_prime = 1;
		for (int q = 2; q < p; q++) {
			if (p % q == 0)
				is_prime = 0;
		}

		if (is_prime != 0)
			printf("%i, ", p);
	}

	printf("\n");
	printf("---------------------------------------------------\n");
}
