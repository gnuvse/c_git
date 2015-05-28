#include <stdio.h>

unsigned long int fact_recurs(unsigned int n);

int main() {
	unsigned int n;
	printf("Please enter n:\n");
	scanf("%ui", &n);


	for (unsigned int i = 1; i <= n; i++) {
		printf("%2u! = %li\n",i, fact_recurs(i));
	}

	return 0;
}

unsigned long int fact_recurs(unsigned int n) {
	unsigned long int result;
	if (n == 0)
		result = 1;
	else
		result = n * fact_recurs(n - 1);
	return result;
}
