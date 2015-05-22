#include <stdio.h>

int main() {
	unsigned long long fact;
	unsigned int n;

	printf("Please, enter number(1-20): \n");
	scanf("%ui", &n);


	if (n < 1 && n > 20) {
		printf("Bad interval for n");
		return 1;
	}

	fact = 1;
	for (unsigned int i = 1; i <= n; i++)
		fact *= i;

	printf("%i! = %lli\n", n, fact);

	return 0;
}
