// Ex. 4
// Write a function `day_of_year(month, day, year)` that returns the day of
// the year as an integer between 1 and 366 specified by three arguments.

#include <stdio.h>

int day_of_year(int month, int day, int year) {
  // No error checking for valid date inputs!
  //                      J   F   M   A   M   J   J   A   S   O   N   D
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int julian = 0;
  for (int m = 1; m <= month; m++) {

    if (m == month) {
      julian += day;
      break;
    }

    // month index is 0-based, so m-1. Add entire month
    julian += days_in_month[m - 1];
  }

  if (year % 4 == 0 && month > 2) {
    // Add leap day!
    julian++;
  }
  return julian;
}

int main(int argc, char *argv[]) {
  printf("Julian day 3/29/2020: %d\n", day_of_year(3, 29, 4));
  return 0;
}
