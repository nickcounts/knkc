#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
  int xLoc;
  int yLoc;
  char character;
  WINDOW *curwin;
} Player;

typedef struct Room {
  int minY;
  int minX;
  int maxY;
  int maxX;
} Room;

Player newPlayer(int yLoc, int xLoc, char character, WINDOW *curWin) {
  Player tempPlayer = {xLoc, yLoc, character, curWin};
  return tempPlayer;
}

void move_player_up(Player *player, Room *room) {
  if (player->yLoc > 1)
    player->yLoc--;
}

void move_player_down(Player *player, Room *room) {
  if (player->yLoc < room->maxY - 2)
    player->yLoc++;
}

void move_player_left(Player *player, Room *room) {
  if (player->xLoc > 1)
    player->xLoc--;
}

void move_player_right(Player *player, Room *room) {
  if (player->xLoc < room->maxX - 2)
    player->xLoc++;
}

#endif // PLAYER_H
