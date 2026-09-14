#include <stdbool.h>

#define STACK_SIZE 100

// Page 375 (398)

// External variables
int contents[STACK_SIZE];
int top;

void stack_overflow();
void stack_underflow();
void push(int i);
int pop(void);

void make_empty(void);
bool is_empty(void);
bool is_full(void);

