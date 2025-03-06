// Write a program that takes a first name and a last name entered by the user
// and displays the last name, a comma, and the first initial, followed by a
// period.
//
// The user's input may contain extra spaces before the first name, between
// the first and last names, and after the last name.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char c;
  char fullname[256];
  char first[256];
  char last[256];
  int i = 0;

  // This gets the input but doesn't handle backspace... whole thing is a tad
  // scary. I may try to write extra logic to handle backspace
  printf("Enter a first and last name: ");
  while ((c = getchar()) != '\n' && i < 256) {
    fullname[i] = c;
    i++;
  }

  // printf("User entered: %s\n", fullname);

  // This whole chunk is really a tokenizer that's been repeated.
  // If I have to do this again, I should look at breaking it out
  // into a function. Do I return a token, or a start/stop index?

  int i_full, i_first, i_last;
  i_full = i_first = i_last = 0;

  // Find First Name
  while (i_full < 256) {
    if (fullname[i_full] != ' ') {
      break;
    }
    i_full++;
  }

  // Populate First Name
  while (i_full < 256) {
    if (fullname[i_full] == ' ') {
      // End of first name
      first[i_first] = 0;
      i_full++;
      break;
    }
    first[i_first] = fullname[i_full];
    i_first++;
    i_full++;
  }

  // Find Start of Last Name
  while (i_full < 256) {
    if (fullname[i_full] != ' ') {
      break;
    }
    i_full++;
  }

  // Populate Last Name
  while (i_full < 256) {
    if (fullname[i_full] == ' ') {
      // End of last name
      last[i_last] = 0;
      i_full++;
      break;
    }
    last[i_last] = fullname[i_full];
    i_last++;
    i_full++;
  }

  printf("%s, %c.\n", last, first[0]);

  return EXIT_SUCCESS;
}
