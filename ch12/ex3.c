#include <stdio.h>
#include <stdlib.h>

#define N 10

#define MULTILINE \
  "This loop reverses the order of an array. The pointers p and q begin pointing " \
  "to the first and last elements of the array, respectively. The value of the first " \
  "element is saved to the temp variable. Then the value of the last element is " \
  "assigned to the first element (through *p++) and then the pointer switces to the " \
  "second element after the assignment.\n" \
  "The temp value is assigned to the last element (throught *q--) and then the pointer " \
  "switches to the penultimate element. This repeats until the pointers reach the " \
  "middle of the array" 


void pretty_print(char* text, int width) {
  char *start = text;
  char *search = start;
  char *last = start;
  int this_line_width;
  while (*search != '\0') {
    this_line_width++;

    if (this_line_width >= width) {
      // We're too long, drop to last space and print
      for (char* c = start; c <= last; c++) {
        printf("%s", c);
      }
      printf("\n");
      // Fix the pointers before continuing
      last++;
      start = last;
      search = start;
      continue;
    }

    if (*search == "\n"){
      // Newline resets line width
      this_line_width = 0;
    }


    
  
  }

}


int main() {
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p = &a[0], *q = &a[N-1], temp;

  while (p<q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
  }

  printf("This loop reverses the order of an array. The pointers p and q begin pointing\n");
  printf("to the first and last elements of the array, respectively. The value of the first\n");
  printf("element is saved to the temp variable. Then the value of the last element is\n");
  printf("assigned to the first element (through *p++) and then the pointer switces to the \n");
  printf("second element after the assignment. \n");
  printf("The temp value is assigned to the last element (throught *q--) and then the pointer\n");
  printf("switches to the penultimate element. This repeats until the pointers reach the \n");
  printf("middle of the array\n\n");
  printf("{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}  temp = 1\n");
  printf("*p                          *q\n\n");

  printf("{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}  temp = 1\n");
  
  printf("{");
  for (int i =0; i<N; i++) {
    printf("%d", a[i]);
    (i < N-1) ? printf(", ") : printf("}\n");
  }

  return EXIT_SUCCESS;
}
