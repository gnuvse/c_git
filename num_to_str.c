/*
	Задача 6.6
	Напишите программу, которая принимает число,
	введенное пользователем и отображает значение
	каждой цифры на английском языке

	input: 953
	output: nine five three

	PS. Скорее всего эту задачу можно решить другим
	способом, но я смог так.
	Далее жесткий быдлокод
*/

#include <stdio.h>

void print_num(int n, int count);
int number_digits(int n);
void print_digit(int n);
void num_to_str(int n, int count);



int main() {
	int n;
	printf("Please, enter number: \n");
	scanf("%i", &n);

	num_to_str(n, number_digits(n));

	return 0;
}



void num_to_str(int n, int count) {
	if (count > 8 || n <= 0) {
		printf("Error! Incorrect data:\n");
		printf("overflow or n <= 0\n");
	}
	else
		print_num(n, number_digits(n));
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



void print_num(int n, int count) {
	int tmp_count = count;
	int multi;


	for (int i = 0; i < count; i++) {
		multi = 1;

		for (int j = tmp_count; j > 1; j--) {
			multi *= 10;
		}
		tmp_count--;

		print_digit((n / multi) % 10);
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
