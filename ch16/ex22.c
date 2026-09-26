/* Chapter 16, Exercise 22
 *
 * Let `chess_pieces` be the following enumeration:
 *
 *  enum chess_pieces {
 *    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
 *  };
 *
 * a) Write a declaration (including an initializer) for a constant array of
 *    integers named `piece_values` that stores the numbers 200,9,5,3,3, and 1,
 *    representing the value of each chess piece.
 *
 * b) Repeat part (a) but use a designated initializer to initialize the array.
 *    Use the enumeration constants in `chess_pieces` as subscripts in the
 *    designators. 
 *    (Hint: See the last question in Q&A for an example)
 */

#include <stdio.h>


// Part A - (C89)
enum chess_pieces {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
};

const int piece_value[] = {
  200,9,5,3,3,1
};


// Part B - (C99)
const int piece_value_99[] = {
  [KING]   = 200,
  [QUEEN]  = 9,
  [ROOK]   = 5,
  [BISHOP] = 3,
  [KNIGHT] = 3,
  [PAWN]   = 1,
};



int main(void){
  // Utility
  const char *piece_names[] = {
    [KING]   = "King",
    [QUEEN]  = "Queen",
    [ROOK]   = "Rook"  ,
    [BISHOP] = "Bishop",
    [KNIGHT] = "Knight",
    [PAWN]   = "Pawn"  ,
  };

  for (int i = 0; i < sizeof(piece_names)/sizeof(piece_names[0]); i++)
    printf("Value of %-6s : %d\n", piece_names[i], piece_value[i]);
  return 0;
}

