#include <stdio.h>
#include <stdlib.h>
#include "big_num.h"

#define SIZE 500


int main() {
	char *buf1 = malloc(sizeof(char) * SIZE);
	char *buf2 = malloc(sizeof(char) * SIZE);

	int count1;
	int count2;


	count1 = input_number(SIZE, buf1);
	printf("count = %i\n", count1);
	count2 = input_number(SIZE, buf2);
	printf("count = %i\n", count2);

	int position = 0;
	output_number(count1, buf1, position);
	output_number(count2, buf2, position);

	char *buf1_reversed = reverse_number(count1, buf1);
	char *buf2_reversed = reverse_number(count2, buf2);
	char *res_diff = diff_number(count1, buf1_reversed, count2, buf2_reversed);
	char *res = reverse_number(count1, res_diff);


	position = normalize_number(res);

	output_number(count1, res, position);


	free(buf1);
	free(buf2);
	free(buf1_reversed);
	free(buf2_reversed);
	free(res);
	free(res_diff);


	return 0;
}
