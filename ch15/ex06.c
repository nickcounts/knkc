/* Chapter 15, Exercise 6
 *
 *
 * Suppose a program consists of three source files and two headers:
 *
 *  - main.c
 *  - f1.c
 *  - f2.c
 *  - f1.h
 *  - f2.h
 *
 * Using the example program described in ex05, answer the following:
 *
 * a) Which files need to be compiled when the program is built for the first
 *    time?
 *
 *    main.o, f1.o, and f2.o bust be compiled
 *
 * b) If f1.c is changed after the program has been built, which files need to
 *    be recompiled?
 *
 *    f1.o will be rebuilt, triggering a rebuild of demo, or at least a re-linking
 *
 * c) If f1.h is changed after the program has been built, which files need to
 *    be recompiled?
 *
 *    all objects will be rebuilt, as they all depend on f1.h, 
 *
 * d) If f2.h is changed after the program has been built, which files need to
 *    be recompiled?
 *
 *    f1.o and f2.o will be rebuilt and relinked to a new demo
 *
 */



