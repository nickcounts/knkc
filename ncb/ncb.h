#ifndef	_STDIO_H_
#include <stdio.h>
#endif // <stdio.h>

/* This function clears the console input buffer by reading up to a newline
 * or EOF and chucking the results.
 * fflush(stdin) does not work on MacOS (and others) as it is undefined.
 */
void clear_input_buffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}


/* This function takes a c-string (null-terminated) and parses it to an 
 * integer. There is NO input error checking and only positive integers
 * are supported
 * Returns -1 if an error happens
 */
int int_from_str(const char *str){
  int end_ind = 0; //= strlen(str);
  int this_int = 0;
  int place_coefficient = 1;

  while (str[end_ind] != 0){
    end_ind++ ;
  };

  if (end_ind < 1)
    return -1;

  end_ind--; // Start on last character, not null-terminator

  for (int i = end_ind; i>=0; i--){
    this_int += (str[i] - '0')*place_coefficient;
    place_coefficient *= 10;
  }
  return this_int;
}
