// Преобразования целого числа из одной системы счисления в другую
#include <stdio.h>

int convert_number[64];
long int num_to_convert;
int next_digit, base, index = 0;


void get_num();
void get_base();

int main() {
	const char base_digits[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


	// Получить число и основание
	get_num();
	get_base();

    	// Преобразовать в указанное основание
	do {
		convert_number[index] = num_to_convert % base;
		index++;
		num_to_convert /= base;
	} while (num_to_convert != 0);

	// Отобразить результат в обратном порядке
	// от n-1 до 0
	for (index -= 1; index >= 0; index--) {
		next_digit = convert_number[index];
		printf("%c", base_digits[next_digit]);
	}

	printf("\n");
	return 0;
}

void get_base() {
	printf("Base(2 .. 36)? ");
	scanf("%i", &base);

	if (base < 2 && base > 36) {
		printf("Error, incorrect data");
		base = 10;
	}
}

void get_num() {
	printf("Number to be converted? ");
	scanf("%li", &num_to_convert);
}
