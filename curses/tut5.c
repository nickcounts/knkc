#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

void start_ncurses(bool use_cbreak, bool use_no_echo) {
  initscr();
  if (use_no_echo)
    cbreak(); // ^c will exit ncurses program
  if (use_cbreak)
    noecho(); // user input does not print to screen
  use_default_colors();
}

int main(int argc, char *argv[]) {

  // NCURSES START
  start_ncurses(true, true);

  // Start terminal colors
  if (!has_colors()) {
    printw("Terminal does not support color output");
    getch();
    return EXIT_FAILURE;
  }
  start_color();

  int y, x;
  getyx(stdscr, y, x);

  WINDOW *win = newwin(y + 10, x + 20, 10, 10);

  // int yBeg, xBeg;
  // getbegyx(stdscr, yBeg, xBeg);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  mvwprintw(win, yMax / 2, xMax / 2, "Centered Text");

  // wait for keypress before exiting
  getch();
  endwin();

  return EXIT_SUCCESS;
}
