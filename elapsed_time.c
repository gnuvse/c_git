#include <stdio.h>


struct time {
	int hour;
	int minutes;
	int seconds;
};

struct time elapsed_time(struct time t1, struct time t2);
struct time chechk_incoming_data(struct time t1, struct time t2);

int main() {
	struct time t1;
	struct time t2;



	printf("Enter the time1(time1 > time2)(1 .. 24, 24 = 00): ");
	scanf("%i%i%i", &t1.hour, &t1.minutes, &t1.seconds);

	printf("Enter the time2(1 .. 24, 24 = 00): ");
	scanf("%i%i%i", &t2.hour, &t2.minutes, &t2.seconds);

	if (t1.hour < t2.hour) {
		printf("Error. time2 > time1\n");
		return -1;
	}


	struct time t_res = elapsed_time(t1, t2);

	printf("t_res = %i:%i:%i\n", t_res.hour, t_res.minutes, t_res.seconds);

	return 0;
}


struct time elapsed_time(struct time t1, struct time t2) {
	struct time t_res;


	if (t1.seconds - t2.seconds < 0) {
		t1.minutes -= 1;
		t_res.seconds = (t1.seconds + 60) - t2.seconds;
	}
	else
		t_res.seconds = t1.seconds - t2.seconds;


	if (t1.minutes - t2.minutes < 0) {
		t1.hour -= 1;
		t_res.minutes = (t1.minutes + 60) - t2.minutes;
	}
	else
		t_res.minutes = t1.minutes - t2.minutes;

	if (t1.hour != 0)
		t_res.hour = t1.hour - t2.hour;

	return t_res;
}
