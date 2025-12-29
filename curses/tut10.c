#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#define KEY_ESC 27

void start_ncurses(bool use_cbreak, bool use_no_echo) {
  initscr();
  if (use_no_echo)
    // The user's input is immediately available to the program
    cbreak(); // ^c will exit ncurses program

  if (use_cbreak)
    noecho(); // user input does not print to screen
}

int main(int argc, char *argv[]) {

  // NCURSES START
  start_ncurses(true, true);
  // Use this like non-blocking input
  halfdelay(5); // 5 tenths of a second delay before returning ERR if no input
  // nodelay(stdscr, true);
  // timeout(500);

  ESCDELAY = 10;

  int c;
  while ((c = getch()) != 'x') {
    if (c >= 0)
      printw("%d\n", c);
  }

  endwin();
  return EXIT_SUCCESS;
}
