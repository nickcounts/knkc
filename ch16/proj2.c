// Sorts an array of integers using Quicksort algorithm

#include "proj2.h"
#include <stdio.h>



void swap(struct part a[], int ind1, int ind2){
  struct part temp = a[ind1];
  a[ind1] = a[ind2];
  a[ind2] = temp;
}



// `low_ind` and `high_ind` define the slice of the `a[]` array that
// gets sorted. To begin the call, you can use `0` and `array_len-1` to 
// sort the entire array
void quicksort_inventory(struct part a[], int low_ind, int high_ind) {

  // If single element, nothing to do
  if (low_ind >= high_ind)
    return;

  int pivot_ind = high_ind;
  int pivot_value = a[pivot_ind].number;

  int leftPtr = low_ind;
  int rightPtr = high_ind;
  
  while (leftPtr < rightPtr){
    // Find next element greater than pivot value (from left)
    while (a[leftPtr].number <= pivot_value && leftPtr < rightPtr)
      leftPtr++;

    // Find next element smaller than pivot value (from right)
    while(a[rightPtr].number >= pivot_value && leftPtr < rightPtr)
      rightPtr--;

    swap(a, leftPtr, rightPtr);

  }

  swap(a, leftPtr, pivot_ind);

  // Recurse on each side of the pivot
  quicksort_inventory(a, low_ind, leftPtr-1);
  quicksort_inventory(a, leftPtr+1, high_ind);
}

