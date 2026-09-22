/* Chapter 16, Exercise 14
 *
 * Let `shape` be the structure from Exercise 13. Write functions that
 * perform the following operations on a `shape` structure `s` passed
 * as an argument:
 *
 * a) Compute the area of `s`
 * b) Move `s` by `x` units in the `x` direction and `y` units in the 
 *    `y` direction.
 * c) Scale `s` by a factor of `c` (a `double`) returning the modified
 *    version of `s`
 */

#include <stdio.h>

struct point {
  int x, y;
};

typedef enum {RECTANGLE, CIRCLE} shape_kind;

struct shape {
  shape_kind shape_kind;                /* RECTANGLE or CIRCLE */
  struct point center;                  /* coordinates of cente r*/
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
} s;



// a) Compute the area of `s`
// Returns 0 for invalid shape
int area_of_shape(struct shape s){
  switch (s.shape_kind) {

    case RECTANGLE:
      return s.u.rectangle.height * s.u.rectangle.width;

    case CIRCLE:
      return 3.14159 * s.u.circle.radius * s.u.circle.radius;

    default:
      return 0;
      break;
  }
}


// b) Move `s` by `x` units in the `x` direction and `y` units in the 
//   `y` direction. return the modified version of `s`
struct shape move_shape(struct shape s, int x, int y){
  s.center.x += x;
  s.center.y += y;
  return s;
}


// c) Scale `s` by a factor of `c` (a `double`) returning the modified
//    version of `s`
struct shape scale_shape(struct shape s, double c){
  switch (s.shape_kind) {
    case RECTANGLE:
      s.u.rectangle.height *= c;
      s.u.rectangle.width *= c;
      return s;

    case CIRCLE:
      s.u.circle.radius *= 2;
      return s;

    default:
      return s;
  }
}


// -------------------------------------------------- 
//                       Helpers
// -------------------------------------------------- 

#define RESET    "\x1b[0m"
#define B_YELLOW "\x1b[93m"

void print_point(struct point p){
  printf("(%d,%d)\n", p.x, p.y);
}

void print_section_header(char *part, char *func){
  printf("\nPart %s : " B_YELLOW "%s\n" RESET, part, func);
}


// -------------------------------------------------- 
//                   program entry
// -------------------------------------------------- 

int main(void){
  struct shape sq = {
    .shape_kind = RECTANGLE,
    .center.x = 0,
    .center.y = 0,
    .u.rectangle.height = 2,
    .u.rectangle.width = 2,
  };

  struct shape cir = {
    .shape_kind = CIRCLE,
    .center.x = 0,
    .center.y = 0,
    .u.circle.radius = 2,
  };


  print_section_header("A", "area_of_shape()");
  printf("Area of original square: %d\n", area_of_shape(sq));
  printf("Area of doubled square: %d\n", area_of_shape(scale_shape(sq, 2.0)));

  printf("Area of original circle: %d\n", area_of_shape(cir));
  printf("Area of doubled circle: %d\n", area_of_shape(scale_shape(cir, 2.0)));


  print_section_header("B", "move_shape()");
  printf("Original shape centers:\n");
  printf("Rectangle: "); print_point(sq.center);
  printf("Circle:    "); print_point(cir.center);
  
  printf("Moved shape centers:\n");
  printf("Rectangle: "); print_point(move_shape(sq, 3, 3).center);
  printf("Circle:    "); print_point(move_shape(cir, 3, 3).center);


  print_section_header("C", "scale_shape()");
  printf("Scaled shapes:\n");
  printf("This is already covered by the 'Area' section\n");




  return 0;
}



