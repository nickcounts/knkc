// Modify ch05 proj8 so that it includes the following function:
void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

// This function will find the flight whose departure time is closest to
// desired_time (expressed as minutes since midnight). It will store the
// departure and arrival times of this flight (also in minutes since midnight)
// in the variables pointed to by departure_time and arrical_time respectively

#include <stdio.h>
#include <stdlib.h>

char dept_strs[][6] = {"08:00", "09:43", "11:19", "12:47",
                       "14:00", "15:45", "19:00", "21:45"};
char arvl_strs[][6] = {"10:16", "11:52", "13:31", "15:00",
                       "16:08", "17:55", "21:20", "23:58"};
int dept_ints[sizeof(dept_strs) / (sizeof(char) * 6)];

int time_to_minutes_from_midnight(int hours, int minutes) {
  return (hours * 60) + minutes;
}

void make_dept_ints() {
  int hr, min;
  int array_len = sizeof(dept_ints) / sizeof(int);
  for (int i = 0; i < array_len; i++) {
    sscanf(dept_strs[i], "%d:%d", &hr, &min);
    dept_ints[i] = time_to_minutes_from_midnight(hr, min);
  }
}

int get_closest_departure_index(int my_time_minutes) {
  int this_delta, index, this_index = 0;
  int delta = 60 * 60 * 24;
  int array_len = sizeof(dept_ints) / sizeof(int);
  for (this_index = 0; this_index < array_len; this_index++) {
    this_delta = abs(my_time_minutes - dept_ints[this_index]);
    if (this_delta < delta) {
      index = this_index;
      delta = this_delta;
    }
  }
  return index;
}

int main(void) {
  make_dept_ints();

  int input_hr, input_min;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hr, &input_min);

  int cl_arrival, cl_departure;

  find_closest_flight(time_to_minutes_from_midnight(input_hr, input_min),
                      &cl_departure, &cl_arrival);

  printf("Closest departure time is %s, arriving at %s\n", dept_strs[closest],
         arvl_strs[closest]);

  return 0;
}
