#include <stdio.h>
#include <stdlib.h>
// write a program that prints out a one-month calendar.
// Ask the user for the number of days and the starting
// day of the week

void check_inputs(int days, int start) {
  int error_flag = 0;
  if (days < 1 || days > 32) {
    printf("Please enter a month length between 28 and 31.\n");
    error_flag += 1;
  }
  if (start < 1 || start > 7) {
    printf("Please enter a starting day between 1 and 7.\n");
    error_flag += 1;
  }
  if (error_flag)
    exit(1);
}

int main(void) {
  int days, start_day;
  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start_day);

  check_inputs(days, start_day);

  // Set initial offset
  for (int bd = 1; bd < start_day; bd++) {
    printf("   ");
  }

  // print all month days
  for (int md = 1; md <= days; md++) {
    printf("%3d", md);
    start_day++;
    if (start_day > 7) {
      printf("\n");
      start_day = 1;
    }
  }
  printf("\n");
  return 0;
}
