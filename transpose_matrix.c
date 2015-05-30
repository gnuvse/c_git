#include <stdio.h>

void transpose_matrix(int row, int column,
						int m[row][column], int n[column][row]);

void arr_init(int row, int column, int m[row][column]);

void print_matrix(int row, int column, int matrix[row][column]);

int main() {
	int row, column;
	printf("Enter row and column: \n");
	scanf("%i %i", &row, &column);

	int m[row][column];
	int n[column][row];

	arr_init(row, column, m);
	print_matrix(row, column, m);
	transpose_matrix(row, column, m, n);


	return 0;
}


void print_matrix(int row, int column, int matrix[row][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%i ", matrix[i][j]);
		printf("\n");
	}
}

void arr_init(int row, int column, int m[row][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("row#%i, column#%i == ", i, j);
			scanf("%i", &m[i][j]);
		}
		printf("\n");
	}
}


void transpose_matrix(int row, int column,
					 int m[row][column], int n[column][row]) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			n[j][i] = m[i][j];
	}

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++)
			printf("%i ", n[i][j]);
		printf("\n");
	}
}
