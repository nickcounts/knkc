/* Chapter 16, Project 6 (pg 412 (435))
 *
 * Modify Programming Project 8 from Chapter 5 so that the times are 
 * stored in a `date` structure (see Exercise 5). Incorporate the 
 * `compare_dates` function of Exercise 5 into your program.
 */

/* Chapter 5, Project 9
 *
 * Write a program that prompts the user to enter two dates and then indicate 
 * which date comes earlier on the calendar:
 *
 *  Enter first date (mm/dd/yy): 3/6/08
 *  Enter second data (mm/dd/yy): 5/17/07
 *  5/17/07 is earlier than 3/6/08
 */

#include <stdio.h>


int main(void){
  int y1,y2,m1,m2,d1,d2;
  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m1, &d1, &y1);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m2, &d2, &y2);

  if (y1<y2){
    printf("1 is earlier than 2\n");
    return 0;
  }

  else if (y2 < y1){
    printf("2 is earlier than 2\n");
    return 0;
  }

  if (m1<m2){
    printf("1 is earlier than 2\n");
    return 0;
  }
  else if (m2 < m1){
    printf("2 is earlier than 2\n");
    return 0;
  }

  if (d1<d2){
    printf("1 is earlier than 2\n");
    return 0;
  }
  else if (d2 < d1){
    printf("2 is earlier than 2\n");
    return 0;
  }

  printf("Both dates are the same\n");
  return 0;

}
