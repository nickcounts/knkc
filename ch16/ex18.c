/* Chapter 16, Exercise 18
 *
 * Each square of a chessboard can hold one piece: a pawn, knight, bishop,
 * rook, queen, or king. Each piece is either black or white.
 *
 * a) define two enumerated types: 
 *      - `Pieces` which has seven possible values (one is empty)
 *      - `Color` which has two 
 *
 * b) Using the types from part (a) define a data structure type named `Square`
 *    that can store both the type of a piece and its color
 *
 * c) Using the `Square` type from part (b), declare an 8x8 array named 
 *    `Board` that can store the entire contents of a chessboard.
 *
 * d) Add an initializer to the declaration in part (c) so that `board` 's
 *    initial value corresponds the the usual arrangement of pieces at the 
 *    start of a chess game.
 *
 *    A square that is not occupied by a piece should have an `empty` 
 *    piece value and the color `black`
 */

#include <stdio.h>


#define C_BLACK          "\x1b[30m"
#define C_RED            "\x1b[31m"
#define C_GREEN          "\x1b[32m"
#define C_YELLOW         "\x1b[33m"
#define C_BLUE           "\x1b[34m"
#define C_MAGENTA        "\x1b[35m"
#define C_CYAN           "\x1b[36m"
#define C_GRAY           "\x1b[37m"
#define C_LIGHT_BLACK    "\x1b[90m"
#define C_LIGHT_RED      "\x1b[91m"
#define C_LIGHT_GREEN    "\x1b[92m"
#define C_LIGHT_YELLOW   "\x1b[93m"
#define C_LIGHT_BLUE     "\x1b[94m"
#define C_LIGHT_MAGENTA  "\x1b[95m"
#define C_LIGHT_CYAN     "\x1b[96m"
#define C_WHITE          "\x1b[97m"
#define C_RESET          "\x1b[0m"

#define CBG_DARK_GRAY  "\x1b[100m"
#define CBG_BLACK      "\x1b[40m"
#define CBG_LIGHT_GRAY "\x1b[47m"
#define CBG_WHITE      "\x1b[107m"


// --------------------------------------------------------
// Part A) Enumeration definition
// --------------------------------------------------------

typedef enum {
  E,    // No piece on the square
  P,
  N,
  B,
  R,
  Q,
  K,
} Pieces;

typedef enum {
  BK, // Default color
  WT,
} Color;


// --------------------------------------------------------
// Part B) Square structure def
// --------------------------------------------------------

typedef struct {
  Color color;
  Pieces piece;
} Square;


// --------------------------------------------------------
// Part C) Initialize an 8x8 `board` array
// --------------------------------------------------------

Square board[8][8] = {
  {{BK, R}, {BK, N}, {BK, B}, {BK, Q}, {BK, K}, {BK, B}, {BK, N}, {BK, R}},
  {{BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}},
  {{WT, R}, {WT, N}, {WT, B}, {WT, Q}, {WT, K}, {WT, B}, {WT, N}, {WT, R}},
};



// --------------------------------------------------------
// Above and Beyond Functions
// --------------------------------------------------------

#define W_KING   "\u2654"
#define W_QUEEN  "\u2655"
#define W_ROOK   "\u2656"
#define W_BISH   "\u2657"
#define W_KNIGHT "\u2658"
#define W_PAWN   "\u2659"

#define B_KING   "\u265A"
#define B_QUEEN  "\u265B"
#define B_ROOK   "\u265C"
#define B_BISH   "\u265D"
#define B_KNIGHT "\u265E"
#define B_PAWN   "\u265F"

//                                  [FG]      [BG]
#define C_DARK_SQUARE_BK  "\x1b[38;5;235;48;5;242m"
#define C_DARK_SQUARE_WT  "\x1b[38;5;255;48;5;242m"

#define C_LIGHT_SQUARE_BK "\x1b[38;5;235;48;5;252m"
#define C_LIGHT_SQUARE_WT "\x1b[38;5;255;48;5;252m"

void print_board(void){
  Color this_square_color = WT;
  Square this_square;

  for (int row = 7; row>=0; row--){
    printf(C_RESET "Row %d : ", row);

    for (int col = 0; col<8; col++){
      this_square = board[row][col];

      // Print Alternating Square Color
      if (this_square_color == BK)  // DARK SQUARE
        printf(C_DARK_SQUARE_WT);
        // if (this_square.color == BK) 
        //   printf(C_DARK_SQUARE_WT);
        // else 
        //   printf(C_DARK_SQUARE_BK);

      else                          // LIGHT SQUARE
        printf(C_LIGHT_SQUARE_WT); 
        // if (this_square.color == WT)
        //   printf(C_LIGHT_SQUARE_WT); 
        // else
        //   printf(C_LIGHT_SQUARE_BK);

      this_square_color = !this_square_color;


      switch (this_square.color){
        case BK:
          switch (this_square.piece) {
            case P:
              printf(B_PAWN);
              break;
            case N:
              printf(B_KNIGHT);
              break;
            case B:
              printf(B_BISH);
              break;
            case R:
              printf(B_ROOK);
              break;
            case K:
              printf(B_KING);
              break;
            case Q:
              printf(B_QUEEN);
              break;
            default:
              printf(" ");
          }
          break;
        case WT:
          switch (this_square.piece) {
            case P:
              printf(W_PAWN);
              break;
            case N:
              printf(W_KNIGHT);
              break;
            case B:
              printf(W_BISH);
              break;
            case R:
              printf(W_ROOK);
              break;
            case K:
              printf(W_KING);
              break;
            case Q:
              printf(W_QUEEN);
              break;
            default:
              printf(" ");
          }
      }
    }
    printf(C_RESET "\n"); // end of row
    this_square_color = !this_square_color;
  }
}


int main(void) {
  print_board();

  printf(C_DARK_SQUARE_WT "C_DARK_SQUARE_WT"   C_RESET "\n");
  printf(C_DARK_SQUARE_BK "C_DARK_SQUARE_BK"   C_RESET "\n");
  printf(C_LIGHT_SQUARE_WT "C_LIGHT_SQUARE_WT" C_RESET "\n");
  printf(C_LIGHT_SQUARE_BK "C_LIGHT_SQUARE_BK" C_RESET "\n");

  return 0;
}


