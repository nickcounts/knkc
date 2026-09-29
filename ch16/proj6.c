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

// From Ch16, Ex 5
struct date {
  int month;
  int day;
  int year;
};

 
 // Returns -1 if d1 is an earlier date than `d2`, +1 if `d1` is later
 // that `d2` and 0 if they are the same
 int compare_dates(struct date d1, struct date d2) {

   // Handle obvious year differences
   if (d1.year > d2.year)
     return 1;
   else if (d1.year < d2.year)
     return -1;

   // Handle obvious month differences
   if (d1.month > d2.month)
     return 1;
   else if (d1.month < d2.month)
     return -1;

   // Handle obvious day differences
   if (d1.day > d2.day)
     return 1;
   else if (d1.day < d2.day)
     return -1;

   return 0;
 }


void print_cmp(struct date early, struct date later){
  printf("%d/%d/%d is earlier than %d/%d/%d.\n",
      early.month, early.day, early.year,
      later.month, later.day, later.year);
}



int main(void){
  // int y1,y2,m1,m2,d1,d2;
  struct date d1, d2;
  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  int cmp = compare_dates(d1, d2);
  if (cmp < 0){
    print_cmp(d1, d2);
  } else if ( cmp > 0){
    print_cmp(d2, d1);
  }else {
    printf("Both dates are the same\n");
  }

  return 0;

}
