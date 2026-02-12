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
