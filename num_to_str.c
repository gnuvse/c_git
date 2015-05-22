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

int reverse_nonnegative_int(int n, int count);
int number_digits(int n, int count);
void print_num(int reverse_n);
void num_to_str(int n, int count);





int main() {
	int n, count = 0;
	printf("Please, enter number: \n");
	scanf("%i", &n);

	num_to_str(n, number_digits(n, count));

	return 0;
}


void num_to_str(int n, int count) {
	if (count > 8)
		printf("Error! Output abroad\n");
	else
		print_num(reverse_nonnegative_int(n, count) );
}


// В этой функции мы находим количество цифр в числе.
int number_digits(int n, int count) {
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;
}



int reverse_nonnegative_int(int n, int count) {
	int right_digit;
	int reverse_n = 0;
	do {
		right_digit = n % 10;
        // В данном выборе, мы получаем десятки, сотни, тысячи.
        // Если вводим 953, то получим в right_digit == 3.
        // count == 2, соответственно получаем 300 и тд, до 359
        // т.е. делаем реверс числа
        // PS. count == 2, потому что отчет с 0
		switch (count) {
			case 1:
				reverse_n = reverse_n + right_digit * 10;
				break;
			case 2:
				reverse_n = reverse_n + right_digit * 100;
				break;
			case 3:
				reverse_n = reverse_n + right_digit * 1000;
				break;
			case 4:
				reverse_n = reverse_n + right_digit * 10000;
				break;
			case 5:
				reverse_n = reverse_n + right_digit * 100000;
				break;
			case 6:
				reverse_n = reverse_n + right_digit * 1000000;
				break;
			case 7:
				reverse_n = reverse_n + right_digit * 10000000;
				break;
			case 8:
				reverse_n = reverse_n + right_digit * 100000000;
				break;
			default:
				printf("Error!\n");
				break;
        }
        count--;
		n /= 10;
	} while (n != 0);

	// не знаю в чем дело, но к реверсивному числу добавляется 0
	// таким не хитрым способом избавляемся от 0
	return reverse_n / 10;
}


// Теперь мы снова меняем делаем реверс и уже выводим наши цифры словами
void print_num(int reverse_n) {
	int right_digit;
	do {
		right_digit = reverse_n % 10;
		switch (right_digit) {
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
		reverse_n /= 10;
	} while (reverse_n != 0);
	printf("\n");
}
