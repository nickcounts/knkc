#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define KEY_ESC 27

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
  ESCDELAY = 10;

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

  // Create a window for our menu
  WINDOW *menu_win = newwin(6, xMax - 12, yMax - 8, 5);
  box(menu_win, 0, 0);
  refresh();
  wrefresh(menu_win);
  keypad(menu_win, true); // forces keypad to arrows

  char *choices[3] = {"Walk", "Jog", "Run"};
  int choice;
  int highlight = 0;

  while (true) {
    for (int i = 0; i < 3; i++) {
      if (i == highlight)
        wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, i + 1, 1, choices[i]);
      wattroff(menu_win, A_REVERSE);
    }
    choice = wgetch(menu_win);

    switch (choice) {
    case 'k':
    case 'K':
    case KEY_UP:
      if (highlight > 0)
        highlight--;
      break;

    case 'j':
    case 'J':
    case KEY_DOWN:
      if (highlight < (sizeof choices / sizeof *choices) - 1)
        highlight++;
      break;

    default:
      break;
    }

    if (choice == KEY_ESC)
      return EXIT_SUCCESS;

    if (choice == KEY_ENTER || choice == '\n')
      break;
  }

  printw("Your choice was: %s", choices[highlight]);
  getch();

  endwin();

  return EXIT_SUCCESS;
}
