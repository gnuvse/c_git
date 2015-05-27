#include <stdio.h>

void sort(int arr[], int n);
void print_arr(int arr[], int n);

int main() {
	int n;

	printf("Please, enter number of elements in the array: ");
	scanf("%i", &n);

	if (n < 0)
		return -1;


	int arr[n];
	for (int i = 0; i < n; i++) {
		printf("#%i = ", i);
		scanf("%i", &arr[i]);
	}

	printf("\n");

	printf("Not sort:\n");
	print_arr(arr, n);

	sort(arr, n);

	printf("\n\nAfter sort:\n");
	print_arr(arr, n);

	return 0;
}


void sort(int arr[], int n) {
	int tmp;

	for(int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", arr[i]);
	}
}
