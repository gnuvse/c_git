#include <stdio.h>
#include <stdlib.h>
#include "big_num.h"


// разность двух чисел
char *diff_number(int count1, int count2, char *buf1, char *buf2) {
	char *res = malloc(sizeof(char) * count1);

	for (int i = 0; i < count2; i++) {
		// если условие выполняется, то мы занимаем из старшего разряда
		if (buf1[i] < buf2[i]) {
			buf1[i + 1] -= 1;
			res[i] = (buf1[i] + 10) - buf2[i];
		}
		else
			res[i] = buf1[i] - buf2[i];
	}

	for (int i = count2; i < count1; i++) {
		if (buf1[i] < 0) {
			res[i] = buf1[i] + 10;
			buf1[i + 1] -= 1;
		}
		else
			res[i] = buf1[i];
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
