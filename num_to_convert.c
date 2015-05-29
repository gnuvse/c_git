// Преобразования целого числа из одной системы счисления в другую
#include <stdio.h>

int g_converted_number[64];
long int g_num_to_convert = 1;
int g_base, g_index = 0;


void get_num();
void get_base();
void convert_number();
void print_converted_num();

int main() {
	int tmp = 1;

	while (tmp >= 0) {
		// Заново присваиваем 1, потому что глобальная переменная,
		// чтобы продолжить ввод
		g_num_to_convert = 1;
		g_base = 1;

		// Получить число и основание
		get_num();
		while(g_base < 2 || g_base > 36) {
			get_base();
		}

		// Преобразовать в указанное основание
		convert_number();

		// Отобразить результат в обратном порядке
		// от n-1 до 0
		print_converted_num();
		printf("For exit enter(-1): ");
		scanf("%i", &tmp);
		printf("\n");
	}
	return 0;
}


void print_converted_num() {
	const char g_base_digits[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int next_digit;
	for (g_index -= 1; g_index >= 0; g_index--) {
		next_digit = g_converted_number[g_index];
		printf("%c", g_base_digits[next_digit]);
	}
	printf("\n");
}


void convert_number() {
	do {
		g_converted_number[g_index] = g_num_to_convert % g_base;
		g_index++;
		g_num_to_convert /= g_base;
	} while (g_num_to_convert != 0);
}


void get_base() {
	printf("base(2 .. 36)? ");
	scanf("%i", &g_base);
}


void get_num() {
	printf("Number to be converted? ");
	scanf("%li", &g_num_to_convert);
}
