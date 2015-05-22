#include <stdio.h>

void reverse_int(int n);

int main() {
	int n;
	
	printf("Please, enter number: \n");
	scanf("%i", &n);
	
	reverse(n);
	
	return 0;
}

int reverse_nonnegative(int n) {
	// Сделай так, чтобы функция возвращала результат, а не выводила его на экран
	int right_digit;
	do {
		right_digit = n % 10;
		printf("%i", right_digit);
		n /= 10;
	} while (n != 0);
	printf("\n");
}

int reverse_int(int n) {
	// TODO
	// Не знаю, чего там хочет автор, но по хорошему, делать надо через модуль числа:
	// У тебя уже есть функция reverse_nonegative, и чтобы не дублировать код проще
	// воспользоваться ей.
	// Типа, если n<0, то reverse_nonnegative(-n)
	
	// Если хочешь поизвращаться, сделай функцию reverse_negative отдельно.
	// Но это не очень хорошая идея, т.к. в С % и / от отрицательного числа,
	// если я не путаю, могут иметь разное действие, в зависимости от платформы.
}
