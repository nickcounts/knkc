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

struct train {
  int depart;
  int arrive;
  char depart_str[6];
  char arrive_str[6];
};



// Return the number of minutes from midnight for a given time
int time_to_minutes_from_midnight(int hours, int minutes) {
  return (hours * 60) + minutes;
}



// StringToMinutes - parse the time string to minutes-from-midnight
int stom(const char* s){
  int hr, min;
  sscanf(s, "%d:%d", &hr, &min);
  return time_to_minutes_from_midnight(hr, min);
}



// Make a train struct from two time strings. Useful for building initial
// data from human-readable input
struct train train_entry(const char* dept, const char* arvl){
  struct train t = {
    .depart = stom(dept),
    .arrive = stom(arvl),
  };
  strcpy(t.depart_str, dept);
  strcpy(t.arrive_str, arvl);
  return t;
}



// Find the next train. Pass the trains array and the number of elements in the
// array
int get_closest_departure_index(int my_time_minutes, struct train trains[], int n) {
  int this_delta, index, this_index = 0;
  int delta = 60 * 60 * 24;

  for (this_index = 0; this_index < n; this_index++) {
    this_delta = abs(my_time_minutes - trains[this_index].depart);
    if (this_delta < delta) {
      index = this_index;
      delta = this_delta;
    }
  }
  return index;
}



int main(void) {

  struct train trains[NUM_TRAINS] = {
    train_entry("08:00","10:16"),
    train_entry("09:43","11:52"),
    train_entry("11:19","13:31"),
    train_entry("12:47","15:00"),
    train_entry("14:00","16:08"),
    train_entry("15:45","17:55"),
    train_entry("19:00","21:20"),
    train_entry("21:45","23:58"),
  };


  int input_hr, input_min;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hr, &input_min);
  if (input_hr > 23){
    printf("Please enter a valid time in the form HH:MM\n");
    return 1;
  }

  int closest = get_closest_departure_index(
      time_to_minutes_from_midnight(input_hr, input_min), trains, NUM_TRAINS);

  printf("Closest departure time is %s, arriving at %s\n", trains[closest].depart_str,
         trains[closest].arrive_str);

  return 0;
}
