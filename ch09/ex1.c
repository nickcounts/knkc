// The following program outline shows only function definitions and variable
// declarations

int a;

void f(int b) { int c; }

void g(void) {
  int d;
  {
    int e;
  }
}

// exercise prototypes
// int check(x, y, n);

int main(void) { int f; }

// For each of the following scopes, list all variable and parameter names
// visible in that scope

// a) the `f` function:
//    f() can see a, b, and c
//
// b) the `g` function:
//    g() can see a and d.
//
// c) the block in which `e` is declared:
//    {int e;} can see a, d, and e
//
// d) the `main()` function:
//    main() can see a and f
//

// Ex. 1)
// The following function, which computes the area of a triangle, contains two
// errors. Locate the errors and show how to fix them.

// double triangle_area(double base, height)
double triangle_area(double base, int height)
// double product;
{
  double product;
  product = base * height;
  return product / 2;
  // The height parameter data type was missing. Moved the `product`
  // declaration into the {}.
}

// Ex. 2)
// Write a function `check(x, y, n)` that returns 1 if both x and y fall
// between 1 and n-1, inclusive. The function should return 0 otherwise.
// Assume that x, y, and n are all of type `int`
int check(int x, int y, int n) {
  if (x && y && x < n && y < 1)
    return 1;
  return 0;
}
