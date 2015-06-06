#include <stdio.h>
#include <stdbool.h>

int count_words(const char string[]);
bool alphabetic(const char c);
void read_line(char buffer[]);


int main() {
	char text[81];
	int total_words  = 0;
	bool end_of_text = 0;

	printf("Type in your text.\n");
	printf("When you are done, press 'ENTER'.\n\n");

	while (!end_of_text) {
		read_line(text);
		if (text[0] == '\n')
			end_of_text = 1;
		else
			total_words += count_words(text);
	}

	printf("\nThere are %i words in the above text.\n", total_words);

	return 0;
}


bool alphabetic(const char c) {
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
		return 1;
	else
		return 0;
}


void read_line(char buffer[]) {
	char c;
	int i = 0;
	do {
		c = getchar();
		buffer[i] = c;
		i++;
	} while(c != '\n');
}


int count_words(const char string[]) {
	int word_count = 0;
	bool looking_for_word = 1;

	for (int i = 0; string[i] != '\0'; i++) {
		if (alphabetic(string[i])) {
			if (looking_for_word) {
				word_count++;
				looking_for_word = 0;
			}
		}
		else
			looking_for_word = 1;
	}

	return word_count;
}

