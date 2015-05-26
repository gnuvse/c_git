// Метод Ньютона-Рафсона для вычесления квадратного корня числа x

#include <stdio.h>

float abs_val(float x);
float square_root(float x);


int main() {
	float x;

	printf("Please enter number: \n");
	scanf("%f", &x);


	printf("square root = %f\n", square_root(x));

	return 0;
}

float square_root(float x) {
	const float epsilon = 0.00001;
	float guess = 1.0;

	while(abs_val(guess * guess - x) >= epsilon)
		guess = (x / guess + guess) / 2.0;

	return guess;
}


float abs_val(float x) {
	if (x < 0)
		x = -x;

	return (float)x;
}
