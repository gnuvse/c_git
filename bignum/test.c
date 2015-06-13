#include "micro_unit.h"
#include "big_num.h"
#include <stdlib.h>

int test_diff_number__equal_length(void)
{
	char a[] = {7, 5, 4};
	int n = 3;


	char b[] = {2, 9, 1};
	int m = 3;

	char *res = diff_number(n, a, m, b);

	const char check[] = {5, 6, 2};

	int ok = eq_number(n, res, m, check);

	free(res);

	return MUST_BE_TRUE(ok);
}

int test_diff_number__const_arg1(void)
{
	char a[] = {7, 5, 4};
	int n = 3;

	char b[] = {2, 9};
	int m = 2;

	char *res = diff_number(n, a, m, b);
	free(res);

	const char check[] = {7, 5, 4};

	int ok = eq_number(n, a, 3, check);

	return MUST_BE_TRUE(ok);
}

int test_diff_number__const_arg2(void)
{
	char a[] = {7, 5, 4};
	int n = 3;

	char b[] = {2, 9};
	int m = 2;

	char *res = diff_number(n, a, m, b);
	free(res);

	const char check[] = {2, 9};

	int ok = eq_number(m, b, 2, check);

	return MUST_BE_TRUE(ok);
}



int main()
{
	INIT_TEST();

	RUN_TEST(test_diff_number__equal_length);
	RUN_TEST(test_diff_number__const_arg1);
	RUN_TEST(test_diff_number__const_arg2);

	FINISH_TEST();

	return 0;
}

