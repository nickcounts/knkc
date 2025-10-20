#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Suppose that the following declarations are in effect:\n");
  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
  int *p = &a[1], *q = &a[5];
  printf("\tint a[] = {5, 15, 34, 54, 14, 2, 52, 72};\n");
  printf("\tint *p = &a[1], *q = &a[5];\n");

  // Question A)
  printf("\na) What is the value of *(p+3):\n");
  printf("\t*(p+3) points to the 5th element of a[], which is 14\n");
  printf("\t14 == %d\n", *(p + 3));

  // Question B)
  printf("Whatis the value of *(q-3):\n");
  printf("\t*(q-3) points to the 3rd element of a[], which is 34\n");
  printf("\t34 == %d\n", *(q - 3));

  // Question C)
  printf("What is the value of q-p:\n");
  printf("\tThe pointers increment by one, regardless of data type size, while\n");
  printf("\tthe actual addresses increment by the type size. Therefore, this\n");
  printf("\treduces to Address2 - Address1 = 4\n");
  printf("\t%p - %p = %ld\n", q, p, q-p);

  // Question D)
  printf("Is the condition p < q true or false?\n");
  printf("\tThe values of p and q are memory addresses and, in modern hardware,\n");
  printf("\tthe memory is virtualized, which means the addresses do not have to\n");
  printf("\tcorrespond to physical addresses. While the physical addresses may\n");
  printf("\tsometimes be out of order and mapped/managed by the hardware, the \n");
  printf("\tpointer addresses will always be in ascending order.\n");
  printf("\t%p < %p = ", p, q);
  printf("%s\n", p<q ? "true": "false");

  // Question E
  printf("Is the condition *p > *q true or false?\n"); 
  printf("\tThe value at p is 15\n");
  printf("\tThe value at q is 2\n");
  printf("\t15 > 2 is ");
  printf("%s\n", *p > *q ? "true": "false");


  return EXIT_SUCCESS;
}
