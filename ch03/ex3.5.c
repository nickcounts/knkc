#include <stdio.h>
#include <stdlib.h>

#define ROW_STEP 1
#define COL_STEP 4
#define DIAG_FRT 5
#define DIAG_BAK 3

void print_int_vector(int v[], int max_ind) {
  for (int i = 0; i < max_ind; i++) {
    printf("%3d", v[i]);
  }
}

void print_matrix(int v[]) {
  int ind = 0;
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      printf("%3d", v[ind]);
      ind++;
    }
    printf("\n");
  }
}

int main(void) {
  int vec[16];
  for (int i = 0; i < 16; i++) {
    printf("Enter number %2d of 16: ", i + 1);
    scanf("%d", &vec[i]);
  }

  for (int i = 0; i < 16; i++) {
    printf("%d ", vec[i]);
  }
  printf("\n");

  int row_sums[4] = {vec[0] + vec[1] + vec[2] + vec[3],
                     vec[4] + vec[5] + vec[6] + vec[7],
                     vec[8] + vec[9] + vec[10] + vec[11],
                     vec[12] + vec[13] + vec[14] + vec[15]};

  int col_sums[4] = {
      vec[0] + vec[4] + vec[8] + vec[12], vec[1] + vec[5] + vec[9] + vec[13],
      vec[2] + vec[6] + vec[10] + vec[14], vec[3] + vec[7] + vec[11] + vec[15]};

  int diag_sums[2] = {vec[0] + vec[5] + vec[10] + vec[15],
                      vec[3] + vec[6] + vec[9] + vec[12]};

  printf("\n\n");
  print_matrix(vec);

  printf("\nRow Sums: ");
  print_int_vector(row_sums, 4);

  printf("\nColumn Sums: ");
  print_int_vector(col_sums, 4);

  printf("\nDiagonal Sums: ");
  print_int_vector(diag_sums, 2);

  return EXIT_SUCCESS;
}
