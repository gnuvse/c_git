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
int number_digits(int n);
void print_num(int reverse_n);
void num_to_str(int n, int count);



int main() {
	int n;
	printf("Please, enter number: \n");
	scanf("%i", &n);

	num_to_str(n, number_digits(n));

	return 0;
}



void num_to_str(int n, int count) {
	if (count > 8)
		printf("Error! Output abroad\n");
	else
		print_num(reverse_nonnegative_int(n, count) );
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


// Делаем реверс числа пользователя
int reverse_nonnegative_int(int n, int count) {
	int right_digit;
	int reverse_n = 0;
	int tmp_count = count;
	int multi;


	for (int i = 0; i < count; i++) {
		multi = 1;
		right_digit = n % 10;

		// 10 в степени tmp_count
		// j > 1 сокращаем такты цикла на 1
		// можно записать tmp_count - 1
		for (int j = tmp_count; j > 1; j--) {
			multi *= 10;
		}

		reverse_n += right_digit * multi;

		// Уменьшаем степень
		tmp_count--;

		// Получаем следующую цифру в числе убирая  сотни, десятки и т.д
		// Пример: 953 / 10 == 95
		n /= 10;
	}

	return reverse_n;
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
