// Modify project 8 from chapter 5 so the user enters time using 12-hour
// clock with A, P, AM, or PM (either upper or lowercase)

#include <ctype.h>
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
  char meridian[4];

  printf("Enter a desired departure time (hh:mm a/p): ");
  scanf("%d:%d %s", &input_hr, &input_min, meridian);

  switch (toupper(meridian[0])) {
    // 12:00 AM = 00:00
    // 01:00 AM = 01:00
    // 12:00 PM = 12:00
  case 'A':
    if (input_hr == 12) {
      input_hr = 0;
    }
    break;
  case 'P':
    if (input_hr != 12) {
      input_hr += 12;
    }
    break;
  default:
    printf("Unknown AM/PM identifier: %s\n", meridian);
    exit(EXIT_FAILURE);
  }

  int closest = get_closest_departure_index(
      time_to_minutes_from_midnight(input_hr, input_min));

  printf("Closest departure time is %s, arriving at %s\n", dept_strs[closest],
         arvl_strs[closest]);

  return 0;
}
