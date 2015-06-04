#include <stdio.h>
#include <stdlib.h>
#define SIZE 500

int input_number(int buf_size, char *buf);
void output_number(int count_digits, char *buf);

int main() {
	char *buf = malloc(sizeof(char) * SIZE);
	int count_digits;

	count_digits = input_number(SIZE, buf);

	printf("count = %i\n", count_digits);

	output_number(count_digits, buf);

	return 0;
}

void output_number(int count_digits, char *buf) {
	for (int i = 0; i < count_digits; i++)
		printf("%i", buf[i]);

	printf("\n");
}


int input_number(int buf_size, char *buf) {
	printf("Input big number: ");
	scanf("%500s", buf);
	int count_digits = 0;

	// Преобразуем в число
	// Элементы без цифры заполняются -48
	for (int i = 0; i < buf_size; i++)
		buf[i] = buf[i] - '0';

	// Считаем количество цифр в числе
	while (*buf++ != -48)
		count_digits++;

	return count_digits;
}
