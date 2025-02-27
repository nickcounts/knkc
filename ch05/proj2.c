#include <stdio.h>

int main(void) {
  int hours, minutes;
  char *suffix = "AM";

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  if (hours > 12) {
    hours -= 12;
    suffix = "PM";
  }

  printf("Equivalent 12-hour time: %d:%d %s\n", hours, minutes, suffix);

  return 0;
}
