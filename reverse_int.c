#include <stdio.h>

void reverse(int n);

int main() {
	int n;
	
	printf("Please, enter number: \n");
	scanf("%i", &n);
	
	reverse(n);
	
	return 0;
}

void reverse(int n) {
	int right_digit;
	while (n != 0) {
		right_digit = n % 10;
		printf("%i", right_digit);
		n /= 10;
	}
	printf("\n");
}
