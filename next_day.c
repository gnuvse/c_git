#include <stdio.h>
#include <stdbool.h>

struct date {
	int day;
	int month;
	int year;
};


int num_of_days(struct date d);
bool is_leap_year(struct date d);
struct date date_update (struct date today);


int main() {


	struct date today, tomorrow;


	printf("Enter todays date(dd mm yyyy): ");
	scanf("%i%i%i", &today.day, &today.month, &today.year);

	tomorrow = date_update(today);

	printf("\n");
	printf("Tomorrow's date(%i/%i/%i): ",
			tomorrow.day, tomorrow.month, tomorrow.year);


	return 0;
}

struct date date_update (struct date today) {
	struct date tomorrow;

	if (today.day != num_of_days(today)) {
		tomorrow = (struct date) {today.day + 1, today.month, today.year};
	}
	else if (today.month == 12) { // Конец года
		tomorrow = (struct date) {1, 1, today.year + 1};
	}
	else { // Конец месяца
		tomorrow = (struct date) {1, today.month + 1, today.year};
	}

	return tomorrow;
}

bool is_leap_year(struct date d) {
	bool leap_year;
	if ( (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leap_year = 1;
	else
		leap_year = 0;

	return leap_year;
}

int num_of_days(struct date d) {
	int days;

	const int days_per_month[12] = { 31, 28, 31, 30, 31, 30,
									 31, 31, 30, 31, 30, 31 };

	if (is_leap_year(d) && d.month == 2)
		days = 29;
	else
		days = days_per_month[d.month - 1];

	return days;
}
