/* Chapter 16, Project 1
 *
 * Write a program that asks the user to enter an international dialing code
 * and then looks it up in the `country_codes` array (see Section 16.3).
 *
 * If it finds the code, the program should display the name of the
 * corresponding country; if not, the program should print an error message
 */

#include <stdio.h>
#include <stdlib.h>



// 16.3 - Nested Arrays and Structures

struct dialing_code {
  char *country;
  int code;
};

const struct dialing_code country_codes[] = {
  {"Argentina", 54},
  {"Bangladesh", 880},
  {"Brazil", 55},
  {"Burma", 95},
  {"China", 86},
  {"Columbia", 57},
  {"Congo", 243},
  {"Egypt", 20},
  {"Ethiopia", 251},
  {"France", 33},
  {"Germany", 49},
  {"India", 91},
  {"Italy", 39},
  {"Japan", 81},
  {"Poland", 48},
  {"Russia", 7},
  {"Ukraine", 380},
  {"United Kingdom", 44},
  {"United States", 1},
  {"Vietnam", 84}
};


// Search by the numerical country code and return the corresponding 
// dialing_code structure. If not found, returns a default struct 
// with an error message and code value of -1
struct dialing_code find_by_code(int c){
  int numel = sizeof(country_codes)/sizeof(country_codes[0]);
  for (int i = 0; i<numel; i++){
    if (country_codes[i].code == c)
      return country_codes[i];
  }

  return (struct dialing_code) {"Not found", -1};
}


// Print a dialing_code struct
void print_dialing_code(struct dialing_code s){
  printf("Country: %s\n", s.country);
  if (s.code<0)
    return;
  printf("   Code: %d\n", s.code);
}

// Get user input from terminal. Return `error_value` if input breaks
int get_int(int error_value){
  char buff[10];
  int val;
  fgets(buff, 10, stdin);
  val = atoi(buff);
  if (val)
    return val;

  return error_value;
}


int main(void){
  int dc;
  printf("Enter a dialing code to search : ");
  dc = get_int(-99);
  print_dialing_code(find_by_code(dc));
  return 0;
}





