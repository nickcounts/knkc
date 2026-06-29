CFLAGS=-Wall -g

SOURCES := $(wildcard proj*.c ex*.c idioms.c syntax.c)
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

	

all: $(SOURCES:.c= )

