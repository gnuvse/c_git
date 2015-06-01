#include <stdio.h>

struct time {
	int hour;
	int minutes;
	int seconds;
};

struct time elapsed_time(struct time t1, struct time t2);

int main() {
	struct time t1 = {12, 10, 10};
	struct time t2 = {24, 10, 10};

	printf("Enter time1(hh mm ss): ");
	scanf("%i%i%i", &t1.hour, &t1.minutes, &t1.seconds);

	printf("Enter time2(hh mm ss): ");
	scanf("%i%i%i", &t2.hour, &t2.minutes, &t2.seconds);


	struct time t_res = elapsed_time(t1, t2);

	printf("t_res = %i/%i/%i\n", t_res.hour, t_res.minutes, t_res.seconds);

	return 0;
}


struct time elapsed_time(struct time t1, struct time t2) {
	struct time t_res;

	if (t1.hour > t2.hour)
		t_res.hour = t1.hour - t2.hour;
	else
		t_res.hour = t2.hour - t1.hour;

	if (t1.minutes > t2.minutes)
		t_res.minutes = t1.minutes - t2.minutes;
	else
		t_res.minutes = t2.minutes - t1.minutes;

	if (t1.seconds > t2.seconds)
		t_res.seconds = t1.seconds - t2.seconds;
	else
		t_res.seconds = t2.seconds - t1.seconds;

	return t_res;
}
