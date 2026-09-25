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
  BK = 0, // Default color
  WT = 1,
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
  {{WT, R}, {WT, N}, {WT, B}, {WT, Q}, {WT, K}, {WT, B}, {WT, N}, {WT, R}},
  {{WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}, {WT, P}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}, {BK, E}},
  {{BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}, {BK, P}},
  {{BK, R}, {BK, N}, {BK, B}, {BK, Q}, {BK, K}, {BK, B}, {BK, N}, {BK, R}},
};



// --------------------------------------------------------
// Above and Beyond Functions
// --------------------------------------------------------

#define O_KING   "\u2654"
#define O_QUEEN  "\u2655"
#define O_ROOK   "\u2656"
#define O_BISH   "\u2657"
#define O_KNIGHT "\u2658"
#define O_PAWN   "\u2659"

#define S_KING   "\u265A"
#define S_QUEEN  "\u265B"
#define S_ROOK   "\u265C"
#define S_BISH   "\u265D"
#define S_KNIGHT "\u265E"
#define S_PAWN   "\u265F"

//                                  [FG]      [BG]
#define C_DARK_SQUARE_BK  "\x1b[38;5;235;48;5;242m"
#define C_DARK_SQUARE_WT  "\x1b[38;5;255;48;5;242m"

#define C_LIGHT_SQUARE_BK "\x1b[38;5;235;48;5;252m"
#define C_LIGHT_SQUARE_WT "\x1b[38;5;255;48;5;252m"

// Pass the color of the squ
void print_piece(Color cs, Color cp, Pieces p){
  int use_outline = 0;

  // All are solid, regular color except white on white
  if (cs == BK){
    cp == WT ? printf(C_DARK_SQUARE_WT) : printf(C_DARK_SQUARE_BK);
  } else if (cp == BK) {
    printf(C_LIGHT_SQUARE_BK);
  } else {
    printf(C_LIGHT_SQUARE_BK);
    use_outline = 1;
  }
  
  // printf("%d%d%d%d",cs,cp,p,use_outline);

  printf(" ");
  if (p == E) {
    printf(" ");
    printf(" ");
    return;
  }

  if (p == P)
    use_outline ? printf(O_PAWN)   : printf(S_PAWN)  ;
  if (p == N)
    use_outline ? printf(O_KNIGHT) : printf(S_KNIGHT);
  if (p == B)
    use_outline ? printf(O_BISH)   : printf(S_BISH)  ;
  if (p == R)
    use_outline ? printf(O_ROOK)   : printf(S_ROOK)  ;
  if (p == Q)
    use_outline ? printf(O_QUEEN)  : printf(S_QUEEN) ;
  if (p == K)
    use_outline ? printf(O_KING)   : printf(S_KING)  ;
  printf(" ");
}


void print_board(void){
  Color square_color = WT;
  Color piece_color  = WT;
  Square this_square;

  for (int row = 7; row>=0; row--){
    printf(C_RESET "Row %d : ", row + 1);

    for (int col = 0; col<8; col++){
      this_square = board[row][col];
      piece_color = this_square.color;

      print_piece(square_color, piece_color, this_square.piece);
      square_color = !square_color;
    }

    printf(C_RESET "\n"); // end of row
    square_color = !square_color;
  }
  printf("         A  B  C  D  E  F  G  H\n" );
}


int main(void) {
  print_board();
  return 0;
}


