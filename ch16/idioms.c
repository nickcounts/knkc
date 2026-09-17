
#include <stdio.h>

#define NAME_LEN 31

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

void print_Part(Part s){
  printf("Part number      : %d\n", s.number);
  printf("Part name        : %s\n", s.name);
  printf("Quantity on hand : %d\n", s.on_hand);
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

  return 0;
}
