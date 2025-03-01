CFLAGS=-Wall -g

SOURCES := $(wildcard proj*.c ex*.c numdigits*.c square*.c)
PRODUCTS := $(SOURCES:.c= *.o)
SYMBOLS := $(SOURCES:.c=.dSYM)

tutorial:
	@# todo: have this actually run some kind of tutorial
	@echo "Please read the 'Makefile' file to go through the tutorial"
	@echo "C files: $(SOURCES)"


clean:
	rm -f $(PRODUCTS) 
	@rm -r $(SYMBOLS) 2</dev/null 
