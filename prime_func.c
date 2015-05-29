#include <stdio.h>
#include <stdbool.h>

bool prime_func(int n);

int main() {
	printf("prime? %i", prime_func(97));
	return 0;
}

bool prime_func(int n) {
	bool is_prime = 1;
	if (n == 2)
		return 1;

	for (int i = 3; i < n; i += 2) {
		if (n % i == 0)
			is_prime = 0;
	}

	return is_prime;
}
