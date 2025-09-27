#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // Initializes the screen
  initscr();
  cbreak(); // ^c will exit ncurses program
  noecho(); // user input does not print to screen

  WINDOW *win;
  int height, width, start_row, start_col;

  height = 10;
  width = 20;
  start_col = start_row = 10;

  win = newwin(height, width, start_row, start_col);
  refresh(); // refresh entire screen with new window

  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  char top_char = '=';

  // box(win, 0, (int)top_char);
  mvwprintw(win, 1, 1, "This is my box");
  wrefresh(win); // refreshes just the internal window

  // Wait for user input, returns int value of keypress
  int c = getch();

  // deallocate memory and end ncurses
  endwin();

  return EXIT_SUCCESS;
}
