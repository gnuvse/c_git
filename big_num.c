#include <stdio.h>
#include <stdlib.h>

#define SIZE 500

int input_number(int buf_size, char *buf);
void output_number(int count_digits, char *buf);
char *reverse_number(int count_digits, char *buf);
char *diff_number(int count_digits, char *buf1, char *buf2);

int main() {
	char *buf1 = malloc(sizeof(char) * SIZE);
	char *buf2 = malloc(sizeof(char) * SIZE);
	char *res = malloc(sizeof(char) * SIZE);
	int count_digits;
	int count;

	count_digits = input_number(SIZE, buf1);
	printf("count = %i\n", count_digits);
	count = input_number(SIZE, buf2);
	printf("count = %i\n", count);

	output_number(count_digits, buf1);
	output_number(count_digits, buf2);

	buf1 = reverse_number(count_digits, buf1);
	buf2 = reverse_number(count_digits, buf2);
	res = diff_number(count_digits, buf1, buf2);
	//res = reverse_number(count_digits, res);

	output_number(count_digits, res);


	return 0;
}


char *diff_number(int count_digits, char *buf1, char *buf2) {
	char *res = malloc(sizeof(char) * count_digits);

	for (int i = 0; i < count_digits; i++) {
		printf("buf1 = %i, buf1 = %i\n", buf1[i], buf2[i]);
		if (buf1[i] - buf2[i] < 0) {
			res[i] = (buf1[i] + 10) - buf2[i];
			printf("%i\n", res[i]);
		}
		else
			res[i] = buf1[i] - buf2[i];
	}

	return res;
}


char *reverse_number(int count_digits, char *buf) {
	char *buf_reverse = malloc(sizeof(char) * count_digits);

	for (int i = 0, j = count_digits - 1; i < count_digits; i++, j--)
		buf_reverse[i] = buf[j];

	return buf_reverse;
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
