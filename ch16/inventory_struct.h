/* Chapter 16, Project 2
 *
 * Moving the inventory structure definition to a header to be shared with the
 * sorting algorithms
 */

#ifndef H_INVENTORY_STRUCT
#define H_INVENTORY_STRUCT

#define NAME_LEN 31

// Structure Tag:
struct part {
  int     number;
  char    name[NAME_LEN + 1];
  int     on_hand;
};

#endif


