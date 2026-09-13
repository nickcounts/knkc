/* Chapter 15, Exercise 5
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
 * All three source files include f1.h but only f1.c and f2.c include f2.h
 *
 * Write a makefile for this program, assuming that the compiler is gcc 
 * and that the executable file is to be named `demo`
 *
 *  
 */
  

// The makefile and an empty version of the example are in this repo to 
// validate the solution

demo: main.o f1.o f2.o 
	$(CC) -o demo main.o f1.o f2.o

main.o: main.c f1.h
	$(CC) -c main.c 

f1.o: f1.c f1.h f2.h
	$(CC) -c f1.c 

f2.o: f1.c f1.h f2.h
	$(CC) -c f2.c 



