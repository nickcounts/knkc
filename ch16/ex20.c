/* Chapter 16, Exercise 20
 *
 * Suppose that the direction variable is declared in the following way:
 *
 *    enum (NORTH, SOUTH, EAST, WEST) direction;
 *
 * Let `x` and `y` be `int` variables. Write a `switch` statement that tests 
 * the value of direction, incrementing `x` if direction is EAST, decrementing
 * if WEST. Increment `y` if direction is SOUTH and decrement if NORTH.
 */

#include <stdio.h>

enum {NORTH, SOUTH, EAST, WEST} direction;

int main(void){
  int x = 0;
  int y = 0;
  direction = NORTH;

  switch (direction){
    case NORTH:
      y--;
      break;
    case SOUTH:
      y++;
      break;
    case EAST:
      x++;
      break;
    case WEST:
      y--;
      break;
  }

  return 0;
}





