/* Chapter 16, Project 5
 *
 * Modify Project 8 from Chapter 5 so that the times are stored in a single
 * array. The elements of the array will be structures, each containing a 
 * departure time and a corresponding arrival time. 
 *
 * Each time will be an integer, representing the number of minutes since 
 * midnight 
 *
 * The program will use a loop to search the array for the departure time 
 * closest to the time entered by the user
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TRAINS 8

char dept_strs[][NUM_TRAINS] = {"08:00", "09:43", "11:19", "12:47",
                                "14:00", "15:45", "19:00", "21:45"};
char arvl_strs[][NUM_TRAINS] = {"10:16", "11:52", "13:31", "15:00",
                                "16:08", "17:55", "21:20", "23:58"};
int dept_ints[sizeof(dept_strs) / (sizeof(char) * NUM_TRAINS)];

struct trains {
  int depart;
  int arrive;
  char arrive_str[6];
  char depart_str[6];
};

int time_to_minutes_from_midnight(int hours, int minutes) {
  return (hours * 60) + minutes;
}

void make_trains_array(struct trains trains[]) {
  int hr, min;
  int array_len = sizeof(dept_ints) / sizeof(int);
  for (int i = 0; i < array_len; i++) {
    sscanf(dept_strs[i], "%d:%d", &hr, &min);
    trains[i].depart = time_to_minutes_from_midnight(hr, min);

    sscanf(arvl_strs[i], "%d:%d", &hr, &min);
    trains[i].arrive = time_to_minutes_from_midnight(hr, min);

    strcpy(trains[i].arrive_str, arvl_strs[i]);
    strcpy(trains[i].depart_str, dept_strs[i]);
  }
}


int get_closest_departure_index(int my_time_minutes, struct trains trains[]) {
  int this_delta, index, this_index = 0;
  int delta = 60 * 60 * 24;
  int array_len = sizeof(dept_ints) / sizeof(int);
  for (this_index = 0; this_index < array_len; this_index++) {
    this_delta = abs(my_time_minutes - trains[this_index].depart);
    if (this_delta < delta) {
      index = this_index;
      delta = this_delta;
    }
  }
  return index;
}

int main(void) {
  struct trains trains[NUM_TRAINS];
  make_trains_array(trains);

  int input_hr, input_min;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hr, &input_min);

  int closest = get_closest_departure_index(
      time_to_minutes_from_midnight(input_hr, input_min), trains);

  printf("Closest departure time is %s, arriving at %s\n", trains[closest].depart_str,
         trains[closest].arrive_str);

  return 0;
}
