#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

#define KEY_ESC 27

void user_input(Player *player, Room *room, WINDOW *room_win);

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

  // Get Screen Size
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // Create Game Window
  WINDOW *playwin = newwin((yMax * 4 / 6), (xMax - 10) / 2, yMax / 6, 10);
  keypad(playwin, true);

  box(playwin, 0, 0);
  refresh();
  wrefresh(playwin);

  // STARTING GAME SETUP
  int rxMin, ryMin, rxMax, ryMax;
  getmaxyx(playwin, ryMax, rxMax);
  getbegyx(playwin, ryMin, rxMin);

  Room room = {ryMin, rxMin, ryMax, rxMax};
  Player player = newPlayer(ryMax / 2, rxMax / 2, 'X', playwin);

  // GAME LOOP

  while (true) {
    mvwprintw(stdscr, 0, 0, "User Pos: %d, %d     ", player.yLoc, player.xLoc);
    wrefresh(stdscr);
    mvwaddch(playwin, player.yLoc, player.xLoc, player.character);
    wrefresh(playwin);
    user_input(&player, &room, playwin);
  }

  endwin();
  return EXIT_SUCCESS;
}

void user_input(Player *player, Room *room, WINDOW *room_win) {

  int input = wgetch(room_win);
  switch (input) {
  case 'k':
  case 'K':
  case KEY_UP:
    mvwaddch(room_win, player->yLoc, player->xLoc, ' ');
    move_player_up(player, room);
    break;

  case 'j':
  case 'J':
  case KEY_DOWN:
    mvwaddch(room_win, player->yLoc, player->xLoc, ' ');
    move_player_down(player, room);
    break;

  case 'h':
  case 'H':
  case KEY_LEFT:
    mvwaddch(room_win, player->yLoc, player->xLoc, ' ');
    move_player_left(player, room);
    break;

  case 'l':
  case 'L':
  case KEY_RIGHT:
    mvwaddch(room_win, player->yLoc, player->xLoc, ' ');
    move_player_right(player, room);
    break;

  default:
    break;
  }

  if (input == KEY_ESC || input == 'q' || input == 'Q') {
    endwin();
    exit(EXIT_SUCCESS);
  }
}
