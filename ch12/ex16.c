// Assume that the following array contains a week worth of hourly temperature
// readings:

#include <stdlib.h>
#include <stdio.h>  

const int temperatures[7][24] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// Write a loop that prints the highest temperature in the temperature array 
// (see ex14) for each day of the week. The loop body should call the 
// find_largest() function, passing it one row at a time

#include <stdbool.h>

bool search(const int a[], int n, int key) {
  const int *ptr = a;
  while (ptr - a < n) {
    if (*ptr++ == key)
      return true;
  }
  return false;
}

void print_daily_readings(const int a[], int n){
  const int *ptr = a;
  while (ptr - a < n) {
    printf("%d ", *ptr++);
  }
  puts("\n");
}

// Returns the largest value in an array of size n
int find_largest(const int a[], int n){
  const int *ptr = a;
  int largest_value = *ptr; // Set initial value to first value
  ptr++;
  while(ptr - a < n){
    if (*ptr > largest_value){
      largest_value = *ptr;
    }
    ptr++;
  }
  return largest_value;
}


int main() {
  puts("Print the largest value from each row of array:");
  for (int row = 0; row < 7; row++){
    printf("Row %d: %d\n", row, find_largest(temperatures[row], 24));
  }

  return EXIT_SUCCESS;
}
