#include <stdio.h>

int main(void) {
  printf("%d\n", 'A');
  printf("%d\n", 0b1000001); // 64 32 16 8 4 2 1 -> 65
  printf("%d\n", 0101);      // (octal) 64 8 1
  printf("%d\n", 0x41);      // (hex) 4*16 = 64 + 1 = 65

  return 0;
}
