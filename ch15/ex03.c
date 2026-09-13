/* Chapter 15, Exercise 3
 *
 *
 * We saw that writing #include <file> instead of #include "file" may not work
 * if file is one that we've written. Woudl there be any problem with writing
 * #include "file" if file is a system header?
 *
 */

/*
 * Answer: No (caveat)
 *
 * The "" tells the compiler to look in the project's local directories first
 * but it will fall back to the system header folders if the header isn't 
 * found.
 *
 * This behavior may not be consistent across all platforms and compilers
 *
 * Issues could also arise if you have a header file name that collides
 * with the system header you intended to include
 * 
 */ 

#include "stdio.h"

int main(void) {
  return 0;
}
