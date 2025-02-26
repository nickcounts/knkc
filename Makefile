CFLAGS=-Wall -g

all: ex1 ex3

ex1:
	cc ex1.c -o ex1

#ex3:
#	cc ex3.c -o ex3



clean:
	rm -f ex1
	rm -f ex3
	
