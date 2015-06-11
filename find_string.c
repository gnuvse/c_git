#include <stdio.h>

int find_string(char str[], char substr[]);
int str_len(char str[]);

int main() {
	char str[] = "leviathan";
	char substr[] = "ath";

	printf("%i\n", find_string(str, substr));

	return 0;
}

int str_len(char str[]) {
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return i;
}

int find_string(char str[], char substr[]) {
	int count = 0;

	for (int i = 0; i < str_len(str); i++) {
		for (int j = 0; j < str_len(substr); j++) {
			if (count == str_len(substr))
				break;

			if(str[i] == substr[j])
				count++;
		}
	}

	return count + str_len(substr) - 1;
}

