// Project 8
// Write a program that simulates the game of craps.
// A player rolls two dice. On the first roll, the player wins if the dice
// sum to 7 or 11
// The player loses if the sum is 2, 3, or 12.
// Any other roll is called the "point" and the game continues. On each
// subsequent roll, the player wins if he rolls the "point".
// The player loses if he rolls a 7.
//
// After the game, prompt user to play again. If they say no, display their
// wins and losses

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void) {
  // simulates rolling two dice and returns the sum
  int d1, d2;
  d1 = 1 + (rand() % 6);
  d2 = 1 + (rand() % 6);
  return d1 + d2;
}

int play_to_end(int point) {
  // takes the "point" and returns 1 if player wins.
  int roll = roll_dice();
  for (;;) {
    printf("You rolled: %2d\n", roll);
    if (roll == point) {
      // Player wins!
      return 1;
    } else if (roll == 7) {
      // Player loses!
      return 0;
    }
    roll = roll_dice();
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int games, wins, this_game, point;
  int roll;
  char play_again = 'y';
  games = 0;
  wins = 0;

  // Seed the random number generator with system time
  srand((unsigned)time(NULL));

  while (play_again == 'y' || play_again == 'Y') {
    games++;
    roll = roll_dice();
    printf("You rolled: %2d\n", roll);

    // First Roll
    if (roll == 7 || roll == 11) {
      // Win on first roll
      wins++;
      printf("You win!\n\n");

    } else if (roll == 2 || roll == 3 || roll == 12) {
      // Lose on first roll
      printf("You lose!\n\n");
    } else {
      // Normal Game
      point = roll;
      printf("Your point is %d\n", point);

      this_game = play_to_end(point);
      wins += this_game;

      if (this_game == 1) {
        printf("You win!\n\n");
      } else {
        printf("You lose!\n\n");
      }
    }

    printf("Play again? ");
    play_again = getchar();
    fflush(stdin);
  }

  printf("\nWins: %d\tLosses: %d\n", wins, games - wins);

  return EXIT_SUCCESS;
}
