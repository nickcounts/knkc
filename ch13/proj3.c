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
#define FULL_NAME_STRLEN 16

typedef struct{
  char short_name;
  char full_name[FULL_NAME_STRLEN];
} card_names ;

card_names CARDS[16] = {
  {'2', "Two"},
  {'3', "Three"},
  {'4', "Four"},
  {'5', "Five"},
  {'6', "Six"},
  {'7', "Seven"},
  {'8', "Eight"},
  {'9', "Nine"},
  {'j', "Jack"},
  {'q', "Queen"},
  {'k', "King"},
  {'a', "Ace"},
  {'c', "Clubs"},
  {'d', "Diamonds"},
  {'h', "Hearts"},
  {'s', "Spades"},
};

char * full_string_from_short(char key){
  for (int i = 0; i < 16; i++){
    if (CARDS[i].short_name == key){
      return CARDS[i].full_name;
    }
  }
  return "";
}

int main(int argc, char *argv[]) {
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                            '9', 't', 'j', 'q', 'k', 'a'};
  const char suit_code[] = {'c', 'd', 'h', 's'};

  srand((unsigned)time(NULL));

  printf("Enter the number of cards in hand: ");
  scanf("%d", &num_cards);

  printf("Your hand: \n");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf("%s of %s\n", full_string_from_short(rank_code[rank]), 
                           full_string_from_short(suit_code[suit]));
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
