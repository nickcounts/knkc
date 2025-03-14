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
//
