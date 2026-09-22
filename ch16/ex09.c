/* Chapter 16, Exercise 9
 *
 * Write the following functions (The `color` structure is defined in
 * Exercise 8)
 *
 * struct color {
 *  int red;
 *  int green;
 *  int blue;
 * };
 *
 * a) struct color make_color(int red, int green, int blue);
 *    Return a `color` structure containing the specified RGB values.
 *    If any argument is outside the valid bounds, clamp to 0-255
 *
 * b) int getRed(struct color c);
 *    Returns the value of `c`'s `red` member
 *
 * c) bool equal_color(struct color c1, struct color c2);
 *    Returns true if all corresponding members of the input structs
 *    are equal
 *
 * d) struct color brighter(struct color c);
 *    Returns a `color` structure that represents a brighter version of the
 *    color `c` except that each member has been divided by 0.7 with the 
 *    result truncated to an integer. If all members are 0, returns 3,3,3. 
 *    If any member is less than 3 before division, it is replaced by 3. 
 *    Values are clamped to 255
 *
 * e) struct color darker(struct color c);
 *    Returns a `color` structure that represents a darker version of the 
 *    color `c` where each member has been multiplied by 0.7. 
 */

#include <stdio.h>
#include <stdbool.h>

#define RESET    "\x1b[0m"
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define BLUE     "\x1b[34m"
#define B_YELLOW   "\x1b[93m"


struct color {
  int red;
  int green;
  int blue;
};


int clamp(int v, int min, int max){
  if (v < min) return min;
  if (v > max) return max;
  return v;
}


void print_color(struct color c, char *color_name){
  char COLOR[32];
  sprintf(COLOR, "\033[38;2;%d;%d;%dm", c.red, c.green, c.blue);
  printf("(");
  printf(RED   "%3d" RESET ", ", c.red);
  printf(GREEN "%3d" RESET ", ", c.green);
  printf(BLUE  "%3d" RESET ") : ",  c.blue);
  printf("%s%s" RESET "\n", COLOR, color_name);
}


// Return a `color` structure containing the specified RGB values.
// If any argument is outside the valid bounds, clamp to 0-255
struct color make_color(int red, int green, int blue){
  return (struct color) {
    .red   = clamp(red,   0, 255),
    .green = clamp(green, 0, 255),
    .blue  = clamp(blue,  0, 255),
  };
}


// Returns the value of `c` `red` member
int getRed(struct color c){
  return c.red;
}


// Returns true if all corresponding members of the input structs
// are equal
bool equal_color(struct color c1, struct color c2){
  if (   c1.blue  == c2.blue 
      && c1.red   == c2.red 
      && c1.green == c2.green)
    return true;
  else
   return false;
}

// Returns a `color` structure that represents a brighter version of the
// color `c` except that each member has been divided by 0.7 with the 
// result truncated to an integer. If all members are 0, returns 3,3,3. 
// If any member is less than 3 before division, it is replaced by 3. 
// Values are clamped to 255
struct color brighter(struct color c){
  struct color c2 = make_color(
      clamp(c.red, 3, 255), 
      clamp(c.green, 3, 255), 
      clamp(c.blue, 3, 255)
  );

  c2.red   /= 0.7;
  c2.green /= 0.7;
  c2.blue  /= 0.7;

  // make_color() automatically clamps
  return make_color(c2.red, c2.green, c2.blue);
}
 

// Returns a `color` structure that represents a darker version of the 
// color `c` where each member has been multiplied by 0.7. 
struct color darker(struct color c){
  c.red   *= 0.7;
  c.green *= 0.7;
  c.blue  *= 0.7;

  return c;
}

void print_section_header(char *part, char *func){
  printf("\nPart %s : " B_YELLOW "%s\n" RESET, part, func);
}


int main(void){

  // a) using `make_color()` with value that clamps to CYAN ------------------
  print_section_header("a", "make_color()");

  struct color cyan = make_color(0, 255, 255);
  struct color clamped_cyan = make_color(-100, 500, 255); // Terrible cyan
  struct color meaningful_red = make_color(123, 15, 79);

  print_color(clamped_cyan,   "CLAMPED_CYAN");
  print_color(cyan,           "CYAN");
  print_color(meaningful_red, "meaningful_red");


  // b) using `getRed()` -----------------------------------------------------
  print_section_header("b", "getRed()");
  char red_value[64];
  sprintf(red_value, "getRed(meaningful_red) = %3d", getRed(meaningful_red));
  print_color(meaningful_red, red_value);


  // c) use equal_color() ----------------------------------------------------
  print_section_header("c", "equal_color()");
  print_color(cyan, "CYAN");
  printf("  clamped_cyan == cyan : %s\n", 
      equal_color(clamped_cyan, cyan) ? "TRUE" : "FALSE");
  printf("meaningful_red == cyan : %s\n", 
      equal_color(meaningful_red, cyan) ? "TRUE" : "FALSE");


  // d) brighter() -----------------------------------------------------------
  print_section_header("d", "brighter()");
  print_color(brighter(meaningful_red), "BRIGHTER meaningful_red");
  print_color(brighter(brighter(meaningful_red)), "BRIGHTER BRIGHTER meaningful_red");
  print_color(brighter(cyan), "BRIGHTER CYAN");
  print_color(brighter(brighter(cyan)), "BRIGHTER BRIGHTER CYAN");


  // e) darker() -------------------------------------------------------------
  print_section_header("e", "darker()");
  print_color(darker(meaningful_red), "DARKER meaningful_red");
  print_color(darker(cyan), "DARKER CYAN");
  print_color(darker(darker(cyan)), "DARKER DARKER CYAN");

  return 0;
}

