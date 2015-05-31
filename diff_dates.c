#include <stdio.h>
#include <stdbool.h>

struct date {
	int day;
	int month;
	int year;
};

int diff_date(struct date d);
struct date condition_calculate_date(struct date d);
bool conditions_older_dates(struct date d);

int main() {
	struct date d1 = {3, 8, 2004};
	struct date d2 = {21, 2, 2005};

	int date1, date2;

	date1 = diff_date(d1);
	date2 = diff_date(d2);

	printf("n1 = %i, n2 = %i\tn2 - n1 = %i", date1, date2, date2 - date1);

	return 0;
}

struct date condition_calculate_date(struct date d) {
	if (d.month <= 2)
		d.year -= 1;

	if (d.month <= 2)
		d.month += 13;
	else
		d.month += 1;

	return d;
}


bool conditions_older_dates(struct date d) {
	bool older_than_1800;

	if (d.year >= 1800 && d.year <= 1900)
		older_than_1800 = 0;
	if (d.year >= 1700 && d.year < 1800)
		older_than_1800 = 1;

	return older_than_1800 = 1;
}


int diff_date(struct date d) {
	int n;
	struct date cond_date;
	bool older_than_1800 = conditions_older_dates(d);

	cond_date = condition_calculate_date(d);

	n = (1461 * cond_date.year) / 4
		+ (153 * cond_date.month) / 5
		+ cond_date.day;

	if (older_than_1800)
		n += 2;

	if (!older_than_1800)
		n += 1;


	return n;
}
