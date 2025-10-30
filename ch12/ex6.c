#include <stdio.h>
#include <stdlib.h>

// Rewrite the following function to use pointer arithmetic instead of
// array subscripting (In other words, eliminate the variable i and all
// uses of the [] operator)
//
// Make as few changes as possible

int sum_array(const int a[], int n) {
  int i, sum;
  sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}

int sum_array_ptr(const int a[], int n) {
  int sum = 0;
  const int *ptr = a;
  while (ptr < a+n) {
    sum += *ptr++;
  }
  return sum;
}


int main() {
  int array[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("sum_array_    = %d\n", sum_array(array, 10));
  printf("sum_array_ptr = %d\n", sum_array_ptr(array, 10));

}
