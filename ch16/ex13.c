/* Chapter 16, Exercise 13
 *
 * Suppose that s is a `struct shape` as defined below. If the value of
 * `shape_kind` is  RECTANGLE, the `height` and `width` members store 
 * the dimensions of a rectangle. If the value of `shape_kind` is `CIRCLE`
 * the `radius` member stores the radius of a circle.
 *
 * Indicate which of the following statements are legal, and show how to
 * repair the ones that aren't:
 *
 * a) s.shape_kind = RECTANGLE;
 * b) s.center.x = 10;
 * c) s.height = 25;
 * d) s.u.rectangle.width = 8;
 * e) s.u.circle = 5
 * f) s.u.radius = 5
 */


struct point {
  int x, y;
};

struct shape {
  int shape_kind;           /* RECTANGLE or CIRCLE */
  struct point center;      /* coordinates of cente r*/
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
} s;


int main(void){

// a) s.shape_kind = RECTANGLE;

// b) s.center.x = 10;
  s.center.x = 10; // This one is good. They all have point `center`

// c) s.height = 25;
  // This one is BAD - height is a member of the rectangle struct, so it 
  // must be accessed through the proper hierarchy:
  s.u.rectangle.height = 25;

// d) s.u.rectangle.width = 8;
  s.u.rectangle.width = 8; // This one is good

// e) s.u.circle = 5
  // This one is BAD - need to access the `radius` member of the `circle`
  // struct.
  // Neither E nor F would be a good idea if `shape_kind` is `RECTANGLE`
  s.u.circle.radius = 5;

// f) s.u.radius = 5
  // This one is BAD - need to access `radius` through the `circle` struct.
  // Neither E nor F would be a good idea if `shape_kind` is `RECTANGLE`
  s.u.circle.radius = 5;

  return 0;
}




