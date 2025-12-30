
#include <ncurses.h>
#include <stdlib.h>

#define ctrl(x) (x & 0x1F)

void print_menu_titles(WINDOW *win) {
  wattron(win, A_NORMAL);
  mvwprintw(win, 0, 2, "File");
  mvwprintw(win, 0, 7, "Edit");
  mvwprintw(win, 0, 12, "Options");
  wrefresh(win);
}



int main(int argc, char *argv[]) {
  initscr();
  noecho();
  curs_set(0); // What does this do?

  if (has_colors() == FALSE) {
    endwin();
    printf("Color can't be started\n");
  }
  start_color();

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  box(win, 0, 0);
  refresh();

  print_menu_titles(win);


  // Define 2 color pairs
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

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
