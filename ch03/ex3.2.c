#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int item_num;
  float item_price;
  int year, month, day;

  printf("Enter item number: ");
  scanf("%d", &item_num);

  printf("Enter unit price: ");
  scanf("%f", &item_price);

  printf("Enter purchase date (mm/dd/yyy): ");
  scanf("%d / %d / %d", &month, &day, &year);

  printf("%-10s    %-10s    %-10s\n", "Item", "Unit", "Purchase");
  printf("%-10s    %-10s    %-10s\n", " ", "Price", "Date");
  printf("%-10d    $%9.2f    %02d/%02d/%04d\n", item_num, item_price, month,
         day, year);

  return EXIT_SUCCESS;
}
