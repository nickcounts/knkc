// Proj 5
// Modify ch8 proj17 so it includes the following functions:
//    void create_magic_square(int n, char magic_square[n][n])
//    void print_magic_square(int n, char magic_square[n][n])
//
// // Magic Square:
// Let user select dimension of matrix.
// Fill it out as a magic square, then display.

#include <stdio.h>
#include <stdlib.h>

void print_magic_square(int n, int magic_square[99][99]) {
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      printf("%5d", magic_square[r][c]);
    }
    printf("\n");
  }
}

void create_magic_square(int N, int magic_square[99][99]) {

  int r, c, n;

  // Starting spot
  r = 0;
  c = N / 2;

  // small counter - for offsetting diagonals every N elements
  n = 0;

  for (int i = 1; i <= N * N; i++) {
    magic_square[r][c] = i;
    // move up 1, right 1 - wrap as needed
    r--;
    c++;
    n++;

    if (n == N) {
      // need to bump down a row!
      r += 2; // need 2: 1 to undo normal move, one to bump down
      c--;    // need to undo normal move (keep old column)
      n = 0;
      // printf("Bumping: r=%d\tc=%d\n", r, c);
    }

    // Wrap around
    if (r < 0)
      r = N - 1;

    if (c >= N)
      c = 0;
  }
}

int main(int argc, char *argv[]) {
  int N;
  printf("This program prints an NxN magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  scanf("%d", &N);

  if (N < 1 || N > 99 || N % 2 == 0) {
    printf("Please enter an odd number between 1 and 99.\n");
    return EXIT_FAILURE;
  }

  int m[99][99] = {0};

  create_magic_square(N, m);
  print_magic_square(N, m);

  return EXIT_SUCCESS;
}
