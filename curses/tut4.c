#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

void start_ncurses(bool hide_echo, bool use_cbreak) {
  initscr();
  if (hide_echo)
    cbreak(); // ^c will exit ncurses program
  if (use_cbreak)
    noecho(); // user input does not print to screen
  use_default_colors();
}

int main(int argc, char *argv[]) {

  // NCURSES START
  start_ncurses(true, true);
  if (!has_colors()) {
    printw("Terminal does not support color output");
    getch();
    return EXIT_FAILURE;
  }
  start_color();

  /*
   * A_NORMAL
   * A_STANDOUT
   * A_REVERSE
   * A_BLINK
   * A_DIM
   * A_BOLD
   * A_PROTECT
   * A_INVIS
   * A_ALTCHARSET
   * A_CHARTEXT
   */

  init_pair(1, COLOR_BLUE, COLOR_WHITE);
  attron(COLOR_PAIR(1));
  printw("This is some text");
  attroff(COLOR_PAIR(1));

  /*
   * COLOR_PAIR(n)
   * COLOR_BLACK   0
   * COLOR_RED     1
   * COLOR_GREEN   2
   * COLOR_YELLOW  3
   * COLOR_BLUE    4
   * COLOR_MAGENTA 5
   * COLOR_CYAN    6
   * COLOR_WHITE   7
   */

  getch();

  endwin();

  return EXIT_SUCCESS;
}
