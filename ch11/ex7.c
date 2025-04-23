// Write the following function:
void split_date(int day_of_year, int year, int *month, int *day);

// day_of_year is an integer between 1 and 366. Specifying a particular day
// within the year designated by year, month, and day point to variables in
// which the function will store the equivalent month (1-12) and day
// within that month (1-31)

#include <stdio.h>
#include <stdlib.h>

void split_date(int day_of_year, int year, int *month, int *day) {
  // Solve for month/day including leap years
  int is_leap_year = (year % 4 == 0) ? 1 : 0;

  int dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  dim[1] += is_leap_year;

  for (int m = 0; m < 12; m++) {
    if (day_of_year <= dim[m]) {
      *month = m + 1;
      break;
    } else {
      day_of_year -= dim[m];
    }
  }
  *day = day_of_year;
}

int main(int argc, char *argv[]) {
  int julian, year, month, day;

  printf("Enter the year: ");
  scanf("%d", &year);
  printf("Enter the day of the year: ");
  scanf("%d", &julian);

  split_date(julian, year, &month, &day);

  printf("The date is: %02d/%02d/%d\n", month, day, year);

  return EXIT_SUCCESS;
}
