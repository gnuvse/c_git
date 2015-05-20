/*
 * gdc.c Нахождение наибольшего общего делителя
 * 
 */

#include <stdio.h>

void check(int u, int v, int tmp) {
	printf("u = %i, v = %i, tmp = %i\n", u, v, tmp);
}


int main() {
	int u, v, tmp;
	
	printf("Please enter nonnegative integers.\n");
	scanf("%i%i", &u, &v);
	
	while (v != 0) {
		tmp = u % v;
		u = v;
		v = tmp;
		check(u, v, tmp);
	}
	
	printf("Their greatest common divisot is %i\n", u);
		
	return 0;
}
