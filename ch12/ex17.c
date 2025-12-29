// Rewrite the following function to use pointer arithmetic instead of array
// subscripting. (In other words, eliminate the variables i and j and all uses
// of the [] operator.) Use a single loop instead of nested loops

#include <stdio.h>
#define LEN 4

int sum_two_dimensional_array(const int a[][LEN], int n){
  int i, j, sum = 0;

  for (i=0; i<n; i++)
    for (j = 0; j<LEN; j++)
      sum += a[i][j];

  return sum;
}

// Return the sum of all elements of 2-d array
int sum_2d_array(const int a[][LEN], int n){
  int sum = 0;
  const int *ptr = a[0];
  const int *start = a[0];
  while (ptr - start < n*LEN) {
    sum += *ptr++;
  }

  return sum;
}

int main() {
  const int array[3][4]= {
    {1, 2, 3, 4},
    {1, 2, 3, 4},
    {1, 2, 3, 4},
  };

  printf("%d\n", sum_two_dimensional_array(array, 3));
  printf("%d\n", sum_2d_array(array, 3));

  return 0;
}
