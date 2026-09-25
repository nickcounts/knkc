/* Chapter 16, Exercise 18
 *
 * Declare a structure with the following members whos tag is a pinball
 * machine:
 *
 *   - name    : a string up to 40 characters
 *   - year    : an integer (the year of manufacture)
 *   - type    : an enumeration with the values EM (ElectroMech) and 
 *               SS (SolidState)
 *   - players : an integer representing the maximum number of players
 *
 */

#include <stdio.h>

// Pinball Machine Data Structure Definition
struct pinball {
  char name[42];
  int year;               // Manufacture Year
  enum { EM, SS} type;    // Electromechanical or Solid State
  int players;            // Max Players Allowed
};



void print_pinball(struct pinball p){
  printf("Name    : %s\n", p.name);
  printf("Year    : %d\n", p.year);
  printf("Players : %d\n", p.players);
  printf("Type    : %s\n", p.type==EM?"EM":"SS");
}


int main(void){
  struct pinball p1 = {
    .name = "Blade Runner",
    .year = 1982,
    .players = 4,
    .type = EM
  };

  print_pinball(p1);

  return 0;
}
