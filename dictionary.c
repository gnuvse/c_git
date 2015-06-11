#include <stdio.h>
#include <stdbool.h>

struct entry {
	char word[15];
	char definition[50];
};


bool compare_strings(const char s1[], const char s2[]);
int lookup(const struct entry dictionary[], const char search[],
		const int num_of_words);


int main() {
	const struct entry dictionary[100] = {
		{"aardvark", "a burrowing African mammal"},
		{"abyss", "a bottomless pit"},
		{"acumen", "mentally sharp; keen"},
		{"addle", "to become confused"},
		{"aerie", "a high nest"},
		{"affix", "to append; attach"},
		{"agar", "a jelly made from seaweed"},
		{"ahoy", "a nautical call of greeting"},
		{"aigrette", "an ornamental cluster of feathers"},
		{"ajar", "partially opened"},
	};
	char word[15];
	int num_of_words = 10;
	int entry;

	printf("Enter word: ");
	scanf("%14s", word);

	entry = lookup(dictionary, word, num_of_words);

	if (entry)
		printf("%s\n", dictionary[entry].definition);
	else
		printf("Sorry, the word %s is not in my dictionary.\n", word);


	return 0;
}

int lookup(const struct entry dictionary[], const char search[],
		const int num_of_words) {

	int low = 0;
	int high = num_of_words - 1;
	int mid, res;

	while(low <= high) {
		mid = (low + high) / 2;
		res = compare_strings(dictionary[mid].word, search);
		if (res == -1)
			low = mid + 1;
		else if (res == 1)
			high = mid - 1;
		else
			return mid;
	}

	return -1; // не найден
}


bool compare_strings(const char s1[], const char s2[]) {
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;

	if (s1[i] < s2[i])
		return -1;
	else if (s1[i] == s2[i])
		return 0;
	else
		return 1;
}

