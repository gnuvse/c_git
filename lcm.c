// Нахождение общего наименьшего кратного
#include <stdio.h>

int lcm(int u, int v);
int gcd(int u, int v);

int main() {
	int u, v;

	printf("Please enter nonnegative integers.\n");
	scanf("%i %i", &u, &v);

	printf("Their least common multiple is %i\n", lcm(u, v));

	return 0;
}



int lcm(int u, int v) {
	if (v < 0)
		return -1;
	else
		return (u * v) / gcd(u, v);
}



int gcd(int u, int v) {
	int tmp;

	while (v != 0) {
		tmp = u % v;
		u = v;
		v = tmp;
	}

	return u;
}
