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
#include "../ncb/ncb.h"

#define MAX_REMIND 50
#define MSG_LEN 60
#define DEFAULT_HOUR 16
#define DEFAULT_MINUTE 30

typedef struct{
  int day;                    // day of year (for Part C)
  int time;                   // minute of day
  char message[MSG_LEN + 12]; // 'mm/dd [tttt] '
} mst_reminder;


int read_line(char str[], int n);
int get_time_from_message(char str[], int n);



int main(void) {
  mst_reminder reminders[MAX_REMIND];

  // char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, r_num, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    mst_reminder this_reminder = {0, 0, ""};

     /* Part B)
        Allow the user to enter a time. "Allow" implies not required?
        Look for string that matches a time as part of the reminder message
        Return "default time" if none is found
        Storing time as minute-of-the-day
      */
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day < 1)
      break;

    // Part A)
    // Ignore numbers greater than 31
    if (day > 31){
      printf("\n%2d is not a valid day of the month. Please try again\n", day);
      clear_input_buffer();
      continue;
    }

    this_reminder.day = day;

    sprintf(day_str, "%2d", day); // Build day_str from parsed day... factor out
    read_line(msg_str, MSG_LEN);
    strcpy(this_reminder.message, msg_str);

    this_reminder.time = get_time_from_message(msg_str, MSG_LEN);

    // Part B) inserting based on day/time
    // Insert this_remninder into the reminders array
    // Shuffle reminders down until r_ind is in the right spot
    for (r_num = num_remind; r_num >= 0; r_num--) {
      // Start at num_required
      if (r_num == 0) break;
      int this_reminder_time = this_reminder.day*24*60 + this_reminder.time;
      int last_reminder_time = reminders[r_num-1].day*24*60+reminders[r_num-1].time;
      if (last_reminder_time > this_reminder_time){
        // move last_reminder down one slot
        reminders[r_num] = reminders[r_num-1];
      } else {
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


// Reads user input up to `n` characters and stores it in `str`
int read_line(char str[], int n){
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
     if (i < n)
       str[i++] = ch;
  str[i] = '\0';
  return i;
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
    printf("Processing `%c`\n", *pt);
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
      printf("No valid time found\n");
      return time_of_day;
    }
  }
  printf("Found time substring\n");

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
 
  printf("Found %2d hour and %2d minute\n", time_of_day, minute_found);
  return time_of_day + minute_found;
}
