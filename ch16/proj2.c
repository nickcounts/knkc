// Sorts an array of integers using Quicksort algorithm

#include "proj2.h"

// `first_ind` and `last_ind` define the slice of the `a[]` array that
// gets sorted. To begin the call, you can use `0` and `array_len` to 
// sort the entire array
void quicksort_inventory(struct part a[], int first_ind, int last_ind) {
  int middle;

  if (first_ind >= last_ind)
    return;
  middle = split(a, first_ind, last_ind);
  quicksort_inventory(a, first_ind, middle - 1);
  quicksort_inventory(a, middle + 1, last_ind);
}


int split(struct part a[], int low, int high) {
  int part_element = a[low].number;
  struct part temp = a[low];

  for (;;) { // infinite loop idiom: (;;)
    // no conditional expression, defaults to false
    while (low < high && part_element <= a[high].number)
      high--;
    if (low >= high)
      break;
    a[low++] = a[high];

    while (low < high && a[low].number <= part_element)
      low++;
    if (low >= high)
      break;
    a[high--] = a[low];
  }

  a[high] = temp;
  return high;
}
