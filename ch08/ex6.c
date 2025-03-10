#include <stdio.h>

// Exercise 6
// Build a 2-D array to drive a seven-segment LED display:
// segments[digit][segment]

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

// Exercise 7
// I am skipping this. I believe I already did the most readable and
// compact initialization of this array. I would not use the indexed
// assignment style, it is far too hard to read in this case.
// Also, it wouldn't be smaller at all. WAY more characters, even
// though there would be fewer numbers explicitly defined:w

#define LENGTH(a) ((int)(sizeof(a) / sizeof(a[0])))
int main(int argc, char *argv[]) {

  // Exercise 8
  //
  // Declare array for a month of hourly average temperatures
  // Rows = days
  // Cols = hours
  int avg_temps[31][24] = {0};

  printf("Number of elements in avg_temps[][]: %d\n", LENGTH(avg_temps));

  int monthly_average, sum;
  sum = 0;
  for (int i = 0; i < LENGTH(avg_temps); i++) {
    // NOTE: I am skipping ahead a bit - I know the 2-d array is stored as a
    // 1-d array in row-major order. So for an average, i can simply add all
    // the elements and divide by the number of elements. No need to nest
    // a loop on row/col
    sum += *avg_temps[i];
    printf("%d", *avg_temps[i]);
  }
  printf("\n");

  // I would actually use floats or something. Integer math for simplicity
  monthly_average = sum / LENGTH(avg_temps);

  printf("Monthly average temp: %d\n", monthly_average);

  return 0;
}
