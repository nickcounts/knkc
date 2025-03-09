// write a "B1FF" translator (leet-speak) generator that takes
// a user's input and translates it into leet-speek
// Be sure to append some number of ! to the end !!!!!!

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char char_lookup[26] = {['a' - 'a'] = '4', ['e' - 'a'] = '3',
                              ['i' - 'a'] = '1', ['o' - 'a'] = '0',
                              ['t' - 'a'] = '7', ['s' - 'a'] = '5'};

char get_leet(char c) {
  c = tolower(c);
  if (c < 'a' || c > 'z')
    return 0;

  return char_lookup[c - 'a'];
}

int main(int argc, char *argv[]) {

  // seed the random number generator?
  srand((unsigned)time(NULL));

  char buffer[256];
  printf("Enter message: ");
  scanf("%[^\n]s", buffer);

  int i = 0;
  char test;

  do {
    test = get_leet(buffer[i]);
    if (test) {
      printf("%c", test);
    } else {
      printf("%c", buffer[i]);
    }
  } while (buffer[++i]);

  int num_slammers = rand() % 10;
  num_slammers += 5;

  while (num_slammers) {
    printf("!");
    num_slammers--;
  }

  printf("\n");

  return EXIT_SUCCESS;
}
