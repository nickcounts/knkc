/* Chapter 15, Exercise 2
 *
 *
 * Which of the following should not be put in a header file and why not? 
 *
 * a) Function Prototypes 
 * b) Function definitions
 * c) Macro definitions
 * d) Type definitions
 *
 */

/*
 * Answer: Function definitions
 *
 * The rationale is that the header is lightweight and the prototypes 
 * allow the functions to be called by any other section of code.
 *
 * Prototyping is useful even within a single file, to allow functions
 * use other functions without having to fuss over the definition order
 *
 *
 * Answer: Macro Definitions
 *
 * Macros are like functions but they operate at a somewhat higher level.
 * Including them in the header allows that functionality to be deployed
 * throughout the codebase.
 *
 *
 * Answer: Type Definitions 
 *
 * Type definitions are often linked to function parameters and return
 * arguments. Including them in header files allows these data types to 
 * be highly portable and to flow through the rest of the program.
 *
 * In some cases you may want to limit the scope of the data type definition
 * to within a particular compilation unit, but it is unclear how useful 
 * that is without language-level namespacing.
 *
 */


