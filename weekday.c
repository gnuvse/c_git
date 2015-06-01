#include <stdio.h>
#include <stdbool.h>


struct date {
	int day;
	int month;
	int year;
};


struct days_week {
	int num;
	char name[3];
};


int diff_date(struct date d);
struct date condition_calculate_date(struct date d);
bool conditions_older_dates(struct date d);
int weekday(int n);
void print_weekday(int weekday);


int main() {
	struct date d;
	int n;

	printf("Enter date(dd mm yyyy): ");
	scanf("%i%i%i", &d.day, &d.month, &d.year);

	n = diff_date(d);

	print_weekday(weekday(n));

	return 0;
}


void print_weekday(int weekday) {
	const struct days_week wkday[7] = {
		{0, {'S', 'U', 'N'} }, {1, {'M', 'O', 'N'} },
		{2, {'T', 'U', 'E'} }, {3, {'W', 'E', 'D'} },
		{4, {'T', 'H', 'U'} }, {5, {'F', 'R', 'I'} },
		{6, {'S', 'A', 'T'} },
	};

	printf("%c%c%c\n", wkday[weekday].name[0], wkday[weekday].name[1],
			 wkday[weekday].name[2]);
}


int weekday(int n) {
	int weekday;
	weekday = (n - 621049) % 7;
	return weekday;
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

	printf("%i\n", n);
	return n;
}
