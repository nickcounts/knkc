#include <stdio.h>

// Return the Beaufort Scale description for a given wind speed

int main(void) {
  int windspeed;
  printf("Enter the wind speed in knots: ");
  scanf("%d", &windspeed);

  printf("%d kts is ", windspeed);

  if (windspeed <= 1)
    printf("Calm");
  else if (windspeed <= 3)
    printf("Light air");
  else if (windspeed <= 27)
    printf("Breeze");
  else if (windspeed <= 47)
    printf("Gale");
  else if (windspeed <= 63)
    printf("Storm");
  else
    printf("Hurricane");

  printf("\n");

  return 0;
}
