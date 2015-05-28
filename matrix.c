#include <stdio.h>

void scalar_multiply(int n_row, int n_column,
		int matrix[n_row][n_column], int scalar);

void display_matrix(int n_row, int n_column, int matrix[n_row][n_column]);

void arr_init(int n_row, int n_column, int matrix[n_row][n_column]);

int main() {
	int n_row = 3, n_column = 5;
    int matrix[n_row][n_column];

	printf("Please enter the value of element.\n");
	arr_init(n_row, n_column, matrix);

	display_matrix(n_row, n_column, matrix);
	printf("\n");
	scalar_multiply(n_row, n_column, matrix, 2);
	printf("\n");
	display_matrix(n_row, n_column, matrix);

	return 0;
}


void scalar_multiply(int n_row, int n_column,
		int matrix[n_row][n_column], int scalar) {

	for (int row = 0; row < n_row; row++) {
		for (int column = 0; column < n_column; ++column)
			matrix[row][column] *= scalar;
	}
}


void display_matrix(int n_row, int n_column, int matrix[n_row][n_column]) {
	for (int row = 0; row < n_row; row++) {
		for (int column = 0; column < n_column; ++column)
			printf("%5i", matrix[row][column]);
		printf("\n");
	}
}


void arr_init(int n_row, int n_column, int matrix[n_row][n_column]) {
	for (int row = 0; row < n_row; row++) {
		for (int column = 0; column < n_column; ++column) {
			printf("row#%i, column#%i == ", row, column);
			scanf("%i", &matrix[row][column]);
		}
		printf("\n");
	}
}
