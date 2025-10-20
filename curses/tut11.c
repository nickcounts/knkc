#include <ncurses.h>
#include <stdlib.h>

#define ctrl(x) (x & 0x1F) 

int main(int argc, char *argv[]) {
  initscr();
  noecho();

  if (has_colors() == FALSE) {
    endwin();
    printf("Color can't be started\n");
  }
  start_color();

  // Define 2 color pairs
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  attr_t empahasis = A_REVERSE | COLOR_PAIR(2);
  attron(empahasis);

  mvaddch(5, 5, 'a');
  mvaddch(5, 6, 'b');
  mvaddch(5, 7, 'c');
  attroff(empahasis);

  attron(A_REVERSE | COLOR_PAIR(2));
  mvaddch(7, 5, 'a');
  mvaddch(7, 6, 'b');
  mvaddch(7, 7, 'c');
  attroff(A_REVERSE | COLOR_PAIR(2));

  chtype c = '@' | A_REVERSE | COLOR_PAIR(1);

  mvaddch(9, 5, c);

  char ch = 0;
  while (ch != 'x') {
    ch = getch();
    mvprintw(1, 0, "KEY NAME : %s - 0x%02x\n", keyname(ch), ch);
    if (ch == ctrl('A')) {
      mvprintw(0, 0, "Detected CTRL+A");
    }
  } 

  endwin();

  return EXIT_SUCCESS;
}
