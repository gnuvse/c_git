/* Программа подсчитывает кол-во определенного символа в строке*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_NUMBER_LETTERS 52

int main()
{
	const int number_letters = 26;
	int alphabet_matches[TOTAL_NUMBER_LETTERS] = {0};


	char *str = (char*) malloc (sizeof(char) * 100);

	char az_AZ_alphabet[TOTAL_NUMBER_LETTERS];

	printf("Please enter string: ");
	scanf("%99s", str);

	// Заполнения массивов маленькими и большими буквами
	for(int i = 0; i < number_letters; i++) {
		az_AZ_alphabet[i] = 'a' + i;
		az_AZ_alphabet[i + number_letters] = 'A' + i;
	}

	// Подсчет символов входящих в строку
	for (char* pch = str; *pch; pch++) {
		if ('a' <= *pch && *pch <= 'z') {
				alphabet_matches[*pch - 'a'] += 1;
		}
		else if ('A' <= *pch && *pch <= 'Z') {
				alphabet_matches[(*pch - 'A') + number_letters] += 1;
		}
		else
			printf("Error!\n");
	}

	// Вывод таблицы
	for (int i = 0; i < TOTAL_NUMBER_LETTERS; i++) {
		printf("%c - %d\n", az_AZ_alphabet[i], alphabet_matches[i]);

		//Вставляет пустую строку после строчных букв
		if (i == number_letters - 1)
			printf("\n");
	}

	free(str);

	return 0;
}
