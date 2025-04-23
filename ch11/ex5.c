// Write the following function:
void split_time(long total_sec, int *hr, int *min, int *sec);
// total_sec is a time represented as the number of seconds since midnight.
// hr, min, sec are pointers to variables in which the function will store
// the equivalent time in hours (0-23), minutes (0-59), and seconds (0-59)

#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *hr, int *min, int *sec) {
  *hr = (int)total_sec / (60 * 60);
  *min = (int)(total_sec - *hr) / 60;
  *sec = (int)total_sec % 60;
}

int main(int argc, char *argv[]) {
  int hr, min, sec;
  split_time(4000, &hr, &min, &sec);
  printf("4000 seconds after midnight is %02d:%02d:%02d\n", hr, min, sec);
  return EXIT_SUCCESS;
}
