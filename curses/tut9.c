
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define KEY_ESC 27

void start_ncurses(bool use_cbreak, bool use_no_echo) {
  initscr();
  if (use_no_echo)
    cbreak(); // ^c will exit ncurses program
  if (use_cbreak)
    noecho(); // user input does not print to screen
}

int main(int argc, char *argv[]) {

  // NCURSES START
  start_ncurses(true, true);
  ESCDELAY = 10;

  WINDOW *win = newwin(10, 30, 0, 0);
  box(win, 0, 0);
  refresh(); // this refreshes the stdscr

  // wrefresh(win); // this refreshes the WINDOW win
  wgetch(win); // wgetch automatically refreshes the target window

  getch();
  endwin();
  return EXIT_SUCCESS;
}
