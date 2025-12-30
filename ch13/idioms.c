// C-strings have several common idioms for typical tasks.
#include <stdio.h>
#define DEBUG 0
void is_string_a_planet_name(char *search_str);

// +-------------------------------------------------------------------------+
// |                       Chapter 13 - Section 6                            |
// +-------------------------------------------------------------------------+

// Finding the end of a string (null-terminated) using a while-loop

// This idiom leaves the pointer at the null terminator
void leave_pointer_at_null_terminator(char *s){
  while (*s)
    s++;
}

// This idiom leaves the pointer at the address *after* the null terminator
void leave_pointer_after_null_terminator(char *s){
  while (*s++)
    ;
}

// This idiom copies a char from one array to another until null term
void copy_chars_until_null_terminator(char *s1, char *s2){
  char *p = s1; // Create pointer to first string
  
  while (*p)    // Move pointer to null terminator
    p++;

  while ((*p++ = *s2++)) // Copy s2 chars until (include) null terminator
    ;

}


// +-------------------------------------------------------------------------+
// |                       Chapter 13 - Section 7                            |
// +-------------------------------------------------------------------------+

// Command-Line Arguments
//
// Arguments are passed in as an array of pointers to c-strings.


int main(int argc, char *argv[]){
  printf("argc = %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
    is_string_a_planet_name(argv[i]);
  }
  return 0;
} 



void is_string_a_planet_name(char *search_str){
  char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                     "Saturn", "Uranus", "Neptune", "Pluto"};
  const int NUM_PLANETS = 9;

  for (int p_num = 0; p_num < NUM_PLANETS; p_num++){
    char *p = planets[p_num];
    char *s = search_str;

    while (*p & *s){
      if (*p != *s){
        // Not a match to this planet
        break;
      }
      if (DEBUG) printf("Checking %c == %c\n", *p, *s);
      p++;
      s++;
    }

    if (*s == '\0'){
      // Reached the end of the input string, all matched
      printf("%s is a planet!\n", planets[p_num]);
      return;
    }

  }
  printf("%s is NOT a planet\n", search_str);
  return;
}


