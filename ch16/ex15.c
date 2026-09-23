/* Chapter 16, Exercise 15
 *
 * a) Declare a tag for an enumeration whose values represent the seven days of
 *    the week. 
 *
 * b) Use `typedef` to define a name for the enumeration of part (a)
 */

#include <stdio.h>

enum days_of_week {
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY,
};

// Can use typedef enum tagname typename without the {} to alias the tag
typedef enum days_of_week DaysOfWeek;


// typedef enum {
//   Mon,
//   Tue,
//   Wed,
//   Thu,
//   Fri,
//   Sat,
//   Sun,
// } DaysOfWeek;


int are_the_same(enum days_of_week e1, DaysOfWeek e2){
  return e1 == e2 ? 1 : 0;
}


int main(void){

  printf("`are_the_same()` expects both the tagged enum and the typedef\n"
         "enum. If `MONDAY` == `MONDAY` then both enums are functioning\n"
         "and the typedef alias works as intended.\n\n");
  printf("Do these function? MONDAY == MONDAY? ");
  printf("%s\n", are_the_same(MONDAY, MONDAY) ? "YES" : "NO" );

  return 0;
}
