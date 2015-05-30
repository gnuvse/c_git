// Решето Эратосфена
#include <stdio.h>


int main() {
	int n;
	printf("Enter n: ");
	scanf("%i", &n);

	if ( (n < 3) || (n > 65000) ) {
		printf("Bad number.\n");
		return 1;
	}

	int p[n];
	for (int i = 0; i < n; i++) {
		p[i] = 1;
	}

	p[1] = 0;
	for (int i = 2; i < n; i++) {
		if (p[i]) {
			for (int j = i * 2; j < n; j += i)
				p[j] = 0;
		}
	}

	for (int i = 2; i < n; i++) {
		if (p[i])
			printf("%i \n", i);
	}

	return 0;
}
