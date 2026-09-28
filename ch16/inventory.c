#include <stdio.h>
#include <string.h>
#include "readline.h"
#include "inventory_struct.h"
#include "proj2.h"


#define MARS_RED "\x1b[38;5;214m"
#define YELLOW   "\x1b[33m"
#define CYAN     "\x1b[36m"
#define GREEN    "\x1b[92m"
#define RESET    "\x1b[0m"

#define NAME_LEN  31
#define MAX_PARTS 100




// --------------------------------------------
// Function Prototypes
// --------------------------------------------

int find_part(struct part inventory[], int num_parts, int number);
void print_help(void);
int insert(struct part inventory[], int num_parts); /* Inserts a new part into inventory */
void search(struct part inventory[], int num_parts); 

void update(struct part inventory[], int num_parts);
void print( struct part inventory[], int num_parts);
void print_ordered(struct part inventory[], int num_parts); // Project 2 - print ordered by PN

// ----------------------------------------------------------------------------
// main:  Prompts the user to enter an operation code, then calls a function to
//        perform the requested action. Repeats until the user enters the
//        command `q`. Prints an error message if the user enters an illegal
//        code.
// ----------------------------------------------------------------------------
int main(void) {
  // Project 3: Make inventory and num_parts local to `main()`
  struct part inventory[MAX_PARTS];
  int num_parts = 0; // number of parts currently stored

  char code;

  // Main Loop
  for (;;){
    // Prompt user 
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;

    // Read input
    switch (code) {
      case 'i' : // insert
        num_parts = insert(inventory, num_parts);
        break;       

      case 's' : // search
        search(inventory, num_parts);
        break;       

      case 'u' : // update
        update(inventory, num_parts);
        break;       

      case 'p' : // print
        print(inventory, num_parts);
        break;       

      case 'l' : // list in part number order (Proj 2)
        print_ordered(inventory, num_parts);
        break;

      case 'q' : // quit
        printf("Thank you for shopping at " MARS_RED "MARS" RESET "\n");
        return 0;
        
      default:   // print error/help 
        printf("Illegal code\n");
        print_help();
    }
    printf("\n");
  }

  return 0;
}



// Looks up a part number in the inventory array and returns the array index for
// the matchine part. If not found, returns -1
int find_part(struct part inventory[], int num_parts, int number){
  int i;
  for (i = 0; i < num_parts; i++){
    if (inventory[i].number == number)
      return i;
  }
  return -1;
}



// Prompts the user for information about a new part and then inserts the part
// into the database. Pritns an error message and returns prematurely if the
// part already exists or the database is full.
int insert(struct part inventory[], int num_parts){
  int part_number;
  int name_chars = 0;

  if (num_parts >= MAX_PARTS) {
    printf("Database is full. Can't add any more parts.\n");
    return num_parts;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(inventory, num_parts, part_number) >= 0){
    printf("Part already exists.\n");
    return num_parts;
  }

  inventory[num_parts].number = part_number;

  printf("Enter the part name: ");
  name_chars = read_line(inventory[num_parts].name, NAME_LEN) ;

  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);

  printf("Enter unit price (in cents): ");
  scanf("%d", &inventory[num_parts].unit_price);

  return ++num_parts;
}



// Prompts the user to enter a part number then looks up the part in the
// database. If the part exists, prints the name and quantity on hand. If not,
// prints an error message
void search(struct part inventory[], int num_parts){
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(inventory, num_parts, number);

  if (i < 0) {
    printf("Part not found.\n");
    return;
  }

  printf("Part name   : " CYAN " %s\n" RESET,   inventory[i].name);
  printf("Qty on hand : %d\n", inventory[i].on_hand);

}



// Prompts the user to enter a part number. Prints an error message if the part
// doesn't exist; otherwise primpts the user to enter the change in quantity on
// hand and updates the database
void update(struct part inventory[], int num_parts){
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(inventory, num_parts, number);
  if (i < 0) {
    printf("Part not found.\n");
    return;
  }

  printf("Adjust quantity on hand by: ");
  scanf("%d", &change);
  inventory[i].on_hand += change;

}



// prints a listing of all parts in the database, showing the part number, part
// name, and quantity on hand. Parts are pritned in the order in which they were
// entered into the database
void print(struct part inventory[], int num_parts){
  int i, dollars, cents;

  printf("%11s " "%-32s " "%-6s " "%-s\n",
      "Part Number", "Part Name", "Qty", "Price");

  for (i = 0; i < num_parts; i++) {
    cents = inventory[i].unit_price % 100;
    dollars = inventory[i].unit_price / 100;
    printf(YELLOW "%11d " 
           CYAN "%-32s " 
           RESET "%-6d "
           GREEN "$%4d.%02d" RESET"\n",   
           inventory[i].number, 
           inventory[i].name, 
           inventory[i].on_hand,
           dollars, cents
          );
    }
}



// This function sorts the master array! There are SIDE EFFECTS
void print_ordered(struct part inventory[], int num_parts){
  quicksort_inventory(inventory, 0, num_parts-1);
  print(inventory, num_parts);
}



// Prints a listing of operation codes and instructions
void print_help(void){
  printf("The following commands are supported:\n");
  printf(YELLOW "i" CYAN "nsert" RESET " : add a new part to the database\n");
  printf(YELLOW "s" CYAN "earch" RESET " : search by part number\n");
  printf(YELLOW "u" CYAN "pdate" RESET " : update quantity of a part\n");
  printf(YELLOW "p" CYAN "rint " RESET " : print inventory\n");
  printf(YELLOW "l" CYAN "ist "  RESET " : print inventory in part number order\n");
  printf(YELLOW "q" CYAN "uit  " RESET " : exit the program\n");
}



