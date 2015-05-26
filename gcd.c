/*
 * gdc.c Нахождение наибольшего общего делителя
 *
 */

#include <stdio.h>

void gdc(int u, int v);

int main() {
	int u, v;

	printf("Please enter nonnegative integers.\n");
	scanf("%i %i", &u, &v);

	gdc(u, v);

	return 0;
}


void gdc(int u, int v) {
	int tmp;
	while (v != 0) {
		tmp = u % v;
		u = v;
		v = tmp;
	}
	printf("Their greatest common divisot is %i\n", u);
}
