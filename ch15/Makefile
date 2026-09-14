CFLAGS=-Wall -g

SOURCES := $(wildcard proj*.c ex*.c idioms.c syntax.c remind justify qsort)
PRODUCTS := $(SOURCES:.c= *.o)
SYMBOLS := $(SOURCES:.c=.dSYM)


ifneq ($(filter french,$(MAKECMDGOALS)),)
	CFLAGS += -DFRENCH
else ifneq ($(filter spanish,$(MAKECMDGOALS)),)
	CFLAGS += -DSPANISH
else ifneq ($(filter english,$(MAKECMDGOALS)),)
	CFLAGS += -DENGLISH
endif

ifneq ($(filter debug,$(MAKECMDGOALS)),)
	CFLAGS += -DDEBUG
endif


.PHONY: debug french spanish english
debug french spanish english:
	@:


tutorial:
	@# todo: have this actually run some kind of tutorial
	@echo "Please read the 'Makefile' file to go through the tutorial"
	@echo "C files: $(SOURCES)"


clean:
	rm -f $(PRODUCTS) 
	@rm -r $(SYMBOLS) 2</dev/null 


macros:
	CFLAGS += -E
	all

ex%: ex%.c
	@echo "Building" $(notdir $(CURDIR)) $@
	$(CC) $(CFLAGS) $< -o $@

	
justify: justify.o word.o line.o
	@echo $(CC)
	$(CC) -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	$(CC) -c justify.c

word.o: word.c word.h
	$(CC) -c word.c

line.o: line.c line.h
	$(CC) -c line.c



qsort: qsort.o quicksort.o 
	$(CC) -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	$(CC) -c qsort.c

quicksort.o: quicksort.c quicksort.h
	$(CC) -c quicksort.c



remind: remind.o readline.o
	$(CC) -o remind remind.o readline.o 

remind.o: remind.c readline.h
	$(CC) -c remind.c

readline.o: readline.c readline.h
	$(CC) -c readline.c



rpn: proj05.o stack.o
	$(CC) -o rpn proj05.o stack.o 

proj05.o: proj05.c stack.h
	$(CC) -c proj05.c

stack.o: stack.h
	$(CC) -c stack.c


all: $(SOURCES:.c= )

