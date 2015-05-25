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
	else {
		int p[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		p[1] = 0;
		for (int i = 2; i < n; i++) {
			if (p[i] != 0)
				for (int j = i * 2; j < n; j += i)
					p[j] = 0;
		}

		for (int i = 0; i < n; i++) {
			if (p[i] != 0)
				printf("%i \n", p[i]);
		}
	}
	return 0;
}
