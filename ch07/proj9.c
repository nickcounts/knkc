// Write a program that asks the user for a 12-hour time, then displays the
// time in 24-hour form:

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int input_hr, input_min;
  char meridian[4];

  printf("Enter a 12-hour time: ");
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

  printf("Equivalent 24-hour time: %02d:%02d\n", input_hr, input_min);

  return 0;
}
