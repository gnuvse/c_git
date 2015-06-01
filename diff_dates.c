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
int abs_val(int x);



int main() {
	struct date d1;
	struct date d2;

	int date1, date2, date_res;

	printf("Enter date1(dd mm yyyy): ");
	scanf("%i%i%i", &d1.day, &d1.month, &d1.year);

	printf("Enter date2(dd mm yyyy): ");
	scanf("%i%i%i", &d2.day, &d2.month, &d2.year);


	date1 = diff_date(d1);
	date2 = diff_date(d2);


	date_res = abs_val(date1 - date2);


	printf("%i/%i/%i - %i/%i/%i = %i days\n",
			d1.day, d1.month, d1.year,
			d2.day, d2.month, d2.year,
			date_res);

	return 0;
}


int abs_val(int x) {
	if (x < 0)
		x = -x;

	return x;
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
	bool older_than_1800 = 0;

	if (d.year >= 1800 && d.year <= 1900)
		older_than_1800 = 2;
	if (d.year >= 1700 && d.year < 1800)
		older_than_1800 = 1;

	return older_than_1800;
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

	if (older_than_1800 == 2)
		n += 1;


	return n;
}
