// Программа производит разность двух чисел с большим количеством знаков
// Условие: buf1 > buf2

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

	int count1;
	int count2;


	count1 = input_number(SIZE, buf1);
	printf("count = %i\n", count1);
	count2 = input_number(SIZE, buf2);
	printf("count = %i\n", count2);


	output_number(count1, buf1);
	output_number(count2, buf2);

	char *buf1_reversed = reverse_number(count1, buf1);
	char *buf2_reversed = reverse_number(count2, buf2);
	char *res_diff = diff_number(count1, buf1_reversed, buf2_reversed);
	char *res = reverse_number(count1, res_diff);

	output_number(count1, res);

	free(buf1);
	free(buf2);
	free(buf1_reversed);
	free(buf2_reversed);
	free(res);
	free(res_diff);

	return 0;
}


// разность двух чисел
char *diff_number(int count_digits, char *buf1, char *buf2) {
	char *res = malloc(sizeof(char) * count_digits);

	for (int i = 0; i < count_digits; i++) {
		// если условие выполняется, то мы занимаем из старшего разряда
		if (buf1[i] - buf2[i] < 0) {
			buf1[i + 1] -= 1;
			res[i] = (buf1[i] + 10) - buf2[i];
		}
		else
			res[i] = buf1[i] - buf2[i];
	}

	return res;
}


// Переворачиваем число, чтобы с первого разряда отнимать,
// а не с последнего
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
	scanf("%499s", buf);
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
