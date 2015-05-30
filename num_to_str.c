#include <stdio.h>

void print_num(int n);
int number_digits(int n);
void print_digit(int n);
int num_to_str(int n, int count);



int main() {
	int n;
	printf("Please, enter number: \n");
	scanf("%i", &n);


	return num_to_str(n, number_digits(n));
}



int num_to_str(int n, int count) {
	if (count > 8 || n <= 0) {
		printf("----------------------\n");
		printf("Error! incorrect data:\n");
		printf("----------------------\n");
		return 1;
	}
	else {
		print_num(n);
		return 0;
	}
}


// Находим количество цифр в числе.
int number_digits(int n) {
	int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}

	return count;
}



void print_num(int n) {
	int next_num;
	int count = number_digits(n);
	int multi = 1;


	for (int j = count; j > 1; j--) {
		multi *= 10;
	}


	for (int i = 0; i < count; i++) {
		next_num = (n / multi) % 10;
		print_digit(next_num);
		multi /= 10;
	}
}



void print_digit(int n) {
	switch (n) {
		case 0:
			printf("zero ");
			break;
		case 1:
			printf("one ");
			break;
		case 2:
			printf("two ");
			break;
		case 3:
			printf("three ");
			break;
		case 4:
			printf("four ");
			break;
		case 5:
			printf("five ");
			break;
		case 6:
			printf("six ");
			break;
		case 7:
			printf("seven ");
			break;
		case 8:
			printf("eight ");
			break;
		case 9:
			printf("nine ");
			break;
		default:
			printf("Error!\n");
			break;
	}
}
