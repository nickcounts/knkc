/***********************************************
 *   Program Structures for C Preprocessor
 * *********************************************/

// One possible ordering is:
//    #include directives
//    #define directives
//    Type definitions
//    Declarations of external/global variables
//    Prototypes for functions other than main()
//    Definitions of other functions
//
// Includes make sense at the top, since they will likely be
// used throughout the code. It also makes it easy to see what
// dependencies the code has
//
// Define directives create macros, which are generally used
// throughout the program
//
// Declaring external (globals) allows them to be available to
// all the functions
//
// Declaring all functions before main() allows the functions to
// be implemented in any order.
//
// Implementing main() first makes it easier for a reader to
// find the entry point.
//      - Not sure about this one, with vim you can always just G
//        jump to the bottom. If you're viewing from command line
//        you can tail or cat for the same effect.
//
// Author suggests preceding function definitions by a boxed
// comment that gives the name of the function, explains purposem
// discusses meaning of each parameter, describes the return value,
// lists any side effects (like modifying any global state!)

// TODO: Look at box comment tools

// FIX: Nothing
