/* Chapter 15, Exercise 1
 *
 *
 * Section 15.1 listed several advantages of dividint a program into multiple
 * source files. 
 *
 * a) Describe several other advantages. 
 * b) Describe some disadvantages
 *
 */

/* A) advantages
 *
 * They say that build times are faster. There is no `namespacing` in C, so 
 * multiple files don't actually provide that kind of segmentation. Multiple 
 * files can give you some code organization if you name and group things 
 * carefully
 *
 */

/* B) disadvantages
 *
 *  This one is easier for me. Breaking the program up into many files adds a
 * level of conceptual complexity to the program. You have more interactions to
 * think about, debugging and finding the code you need is harder on its own.
 *
 *  The build process is also more complex, and you need to pay attention to the
 * makefiles or other build tooling
 */
