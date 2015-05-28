// Метод Ньютона-Рафсона для вычесления квадратного корня числа x

#include <stdio.h>

float abs_val(float x);
float square_root(float x, float epsilon);


int main() {
	float x, epsilon = 0.00001;

	printf("Please enter number: \n");
	scanf("%f", &x);

	if (x < 0) {
		printf("Negative argument to square_root.\n");
		return -1;
	}


	printf("square root = %f\n", square_root(x, epsilon));

	return 0;
}

float square_root(float x, float epsilon) {
	float guess = 1.0;

	while(abs_val(guess * guess - x) >= epsilon) {
		guess = (x / guess + guess) / 2.0;
	}

	return guess;
}


float abs_val(float x) {
	if (x < 0)
		x = -x;

	return x;
}
