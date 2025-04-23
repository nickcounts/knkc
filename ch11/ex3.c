// The function should compute the sum and average of the numbers
// in the array a[], which has length n.
// There are errors to be corrected:

#include <stdio.h>
#include <stdlib.h>

void avg_sum(double a[], int n, double *avg, double *sum) {
  // This function was missing all the dereferences for
  // sum and avg in the code below:

  int i;

  *sum = 0.0;
  for (i = 0; i < n; i++)
    *sum += a[i];
  *avg = *sum / n;
}

int main(int argc, char *argv[]) {
  double a[3] = {5, 10, 15};
  double avg, sum;
  avg_sum(a, 3, &avg, &sum);

  printf("The sum is: %4.1f\n", sum);
  printf("The avg is: %4.1f\n", avg);

  return EXIT_SUCCESS;
}
