// Метод Ньютона-Рафсона для вычесления квадратного корня числа x

#include <stdio.h>

double abs_val(double x);
double square_root(double x, double epsilon);


int main() {
	double x, epsilon = 0.00001;

	printf("Please enter number: \n");
	scanf("%lf", &x);

	if (x < 0) {
		printf("Negative argument to square_root.\n");
		return -1;
	}


	printf("square root = %f\n", square_root(x, epsilon));

	return 0;
}

double square_root(double x, double epsilon) {
	double guess = 1.0;

	while(abs_val(guess * guess - x) >= epsilon) {
		guess = (x / guess + guess) / 2.0;
		printf("guess = %elf\n", guess);
	}

	return guess;
}


double abs_val(double x) {
	if (x < 0)
		x = -x;

	return x;
}
