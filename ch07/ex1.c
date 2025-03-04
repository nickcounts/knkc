#include <stdio.h>

int octal = 077;
int hex = 0x77;
int other = 0XABC;

int main(void) {
  printf("Decimal representations of constants.\n");
  printf("077:\t%d\n", octal);
  printf("0x77:\t%d\n", hex);
  printf("0XABC:\t%d\n", other);

  return 0;
}
