#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char pawns[8] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
const char kqbnr[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

void init_chess_board() {
  char chess_board[8][8];
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (((row + col) % 2) == 0) {
        // Even numbers (starting at 0,0)
        chess_board[row][col] = ' ';
      } else {
        chess_board[row][col] = '.';
      }
    }
  }
  // Back Rank Pieces:
  for (int col = 0; col < 8; col++) {
    chess_board[0][col] = toupper(kqbnr[col]);
    chess_board[7][col] = tolower(kqbnr[col]);
  }
  // Pawns:
  for (int col = 0; col < 8; col++) {
    chess_board[1][col] = toupper(pawns[col]);
    chess_board[6][col] = tolower(pawns[col]);
  }

  // Display board:
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      printf("%2c", chess_board[row][col]);
    }
    printf("\n");
  }
}

void init_checker_board() {
  char checker_board[8][8];
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      checker_board[row][col] = ((row + col) % 2 == 0) ? 'B' : 'R';
    }
  }

  // Display board:
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      printf("%2c", checker_board[row][col]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Please specify the game: chess or checkers\n");
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "chess") == 0) {
    init_chess_board();
  } else if (strcmp(argv[1], "checkers") == 0) {
    init_checker_board();
  }

  return EXIT_SUCCESS;
}
