/* Chapter 16, Exercise 1
 *
 * In the following declarations, the `x` and `y` structures have members named
 * `x` and `y`:
 *
 * struct { int x, y; } x;
 * sturct { int x, y; } y;
 *
 * Are these declarations legal on an individual basis? Could both declarations
 * appear as shown in a program? Justify your answer.
 */


// the x and y in the struct def are scoped within the structs, so these
// definitions should be legal and there will be no collision with the struct 
// names themselves.

struct { int x, y; } x;
struct { int x, y; } y;

int main(void) {

  return 0;
}
