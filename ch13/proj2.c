/*
   Improve the remind.c program of Section 13.5 in the following ways:

   a) Have the program print an error message and ignore a reminder if the
      corresponding day is negative or larger than 31 (Hint: use the continue
      statement) 

   b) Allow the user to enter a day, a 24-hour time, and a reminder.
      The printed reminder list should be sorted first by day, then by time. 
      (The original program allows the user to enter a time, but it's treated 
      as part of the reminder) 

   c) Have the program print a one-year reminder list. Require the
      user to enter days in the form month/day
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../ncb/ncb.h"

#define MAX_REMIND 50
#define MSG_LEN 60
#define DEFAULT_HOUR 16
#define DEFAULT_MINUTE 30
#define DEBUG_PRINT 0

typedef struct{
  int month;                  // month num
  int day;                    // day of year (for Part C)
  int time;                   // minute of day
  char message[MSG_LEN + 12]; // 'mm/dd [tttt] '
} mst_reminder;

typedef struct{
  int month;
  int day;
  char reminder_str[MSG_LEN + 1];
  char original_str[MSG_LEN + 1];
} mst_user_input ;


/*
   ----------------------------------------------
   |            Function Prototypes             |
   ----------------------------------------------
 */

int get_time_from_message(char str[], int n);
bool is_string_valid_format(char *fmt_str, const char* str);
mst_user_input get_user_input(char * prompt_str);
// int int_from_str(const char *str);
void print_input(mst_user_input input);



int main(void) {
  mst_reminder reminders[MAX_REMIND];

  // char reminders[MAX_REMIND][MSG_LEN+3];
  int r_num, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    mst_reminder this_reminder = {0, 0, 0, ""};
    mst_user_input this_input = get_user_input("Enter day and reminder: ");

    if (DEBUG_PRINT) print_input(this_input);

    /* Part B)
       ----------------------------------------------------------------------
       Allow the user to enter a time. "Allow" implies not required?
       Look for string that matches a time as part of the reminder message
       Return "default time" if none is found
       Storing time as minute-of-the-day
       */
    
    if (this_input.month == -1){
      // User might be done!
      if (this_input.original_str[0] == '0'){
        break;
      } else {
        puts("Invalid entry. Please use mm/dd");
        continue;
      }
    }

    /* Part A)
       ----------------------------------------------------------------------
       Ignore numbers greater than 31
       */
    if ((this_input.month > 12) || this_input.day > 31){
      // Prompt for valid date
      puts("Please enter a valid date in the form mm/dd");
      continue;
    }

    this_reminder.day = this_input.day;
    this_reminder.month = this_input.month;
    strcpy(this_reminder.message, this_input.reminder_str); // messsage text from input w/o date

    // Strip trailing newline from message string
    int last_char = strlen(this_reminder.message);
    if (last_char > 1) last_char--;
    if (this_reminder.message[last_char] == '\n') this_reminder.message[last_char] = 0;

    this_reminder.time = get_time_from_message(this_reminder.message, MSG_LEN);

    /* Part B) 
       ----------------------------------------------------------------------
       inserting based on day/time
       Insert this_remninder into the reminders array
       Shuffle reminders down until r_ind is in the right spot

       Was using "minute of the month" in part B, but added a month/day field
       for part C. This version does not check valid month/day combos for short
       months
     */
    for (r_num = num_remind; r_num >= 0; r_num--) {
      // Start at num_required
      if (r_num == 0) break;

      mst_reminder last_reminder = reminders[r_num-1];

      if (last_reminder.month > this_reminder.month){
        // move last reminder down one slot
        reminders[r_num] = reminders[r_num-1];

      } else if (last_reminder.day > this_reminder.day) {
        // move last_reminder down one slot
        reminders[r_num] = reminders[r_num-1];
      
      } else if (last_reminder.time > this_reminder.time){
        // move last_reminder down one slot
        reminders[r_num] = reminders[r_num-1];
      } else {
        // this is a good spot!
        break;
      }
    }

    reminders[r_num] = this_reminder;
    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (r_num = 0; r_num < num_remind; r_num++){
    printf( "%2d %s\n", reminders[r_num].day, reminders[r_num].message);
  }
}






