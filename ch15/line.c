#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line() {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining() {
  return MAX_LINE_LEN - line_len;
}

void write_line() {
  int extra_spaces, spaces_to_insert, i, j;
  int remainder_spaces, print_extra_space_now;
  print_extra_space_now = 1;

  // extra_spaces = MAX_LINE_LEN - line_len;
  extra_spaces = space_remaining();
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      spaces_to_insert = extra_spaces / (num_words-1);
      remainder_spaces = extra_spaces % spaces_to_insert;

      // Proj 1: If there are remainder spaces, then spacing is uneven.
      // Add an extra space to spaces_to_insert if print_extra_space_now
      // and toggle print_extra_space_now to spread them out.
      // This isn't perfect, but it does result in more even distribution
      if (remainder_spaces > 0) {
        if (print_extra_space_now) {
          spaces_to_insert += 1;
          print_extra_space_now = 0;
        } else {
          print_extra_space_now = 1;
        }
      }

      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line() {
  if (line_len > 0)
    puts(line);
}


