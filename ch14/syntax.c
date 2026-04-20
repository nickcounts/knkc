void print_std_macros();


/* Chapter 14, Secion 1
 
   The Preprocessor

 */

#define BEGIN {
#define END   }
#define LOOP for (;;)


int main(int argc, char *argv[])
BEGIN

print_std_macros();

return 0;
END



/* Chapter 14, Section 2
 *
 * Predefined Macros:
 *
 */

#include <stdio.h>
#define FUNC_CALLED printf("%s called\n", __func__);
#define FUNC_RETURNED printf("%s returned\n", __func__);

void print_std_macros(){
  FUNC_CALLED

  printf("%d\n", __LINE__); // int
  printf("%s\n", __FILE__);
  printf("%s\n", __DATE__);
  printf("%s\n", __TIME__);
  printf("%d\n", __STDC__); // int

  printf("STDC_HOSTED = %d\n", __STDC_HOSTED__);
  if (__STDC_HOSTED__){
    printf("C implementation is HOSTED\n");
  } else {
    printf("C implementation is STAND-ALONE\n");
  }

  printf("Supports standard C version %ld\n", __STDC_VERSION__);

  FUNC_RETURNED
}
