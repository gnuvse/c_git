#include <stdio.h>

void transpose_matrix(int m[4][5], int n[5][4]);

int main() {
	int m[4][5] = {
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5}
	};

	int n[5][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	transpose_matrix(m, n);

	return 0;
}

void transpose_matrix(int m[4][5], int n[5][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++)
			n[j][i] = m[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			printf("%i ", n[i][j]);
		printf("\n");
	}
}
