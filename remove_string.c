#include <stdio.h>
#define SIZE 15

void remove_string(char source[], int start, int count_remove, char res_str[]);
int str_len(char str[]);

int main() {
	char str[SIZE] = "leviathan";
	char new_str[SIZE];

	remove_string(str, 4, 3, new_str);
	return 0;
}

int str_len(char str[]) {
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return i;
}

void remove_string(char source[], int start, int count_remove, char res_str[]) {
	for (int i = 0; i < start; i++)
		res_str[i] = source[i];

	for (int i = count_remove + start, j = start; i < str_len(source); i++, j++)
		res_str[j] = source[i];

	printf("%s\n", res_str);
}


