#include <stdio.h>
#include <stdbool.h>

void sort(int arr[], int n, bool arg_sort);

void print_arr(int arr[], int n);

int main() {
	int n;
	int bool_reverse_sort = 0;

	printf("Please, enter number of elements in the array: ");
	scanf("%i", &n);

	printf("Please, enter type sort(1 - revers, 0 - linear: ");
	scanf("%i", &bool_reverse_sort);

	if (n < 0)
		return -1;


	int arr[n];
	for (int i = 0; i < n; i++) {
		printf("#%i = ", i);
		scanf("%i", &arr[i]);
	}

	printf("Not sort:\n");
	print_arr(arr, n);

	sort(arr, n, (bool)bool_reverse_sort);

	printf("\n\nAfter sort:\n");
	print_arr(arr, n);

	printf("\n");

	return 0;
}


void sort(int arr[], int n, bool arg_sort) {
	int tmp;

	if(arg_sort) {
		for(int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] < arr[j]) {
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	else {
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
}

void print_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", arr[i]);
	}
}
