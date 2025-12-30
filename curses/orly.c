#include <curses.h>
#include <signal.h>
#include <stdlib.h>

void die();

int main() {
  initscr();
  signal(SIGINT, die);

  // spreadsheet();
  die();
}

void die() {
  // ignore interrupts
  signal(SIGINT, SIG_IGN);

  // move cursor to lower left
  mvcur(0, COLS - 1, LINES - 1, 0);

  // make terminal the way it was
  endwin();
  exit(EXIT_SUCCESS);
}
