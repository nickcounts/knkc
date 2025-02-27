#include <stdio.h>

int main(void) {
  int integers[4];

  printf("Enter four (4) integers: ");
  scanf("%d %d %d %d", &integers[0], &integers[1], &integers[2], &integers[3]);

  int max_int = integers[0];
  int min_int = integers[0];

  for (int i = 0; i < 4; i++) {
    if (integers[i] > max_int)
      max_int = integers[i];
    if (integers[i] < min_int)
      min_int = integers[i];
  }

  printf("Largest: %d\nSmallest: %d\n", max_int, min_int);

  return 0;
}
