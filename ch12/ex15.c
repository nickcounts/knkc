// Assume that the following array contains a week worth of hourly temperature
// readings:

#include <stdlib.h>
#include <stdio.h>  

const int temperatures[7][24] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// Write a lolop that prints all temperature readings in row i of the
// temperature array. Use a pointer to visit each element

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


int main() {
  puts("Hourly readings for row 2 (third row): ");
  print_daily_readings(temperatures[2], 24);

  return EXIT_SUCCESS;
}
