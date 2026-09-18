
#include <stdio.h>
#include <string.h>

#define NAME_LEN 31
#define LAST_NAME_LEN 31
#define FIRST_NAME_LEN 31

// structs can be instantiated by simply placing the values in the order in
// which they were defined.

struct {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} part1 = {528, "Disk drive", 10}, 
  part2 = {914, "some string", 50}; 

// Designated Initializers:

struct {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} part3 = {.number=528, "Disk drive", .on_hand=10}, 
  part4 = {.number=914, .name="some string", .on_hand=50}; 

// Operations on Structures
// 
// part4.number = part3.number + 1; // valid. 
//
// Can even do with arrays, unlike stand-alone arrays!  


// 16.2 Structure Types
//
// Create a structure tag or mix with typedef to create a reusable struct type

// Structure Tag:
struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
}; // <-- need this semicolon! 

// These are distinct from typedefs in that they MUST be used WITH the `struct` keyword 

struct part mypart1; // `part` is the tag, `mypart1` is the variable/struct name
struct part mypart2 = {123, "some text", 10};

void print_part(struct part s){
  printf("Part number      : %d\n", s.number);
  printf("Part name        : %s\n", s.name);
  printf("Quantity on hand : %d\n", s.on_hand);
}

// Defining a Structure Type:
// use typedef struct { struct def } typeDefName;


typedef struct {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} Part;  

Part myPart;


struct person_name {
  char first[FIRST_NAME_LEN+1];
  char middle_initial;
  char last[LAST_NAME_LEN+1];
};


// 16.3 - Nested Arrays and Structures

// Use `person_name` as the first element in `student`
struct student {
  struct person_name name;
  int id, age;
  char sex;
} student1, student2;


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



// --------------------------------------------
// Function Definitions
// --------------------------------------------

void print_Part(Part s){
  printf("Part number      : %d\n", s.number);
  printf("Part name        : %s\n", s.name);
  printf("Quantity on hand : %d\n", s.on_hand);
}

struct part build_part(int number, const char* name, int on_hand){
  struct part p;
  p.number = number;
  strcpy(p.name, name);
  p.on_hand = on_hand;
  return p;
}








int main(void) {
  printf("Part number      : %d\n", part1.number);
  printf("Part name        : %s\n", part1.name);
  printf("Quantity on hand : %d\n", part1.on_hand);

  printf("\n\n");

  mypart1 = mypart2; // This works since they are the same struct/tag
  print_part(mypart1);

  printf("\n\n");

  print_Part(myPart);

  struct part mypart3 = build_part(101, "My Part 3", 10);
  print_part(mypart3);
  printf("\n");

  // Examples of compound literals being used to "instantiate" a struct as 
  // an argument to a function
  printf("Using compound literal notation with struct definitions and\n");
  printf("function calls: -----------------------------------------------\n\n");
  print_part((struct part) {10, "compound literal", 20});

  printf("\n");
  print_part((struct part) {.number=11, 
                            .name="compound lit w/ designators", 
                            .on_hand=20});

  printf("\n");

  // Examples of nested structs and arrays
  printf("\nUsing nested structs and arrays:\n");
  printf("---------------------------------------------------------------\n\n");
  strcpy(student1.name.first, "Fred");
  printf("student1.name.first: %s\n", student1.name.first);

  // an Array of Structs:
  struct part inventory[100];

  strcpy(inventory[0].name, part3.name);
  inventory[0].number = part3.number;
  inventory[0].on_hand = part3.on_hand;

  print_part(inventory[0]);


  return 0;
}
