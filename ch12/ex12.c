// Write the following function:

// Returns pointers to the two largest elements in array a.
void find_two_largest(const int *a, int n, int *largest, int *second_largest);

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
  int array1[N] = {19, 2, 3, 41, 5, 6, 7, 8, 9, 10};

  int largest, second_largest = 0;

  find_two_largest(array1, N, &largest, &second_largest);

  printf("The largest element is %d and the next biggest is %d\n", largest, second_largest);

  return EXIT_SUCCESS;
}


void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
  const int *this_elem = a;

  *largest = 0;
  *second_largest = 0;

  while (this_elem - a < n) {
    // printf("this_elem - a = %ld\n", this_elem - a);
    if (*this_elem > *largest) {
      // puts("This element is bigger than largest");
      *second_largest = *largest;
      *largest = *this_elem;
      this_elem++;
      continue;
    }

    if (*this_elem > *second_largest) {
      *second_largest = *this_elem;
      this_elem++;
      continue;
    }
    this_elem++;
  }
  

}

