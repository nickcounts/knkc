// Print a table of compound interest

#include <stdio.h>
#include <stdlib.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(int argc, char *argv[]) {
  int i, low_rate, num_years, year;
  double value[5];

  printf("Enter interest rate: ");
  scanf("%d", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);

  printf("\nYears");
  for (i = 0; i < NUM_RATES; i++) {
    printf("%7d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }

  printf("\n");

  for (year = 1; year <= num_years; year++) {
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++) {
      value[i] += (low_rate + i) / 100.00 * value[i];
      printf("%8.2f", value[i]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
