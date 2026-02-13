/* Modify the `deal.c` program of section 8.2 so that it prints the full names
   of the cards it deals:
  
   Enter the number of cards in hand: 5
   Your hand:
   Seven of clubs
   Two of spades
   Five of diamonds
   Ace of spades
   Two of Hearts
  
   Hint: Replace rang_code and suit_code by arrays containing pointers to 
   strings
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(int argc, char *argv[]) {
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                            '9', 't', 'j', 'q', 'k', 'a'};
  const char suit_code[] = {'c', 'd', 'h', 's'};

  srand((unsigned)time(NULL));

  printf("Enter the number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand: ");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
