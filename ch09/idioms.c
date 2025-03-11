// Notes from the text of Chapter 09
//
// "Our programs so far have consisted of just the `main` function"
// -- oops!
//
// void function declarations:
void my_void_func(void) {
  // Does something
}

// C99 will often allow `void my_void_func()` but to be strict, include
// void when no parameters are defined

int main(int argc, char *argv[]) {
  // This is another example of function definition.
  // You can use the alternative main declaration that
  // takes `void`: `int main(void) { return 0;}`
  return 0;
}

// Variable declaration:
//
// C99 allows declarations anywhere, as long as they precede the first use
// c89 required all declaration at the top of a function.
//
