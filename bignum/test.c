#include "micro_unit.h"
#include "big_num.h"
#include <stdlib.h>

int test_diff_number__equal_length(void)
{
	char a[] = {7, 5, 4};
	int n = 3;


	char b[] = {2, 9, 1};
	int m = 3;

	char *res = diff_number(n, m, a, b);

	const char check[] = {5, 6, 2};

	int ok = eq_number(n, res, 3, check);

	free(res);

	return MUST_BE_TRUE(ok);
}



int main()
{
	INIT_TEST();

	RUN_TEST(test_diff_number__equal_length);

	FINISH_TEST();

	return 0;
}

