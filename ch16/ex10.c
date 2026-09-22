/* Chapter 16, Exercise 10
 *
 * The following structures are designed to store information about objects on
 * a graphics screen:
 *
 * struct point { int x, y; };
 * struct rectangle {struct point upper_left, lower_right; };
 *
 * A `point` stores the `x` and `y` coordinates of a point on screen. A 
 * `rectangle` structure stores the coordinates of the upper-left and lower-
 * right corners of a rectangle. 
 *
 * Write the functions that perform the following operations on a `rectange`
 * structure `r` passed as an argument:
 *
 * a) Compute the area of `r`
 *
 * b) Compute the center of `r`, returning it as a `point` value. If either
 *    the `x` or `y` coordinate of the center isn't an integer, store its 
 *    truncated value in the `point` structure.
 *
 * c) Move `r` by `x` units in the `x` direction and `y` units in the `y` 
 *    direction. (passed as arguments to the function)
 *
 * d) Determine whether a point `p` lies within `r`, returning `true` or 
 *    `false`. (`p` is an additional argument of type `struct point`)
 */

#include <stdio.h>
#include <stdbool.h>

#define RESET    "\x1b[0m"
#define B_YELLOW "\x1b[93m"

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point upper_left;
  struct point lower_right;
};


// Compute the area of `r`
int area_of_rectangle(struct rectangle r){
  int area = (r.lower_right.x - r.upper_left.x) * 
             (r.lower_right.y - r.upper_left.y);
  if (area < 0)
    return -area;
  else
    return area;
}


// Compute the center of rectangle `r` and return a `struct point`
// assumes origin is bottom-left
struct point center_of_rectangle(struct rectangle r){
  int dx, dy;

  dx = r.upper_left.x - r.lower_right.x;
  dy = r.upper_left.y - r.lower_right.y;

  return (struct point) {
    .x = r.lower_right.x + (dx/2),
    .y = r.lower_right.y + (dy/2)
  };
}


// Move `r` by `x` units in the x-direction and `y` units in the y-direction
struct rectangle translate_rectangle(struct rectangle r, int x, int y){
  r.lower_right.x += x;
  r.upper_left.x += x;
  r.lower_right.y += y;
  r.upper_left.y += y;
  return r;
}


// Determine whether a point `p` lies within `r`, returning `true` or 
// `false`. (`p` is an additional argument of type `struct point`)
bool is_point_in_rect(struct point p, struct rectangle r){
  if (r.upper_left.x  < p.x && p.x < r.lower_right.x &&
      r.lower_right.y < p.y && p.y < r.upper_left.y)
    return true;
  else
   return false;
} 


// -------------------------------------------------- 
//                       Helpers
// -------------------------------------------------- 

void print_section_header(char *part, char *func){
  printf("\nPart %s : " B_YELLOW "%s\n" RESET, part, func);
}

void print_rectangle(struct rectangle r){
  printf("(%d,%d),(%d,%d)\n", 
      r.upper_left.x, r.upper_left.y, 
      r.lower_right.x, r.lower_right.y);
}

void print_point(struct point p){
  printf("(%d,%d)\n", p.x, p.y);
}




// -------------------------------------------------- 
//                   program entry
// -------------------------------------------------- 

int main(void){
  struct rectangle r = {.lower_right.x = 10, .lower_right.y = 0,
                        .upper_left.x  =  0, .upper_left.y = 10};
  struct point p = {.x = 5, .y = 5};

  printf("p = "); print_point(p);
  printf("r = "); print_rectangle(r);


  // A) Compute the area of `r` ----------------------------------------------
  print_section_header("A", "area_of_rectangle()");
  printf("area_of_rectangle(r) = %d\n", area_of_rectangle(r));


  // B) Compute the center of `r`, -------------------------------------------
  print_section_header("B", "center_of_rectangle()");
  printf("center_of_rectangle(r) = ");
  print_point(center_of_rectangle(r));


  // C) move rectangle by x,y ------------------------------------------------
  print_section_header("C", "translate_rectangle()");
  printf("translate_rectangle(r, 5, -5) = ");
  print_rectangle(translate_rectangle(r, 5, -5));

    
  // D) is point inside rectangle? -------------------------------------------
  print_section_header("D", "is_point_in_rect()");
  printf("is_point_in_rect(p, r) : %s\n", 
      is_point_in_rect(p, r)?"TRUE": "FALSE");

  
  return 0;
}

