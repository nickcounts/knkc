#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int month, date, year;

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &date, &year);

  printf("You entered the date %04d%02d%02d\n", year, month, date);

  return EXIT_SUCCESS;
}
