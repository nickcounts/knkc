// Use getchar() idioms to count the characters in user input
#include <stdio.h>

int main(void) {
  int length = 0;
  printf("Enter a message: ");
  while (getchar() != '\n') {
    length++;
  }

  printf("Your message was %d character(s) long.\n", length);
  return 0;
}
