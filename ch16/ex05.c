/* Chapter 16, Exercise 5
 *
 * Write the followign functions, assuming that the `date` structure 
 * contains three members: `month`, `day`, and `year` (all type `int`)
 *
 * a) int day_of_year(struct date d);
 *    returns the day of the year (an integer between 1 and 366) that
 *    corresponds to the date `d`
 *
 * b) int compare_Dates(struct date d1, struct date d2); 
 *    Returns -1 if d1 is an earlier date than `d2`, +1 if `d1` is later
 *    that `d2` and 0 if they are the same
 */

#include <stdio.h>


struct date {
  int month;
  int day;
  int year;
};

// returns the day of the year (an integer between 1 and 366) that
// corresponds to the date `d`
 int day_of_year(struct date d) {
   int month_days[12] = {
     // J   F   M   A   May Jn  Jl  A   S   O   N   D
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
   };

   int days_elapsed = 0;
   for (int m = 0; m < d.month - 1; m++) {
     days_elapsed += month_days[m];
   }

   days_elapsed += d.day;

   if (d.month > 2) {
     if (d.year % 4 == 0)
       days_elapsed += 1;
   }
   
  return days_elapsed;
 }
 
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



int main(void) {
  struct date d1={3,1,1999}, d2={3,1,2000};

  printf("compare_dates(d1,d2) = %d\n", compare_dates(d1, d2));
  printf("day({3,1,1999}) = %d\n", day_of_year(d1));
  printf("day({3,1,2000}) = %d\n", day_of_year(d2));

  return 0;
}

