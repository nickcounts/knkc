// Evaluate a chess position by summing the value of both players' pieces and returning
// the difference. Positive value is white's advantage

#include <stdio.h>

#define QUEEN  9
#define ROOK   5
#define BISHOP 3
#define KNIGHT 3
#define PAWN   1



int evaluate_position(char board[8][8]){
  int position_value = 0;
  char *square = board[0];
  char *first_square = board[0];

  int sq_val = 0;
  while (square - first_square < 8*8) {
    // printf("square ptr: %p\n", square);

    switch (*square) {
      default:
        sq_val = 0;
        break;

      case 'Q':
        sq_val = QUEEN;
        break;
      case 'R':
        sq_val = ROOK;
        break;
      case 'B':
        sq_val = BISHOP;
        break;
      case 'N':
        sq_val = KNIGHT;
        break;
      case 'P':
        sq_val = PAWN;
        break;
    
      case 'q':
        sq_val = -QUEEN;
        break;
      case 'r':
        sq_val = -ROOK;
        break;
      case 'b':
        sq_val = -BISHOP;
        break;
      case 'n':
        sq_val = -KNIGHT;
        break;
      case 'p':
        sq_val = -PAWN;
        break;
          
    }
    // printf("Square contains %c valued at %d\n", *square, sq_val);
    position_value += sq_val;
    square++;
  }
  return position_value;
}


int main(){
  char board[8][8] = {
    {'r','n','b','k','q','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','K','Q','B','N','R'},
  };

  printf("The position evaluates to: %d\n", evaluate_position(board));

  char board2[8][8] = {
    {'r','n','b','k','q','b','n','r'},
    {'p','p','p',' ','p','p','p','p'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ','P',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'P','P','P','P',' ','P','P','P'},
    {'R','N','B','K','Q','B','N','R'},
  };

  printf("The position evaluates to: %d\n", evaluate_position(board2));
  return 0;
}




