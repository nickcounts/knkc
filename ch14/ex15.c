/* Chapter 14, Exercise 15

   Suppose that a program needs to display messages in either English, French, or
   Spanish. using conditional compilation, write a program fragment that displays
   one of the following three messages, depending on whether or not the specified
   macro is defined:

      Insert Disk 1         (if ENGLISH is defined)
      Inserez Le Disque 1   (if FRENCH is defined)
      Inserte El Disco 1    (if SPANISH is defined)

   Updated Makefile with .phony targets for english, spanish, and french to set 
   the CFLAGS to add a -D flag for conditional compilation.

   Also tested an enable/disabled DBG() macro that seems to work. Also added to
   Makefile. Invocation as follows:

   ```zsh
       > make debug french ex15
       Building ch14 ex15
       cc -Wall -g -DFRENCH -DDEBUG ex15.c -o ex15
   ```
 */

#include <stdio.h>

#ifdef DEBUG
#define DEBUG_PRINT(s) printf(s)
#else
#define DEBUG_PRINT(s) do {} while (0)
#endif

#define DBG(s) DEBUG_PRINT(s)

#if defined(FRENCH)
#define INSERT_MSG "Inserez Le Disque 1"
#elif defined(SPANISH)
#define INSERT_MSG "Inserte El Disco 1"
#else
#define INSERT_MSG "Insert Disk 1"
#endif

int main(void){

  DBG("This only appears if DEBUG is defined\n");

  printf("%s...\n", INSERT_MSG);

  return 0;
}
