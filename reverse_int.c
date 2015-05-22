#include <stdio.h>


void reverse_nonnegative_int(int n);
void reverse_int(int n);

int main() {
	int n;

	printf("Please, enter number: \n");
	scanf("%i", &n);
	reverse_int(n);
	return 0;
}

void reverse_nonnegative_int(int n) {
	int right_digit;
	do {
		right_digit = n % 10;
		printf("%i", right_digit);
		n /= 10;
	} while (n != 0);
	printf("\n");
}

void reverse_int(int n) {
	if (n < 0) {
		printf("-");
		reverse_nonnegative_int(-n);
	}
	else
		reverse_nonnegative_int(n);
}
