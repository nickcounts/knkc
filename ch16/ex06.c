/* Chapter 16, Exercise 6
 *
 * Write the following functions, assuming that the `time` structure 
 * contains three members: `hours`, `minutes`, and `seconds` (all type `int`)
 *
 * a) struct time split_time(long total_seconds);
 *    Returns a structure containing the time in hours, minutes, and seconds
 *    `total_seconds` is the number of seconds since midnight
 */

#include <stdio.h>

struct time {
  int hours;
  int minutes;
  int seconds;
};

// ---------------------------------------------------------------------
//                     Part A) Function Definition
// ---------------------------------------------------------------------

// Returns a structure containing the time in hours, minutes, and seconds
// `total_seconds` is the number of seconds since midnight
 struct time split_time(long total_seconds){
   int hours, minutes, seconds = 0;

   hours   = total_seconds / (60*60);
   minutes = (total_seconds - hours*60*60) / 60;
   seconds = total_seconds % 60;

   struct time time = {
     .hours = hours,
     .minutes = minutes,
     .seconds = seconds,
   };

   return time;
 }


void print_split_time(struct time t){
  printf("%02d:", t.hours);
  printf("%02d:", t.minutes);
  printf("%02d",  t.seconds);
}




int main(void) {

  int sec = 0;
  struct time time = split_time(sec);

  printf("Testing seconds = 0 (midnight): ");
  print_split_time(time); printf("\n");

  sec = 61;
  time = split_time(sec);
  printf("Testing seconds = 61 (1 min, 1 sec): ");
  print_split_time(time); printf("\n");

  sec = 3*60*60 + 4*60 + 5;
  time = split_time(sec);
  printf("Testing seconds = 11045 (3 hr, 4 min, 5 sec): ");
  print_split_time(time); printf("\n");

  sec = 24*60*60;
  time = split_time(sec);
  printf("Testing seconds = 86400 (24 hr, 0 min, 0 sec): ");
  print_split_time(time); printf("\n");

  sec = 24*60*60 - 1;
  // printf("Sec: %d\n", sec);
  time = split_time(sec);
  printf("Testing seconds = 86399 (23 hr, 59 min, 59 sec): ");
  print_split_time(time); printf("\n");


  return 0;
}




