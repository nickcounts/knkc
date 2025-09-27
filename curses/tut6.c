#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// void printMenu(WINDOW *menu, string choices[], int size, int highlight);

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

  // Start terminal colors
  if (!has_colors()) {
    printw("Terminal does not support color output");
    getch();
    return EXIT_FAILURE;
  }
  start_color();
  use_default_colors();

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // Create a window for our input
  WINDOW *inputwin = newwin(3, xMax - 12, yMax - 5, 5);
  box(inputwin, 0, 0);
  refresh();
  wrefresh(inputwin);

  keypad(inputwin, true); // forces keypad to arrows

  int c = wgetch(inputwin);
  if (c == KEY_UP) {
    mvwprintw(inputwin, 1, 1, "You pressed UP ARROW !!");
    wrefresh(inputwin);
  }

  // wait for keypress before exiting
  getch();
  endwin();

  return EXIT_SUCCESS;
}
