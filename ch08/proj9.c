// Write a program that generates a random walk across a 10x19 array
// The array will contain all '.' initially. Walk randomly from element
// to element, leaving the letters A ... Z.
// Print the final array. Can't move off the edge or onto a letter. If
// no moves are left, must terminate.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// silence debug output by defining "NoDEBUG"
#define NDEBUG 1
#include "dbg.h"

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

#define NORTH 0b0001
#define SOUTH 0b0010
#define EAST 0b0100
#define WEST 0b1000

static char board[10][10];
// initialize off board means first move must be to 0,0
static int coord[2] = {-1, 0};
static int delta[2] = {0};

int set_delta_if_legal(uint8_t dir) {
  int d[2] = {0, 0}; // delta from directions
  int n[2];          // next coord for testing
  delta[0] = 0;
  delta[1] = 0; // reset delta!
  switch (dir) {
  case NORTH:
    d[0] = -1;
    break;
  case SOUTH:
    d[0] = 1;
    break;
  case EAST:
    d[1] = 1;
    break;
  case WEST:
    d[1] = -1;
    break;
  }
  // Make next coord for testing
  n[0] = coord[0] + d[0];
  n[1] = coord[1] + d[1];
  debug("Checking coord={%d, %d} with delta={%d, %d} makes next={%d, %d}",
        coord[0], coord[1], d[0], d[1], n[0], n[1]);
  if ((n[0] < 0 || n[0] > 9) || (n[1] < 0 || n[1] > 9)) {
    // Out of bounds
    return -1;
  }
  if (board[n[0]][n[1]] != '.') {
    // On a tile that has been occupied
    debug("(%d, %d) is occupied!", n[0], n[1]);
    return -1;
  }

  // Set the global "delta" value and return "true"
  delta[0] = d[0];
  delta[1] = d[1];
  debug("setting delta = {%d, %d}", delta[0], delta[1]);

  return 1;
}

int get_valid_direction() {
  uint8_t dirs = 0;
  uint8_t dir;
  // Generate up to 4 random directions
  while (dirs != 0b1111) {
    dir = rand() % 4;
    debug("Trying direction %d\tdirs=%d", dir, dirs);
    switch (dir) {
    case 0:
      dir = NORTH;
      dirs |= NORTH;
      break;
    case 1:
      dir = SOUTH;
      dirs |= SOUTH;
      break;
    case 2:
      dir = EAST;
      dirs |= EAST;
      break;
    case 3:
      dir = WEST;
      dirs |= WEST;
      break;
    }
    // Test move validity
    if (set_delta_if_legal(dir) > 0) {
      debug("Found valid direction");
      return 1;
    }
  }
  debug("No valid moves remaining!");
  return -1;
}

void print_board() {
  for (int r = 0; r < ELEMENTS(board); r++) {
    for (int c = 0; c < ELEMENTS(board); c++) {
      printf("%2c", board[r][c]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  char letter = 'A';
  int r, c;

  // seed the random number generator
  srand((unsigned)time(NULL));

  // Initialize Empty Board
  for (r = 0; r < 10; r++) {
    for (c = 0; c < 10; c++) {
      board[r][c] = '.';
    }
  }

  while (letter <= 'Z') {
    // Get a valid direction
    if (get_valid_direction() < 0) {
      // No valid moves left!
      break;
    }
    debug("Making move for letter %c", letter);
    debug("In main() : global delta = {%d, %d}", delta[0], delta[1]);
    // make move and advance the letter
    coord[0] = coord[0] + delta[0];
    coord[1] = coord[1] + delta[1];
    debug("coord = {%d, %d}\tdelta = {%d, %d}", coord[0], coord[1], delta[0],
          delta[1]);
    board[coord[0]][coord[1]] = letter;
    debug("board[%d][%d] = %c", coord[0], coord[1], letter);
    debug("coord = {%d, %d}", coord[0], coord[1]);
    letter++;
  }

  printf("\nFinal Board:\n\n");
  print_board();
  printf("\n\n");

  return EXIT_SUCCESS;
}
