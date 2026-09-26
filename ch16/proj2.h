/* Chapter 16, Project 2
 *
 * Modify the `inventory.c` program of Section 16.3 so that the `p`
 * print operation displays the parts sorted by part number
 *
 */

#include "inventory_struct.h"

void quicksort_inventory(struct part a[], int first_ind, int last_ind);
int split(struct part a[], int low, int high);


