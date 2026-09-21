/* Chapter 16, Exercise 8
 *
 * Let `color` be the following structure:
 *
 * struct color {
 *  int red;
 *  int green;
 *  int blue;
 * };
 *
 * a) Write a decaration for a `const` variable named MAGENTA of type 
 *    `struct color` whose members have the values 255, 0, 255
 *
 * b) (C99) Repeat part (a), but use a designated initializer that doesn't 
 *    specify the value of `green`, allowing it to default to 0;
 */


#include <stdio.h>

#define RESET    "\x1b[0m"
#define RED            "\x1b[31m"
#define GREEN          "\x1b[32m"
#define BLUE           "\x1b[34m"

#define TEST "\033[38;2;255;0;255m"

struct color {
  int red;
  int green;
  int blue;
};


void print_color(struct color c, char *color_name){
  char COLOR[32];
  sprintf(COLOR, "\033[38;2;%d;%d;%dm", c.red, c.green, c.blue);
  printf("(");
  printf(RED   "%3d" RESET ", ", c.red);
  printf(GREEN "%3d" RESET ", ", c.green);
  printf(BLUE  "%3d" RESET ") : ",  c.blue);
  printf("%s%s" RESET "\n", COLOR, color_name);
}

int main(void){
  const struct color MAGENTA = {255, 0, 255};

  print_color(MAGENTA, "MAGENTA");


  const struct color MAGENTA2 = {.red=255, .blue=255};
  print_color(MAGENTA2, "MAGENTA2 Electric Boogaloo");

  const struct color MARS_RED = {.red=255, .green=175};
  print_color(MARS_RED, "MARS RED");



  return 0;
}
