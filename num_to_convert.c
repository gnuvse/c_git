// Преобразования целого числа из одной системы счисления в другую
#include <stdio.h>

int main() {
	const char base_digits[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
	};
	int convert_number[64];
	long int num_to_convert;
	int next_digit, base, index = 0;

	// Получить число и основание
	printf("Number to be converted? ");
	scanf("%li", &num_to_convert);
	printf("Base(2, 16)? ");
	scanf("%i", &base);

	if (base != 2 && base != 16) {
		printf("Error, incorrect data");
		return 1;
    }
	else {
    	// Преобразовать в указанное основание
		do {
			convert_number[index] = num_to_convert % base;
			index++;
			num_to_convert /= base;
		} while (num_to_convert != 0);
	}

	// Отобразить результат в обратном порядке
	// от n-1 до 0
	for (index -= 1; index >= 0; index--) {
		next_digit = convert_number[index];
		printf("%c", base_digits[next_digit]);
	}

	return 0;
}