// Section 8.2 had a program fragment in which two nested `for` loops
// initialized the array `ident` for use as an identity matrix.
//
// Rewrite the code, using a single pointer to step throught hte array one
// element at a time. Hint: Since we won't be usint row and col index variables,
// it won't be easy to tell where to store 1.
//
// Instead, we can use the fact that the first element of the array should be
// 1, the next N elements should be 0, the next element should be 1 and
// so forth.
//
// Use a variable to keep track of how many consecutive 0 have been stored;
// When the count reaches N, it's time to store 1.

#include <stdlib.h>
#include <stdio.h>
#define N 10

double ident[N][N];

// void make_ident_old(double *new_ident, int n)
// {
//   int row, col;
//   for (row = 0; row < n; row++) {
//     for (col = 0; col < n; col++) {
//       if (row == col) {
//         new_ident[row][col] = 1.0;
//       } else {
//         new_ident[row][col] = 0.0;
//       }
//     }
//   }
// }

// Quick and dirty text output from earlier exercize
void print_square_matrix(double *v, int dim) {
  int ind = 0;
  for (int row = 0; row < dim; row++) {
    for (int col = 0; col < dim; col++) {
      printf("%1.0f ", v[ind]);
      ind++;
    }
    printf("\n");
  }
}

void make_ident(double *new_array, int n) {
  double *this_elem = new_array;

  int counter = n;

  while (this_elem - new_array < n*n) {
    if (counter == n) {
      *this_elem = 1.0;
      counter = 0;
      this_elem++;
      continue;
    }

    *this_elem++ = 0.0;
    counter++;

  }
}


int main() {
  // How TF are we really supposed to handle multi-dim arrays?
  double *I = malloc((N * N) * sizeof(*I));

  make_ident(I, N);
  print_square_matrix(I, N);

  return EXIT_SUCCESS;
  
}


