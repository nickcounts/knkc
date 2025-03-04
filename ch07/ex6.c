#include <stdio.h>

// Specify which type is smallest guaranteed to hold the value;
// char, short, int, long

char days_in_a_month = 31;
short days_in_a_year = 366;
int minutes_in_a_day = 1440;
long seconds_in_a_day = 86400;

int main(void) {
  printf("31 fits in char   : %d\n", days_in_a_month);
  printf("366 fits in short : %d\n", days_in_a_year);
  printf("1440 fits in int  : %d\n", minutes_in_a_day);
  printf("86400 fits in char: %ld\n", seconds_in_a_day);

  return 0;
}
