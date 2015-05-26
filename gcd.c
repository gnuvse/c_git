/*
 * gdc.c Нахождение наибольшего общего делителя
 *
 */

#include <stdio.h>

int gdc(int u, int v);

int main() {
	int u, v;

	printf("Please enter nonnegative integers.\n");
	scanf("%i %i", &u, &v);

	printf("Their greatest common divisot is %i\n", gdc(u, v));

	return 0;
}


int gdc(int u, int v) {
	int tmp;

	while (v != 0) {
		tmp = u % v;
		u = v;
		v = tmp;
	}

	return u;
}
