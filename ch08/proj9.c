// Write a program that generates a random walk across a 10x19 array
// The array will contain all '.' initially. Walk randomly from element
// to element, leaving the letters A ... Z.
// Print the final array. Can't move off the edge or onto a letter. If
// no moves are left, must terminate.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

#define NORTH 0b0001
#define SOUTH 0b0010
#define EAST 0b0100
#define WEST 0b1000

char board[10][10];

uint8_t get_valid_direction() {
  uint8_t dirs = 0;
  uint8_t dir;
  // Generate up to 4 random directions
  while (dirs != 0b1111) {
    dir = rand() % 4;
    switch (dir) {
    case NORTH:
      dirs |= NORTH;
      break;
    case SOUTH:
      dirs |= SOUTH;
      break;
    case EAST:
      dirs |= EAST;
      break;
    case WEST:
      dirs |= WEST;
      break;
    }
    // Test move validity
  }
  return -1;
}

int main(int argc, char *argv[]) {
  char letter = 'A';
  int r, c, d;

  // Initialize Empty Board
  for (r = 0; r < 10; r++) {
    for (c = 0; c < 10; c++) {
      board[r][c] = '.';
    }
  }

  while (letter <= 'Z') {
    // Get a valid direction
  }

  return EXIT_SUCCESS;
}