int get_time_from_message(char str[], int n){
  int time_of_day = ((DEFAULT_HOUR * 60) + DEFAULT_MINUTE);
  int minute_found = 0;
  int time_chars = 0;
  char found_time[MSG_LEN];
  char hr[3], min[3];
  char *pt = str;
  char *pf = found_time;

  while (*pt){
    if (DEBUG_PRINT) printf("Processing `%c`\n", *pt);
    // Loop through initial input if it is numerical (ignore whitespace?)
    if (*pt <= '9' && *pt >= '0'){
      *pf++ = *pt++;
      time_chars++;
      if (time_chars >= 4) {
        break;
      }
      continue;
    } else if (*pt == ' ') {
      // advance if first character was whitespac
      pt++;
      continue;
    } else {
      // No valid time string was found (non numeric and non whitespace)
      if (DEBUG_PRINT) printf("No valid time found\n");
      return time_of_day;
    }
  }
  if (DEBUG_PRINT) printf("Found time substring\n");

  // Compute time_of_day from found_time;
  // Do my own ascii to int conversions
  if (strlen(found_time) > 1){
    hr[0] = found_time[0];
    hr[1] = found_time[1];
    time_of_day = (hr[0]-'0')*10 + hr[1]-'0'; 
  }

  if (strlen(found_time) > 3){
    min[0] = found_time[2];
    min[1] = found_time[3];
    minute_found = (min[0]-'0')*10 + min[1]-'0';
  }
 
  if (DEBUG_PRINT) printf("Found %2d hour and %2d minute\n", time_of_day, minute_found);
  return time_of_day + minute_found;
}




// fmt_str: d is digit, c is char, supports '/' character
bool is_string_valid_format(char *fmt_str, const char* str){
  int len_fmt = strlen(fmt_str);
  const char* ps = str;
  char* pf = fmt_str;
  while (pf - fmt_str < len_fmt){
    switch (*pf) {
      case 'd':
        if (!(*ps <= '9' && *ps >= '0'))
          return false;
        break;

      case 'c':
        if (!((*ps <= 'z' && *ps >= 'a') || (*ps <= 'z' && *ps >= 'a')))
          return false;
        break;

      case '/':
        if (*ps != '/')
          return false;
        break;
    
    }
    pf++;
    ps++;
  }

  return true;
}


// returns .day = -1 and .month = -1 if invalid user input
mst_user_input get_user_input(char * prompt_str){
  char *p_msg_start;
  mst_user_input response;

  char msg_str[MSG_LEN + 8];
  char day_str[3], month_str[3];

  printf("%s", prompt_str);
  fgets(msg_str, MSG_LEN, stdin);
  if (!is_string_valid_format("dd/dd", msg_str)){
    response.day = -1;
    response.month = -1;
    strcpy(response.original_str, msg_str);
    response.reminder_str[0] = '\0';
    return response;
  }

  // Set msg_start pointer to first character after 'mm/dd '
  p_msg_start = &msg_str[5];

  day_str[0] = msg_str[3]; 
  day_str[1] = msg_str[4]; 
  day_str[2] = 0; 

  response.day = int_from_str(day_str);

  month_str[0] = msg_str[0];
  month_str[1] = msg_str[1];
  month_str[2] = 0;

  response.month = int_from_str(month_str);

  strcpy(response.original_str, msg_str);
  strcpy(response.reminder_str, p_msg_start);

  return response;
}

// Requires a c-string, null-terminated.
// Only supports positive integers
/*
   int int_from_str(const char *str){
   int end = strlen(str);
   int this_int = 0;
   int place_coefficient = 1;

   if (end < 1)
   return this_int;

   end--; // Start on last character, not null-terminator

   for (int i = end; i>=0; i--){
// printf("%d's place = %c\n", place_coefficient, str[i]);
this_int += (str[i] - '0')*place_coefficient;
place_coefficient *= 10;
}
return this_int;
}
 */

void print_input(mst_user_input input){
  printf("    day: %d\n", input.day);
  printf("  month: %d\n", input.month);
  printf("    raw: %s\n", input.original_str);
  printf("rem str: %s\n", input.reminder_str);
}



