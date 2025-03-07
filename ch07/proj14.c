// Write a program that calculates the average word length for a sentence

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  double x, y, xy, lasty;

  printf("Enter a positive number: ");
  scanf("%lf", &x);

  y = x / 2.0f;
  do {
    lasty = y;
    xy = x / lasty;
    y = (xy + y) / 2.0f;

    // printf("Guess is: %lf\n", y);
  } while (fabsl(lasty - y) > 0.00001f);

  printf("Square root: %lf\n", y);

  return EXIT_SUCCESS;
}
