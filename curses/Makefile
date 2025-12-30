CFLAGS=-Wall -g -lncurses

SOURCES := $(wildcard proj*.c tut*.c hello.c orly.c)
PRODUCTS := $(SOURCES:.c= *.o)
SYMBOLS := $(SOURCES:.c=.dSYM)

hello:
	gcc -lncurses hello.c -o hello

orly:
	gcc -lncurses orly.c -o orly

tutorial:
	@# todo: have this actually run some kind of tutorial
	@echo "Please read the 'Makefile' file to go through the tutorial"
	@echo "C files: $(SOURCES)"


clean:
	rm -f $(PRODUCTS) 
	@rm -r $(SYMBOLS) 2</dev/null 

all: $(SOURCES:.c= )

