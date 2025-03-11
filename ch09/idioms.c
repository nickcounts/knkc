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

  // Even functions without arguments require empty parentheses when invoked
  my_void_func();
  return 0;
}

// Variable declaration:
//
// C99 allows declarations anywhere, as long as they precede the first use
// c89 required all declaration at the top of a function.

// Casting to void:
//
// casting something to void is effectively saying "throw this away"
// (void) printf("Hi, mom!\n")  ;
//
// explicitely discards the return value of printf (which is the number of
// characters printed). This is implied if no assignment is made.
