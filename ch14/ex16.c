/* Chapter 14, Exercise 16

   (C99) Assume that the following macro definitions are in effect:

      #define IDENT(x) PRAGMA(ident #x)
      #define PRAGMA(x) _Pragma(#x)

   What will the following line look like after macro expansion?

      IDENT(foo)


   Verify with:
     `clang -E ./ex16.c`
 */

// IDENT(foo) -> PRAGMA(ident #foo) -> PRAGMA(ident "foo")
// PRAGMA(ident "foo") -> _Pragma(#ident "foo")
// _Pragma(#ident "foo") -> destringizes, but we stringized the string first?
// _Pragma(#ident "foo") -> _Pragma("ident \"foo\"") -> #pragma ident "foo"


#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)
IDENT(foo)


int main(void) {
  return 0;
}

