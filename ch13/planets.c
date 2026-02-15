/* 
 Project 6
 Improve the `planet.c` program of Section 13.7 by having it ignore case when
 comparing command-line arguments with strings in the planets array
 */

#define DEBUG 0

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void is_string_a_planet_name(char *search_str){
  char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                     "Saturn", "Uranus", "Neptune", "Pluto"};
  const int NUM_PLANETS = 9;

  for (int p_num = 0; p_num < NUM_PLANETS; p_num++){
    char *p = planets[p_num];
    char *s = search_str;

    while (*p & *s){
      if (tolower(*p) != tolower(*s)){
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

int main(int argc, char *argv[]){
  if (argc == 1) return 1;

  is_string_a_planet_name(argv[1]);

  return 0;
}
