#include <stdio.h>

struct date {
	int day;
	int month;
	int year;
};

int diff_date(struct date d);


int main() {
	struct date d1 = {3, 8, 2004};
	struct date d2 = {21, 2, 2005};

	printf("n1 = %i, n2 = %i\tn2 - n1 = %i",
			diff_date(d1), diff_date(d2), diff_date(d2) - diff_date(d1));

	return 0;
}

int diff_date(struct date d) {
	int n;
	if (d.month <= 2)
		d.year -= 1;

	if (d.month <= 2)
		d.month += 13;
	else
		d.month += 1;

	n = (1461 * d.year) / 4 + (153 * d.month) / 5 + d.day;

	return n;
}
