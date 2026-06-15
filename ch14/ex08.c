/* Chapter 14, Exercise 8

   Suppose we want a macro that expands into a string containing the current
   line number and file name. In other words, we'd like to write:

     const char *str = LINE_FILE;

   and have it expand into:

     const char* = "Line 10 of file foo.c";

   where `foo.c` is the file containing the program and `10` is the line on
   which the invocation of `LINE_FILE` appears.

   WARNING: This exercise is for experts only. Be sure to read the Q&A section
   carefully before attempting!
 */

#define STRINGIFY(s) #s
#define TO_STRING(s) STRINGIFY(s)
#define LINE_FILE TO_STRING(Line __LINE__ of file __FILE__)

#include <stdio.h>

int main(int argc, char **argv){
  const char *str = LINE_FILE;

  printf("Invoked on line 26: %s\n\n", str);

  printf("We can't just create a single macro because we need to allow the "
         "macro expansion to occur on the special LINE and FILE keywords while "
         "also returning a \"stringified\" copy.\n\n");

  printf("By wrapping the `Line __LINE__ of file __FILE__` in a second macro, "
         "we allow the expansion of __LINE__ and __FILE__ to be passed to "
         "another pre-processor. But we can't just have the second macro "
         "stringify or it will not complete the expansion, so the wrapping macro "
         "itself must call a 'stringify' macro that uses the `(s) #s` directive "
         "to convert the expanded string into a double-quote wrapped string.\n\n");

  printf("So, the final form is:\n\n");

  printf("#define STRINGIFY(s) #s\n");
  printf("#define TO_STRING(s) STRINGIFY(s)\n");
  printf("#define LINE_FILE TO_STRING(Line __LINE__ of file __FILE__)\n");

      return 0;
}

