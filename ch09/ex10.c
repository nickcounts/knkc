// Ex 10
// Write functions that return the following values for a and n, where a is
// an array of integers and n is the length of the array:
//
// a) the largest element of a
// b) the average of all elements in a;
// c) the number of positive elements in a;

#include <stdio.h>
#include <stdlib.h>

int largest(int a[], int n) {
  int largest = a[0];
  int i = 0;
  while (i < n) {
    if (a[i] > largest)
      largest = a[i];
    i++;
  }
  return largest;
}

int count_positive(int a[], int n) {
  int i, pos_count;
  pos_count = 0;
  for (i = 0; i < n; i++) {
    if (a[i] >= 0)
      pos_count++;
  }
  return pos_count;
}

float average(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return (float)sum / n;
}

int main(int argc, char *argv[]) {
  int ar[] = {1, 2, 3, 4, -10, 3};
  printf("The largest element in ar[] is %d\n", largest(ar, 6));
  printf("The number of positive elements in ar[] is: %d\n",
         count_positive(ar, 6));
  printf("The average of the elements in ar[] is: %f\n", average(ar, 6));
  return EXIT_SUCCESS;
}
