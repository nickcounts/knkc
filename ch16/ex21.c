/* Chapter 16, Exercise 21
 *
 * What are the integer values of the enumeration constants in each of the 
 * following declarations?
 *
 * a) enum {NUL, SOH, STX, ETX};
 * b) enum {VT = 11, FF, CR};
 * c) enum {SO = 14, SI, DLE, CAN=24, EM};
 * d) enum {ENQ=45, ACK, BEL, LF=37, ETB, ESC};
 */

enum {NUL, SOH, STX, ETX};
enum {VT = 11, FF, CR};
enum {SO = 14, SI, DLE, CAN=24, EM};
enum {ENQ=45, ACK, BEL, LF=37, ETB, ESC};

#include <stdio.h>

int main(void){
  printf("A) 0 1 2 3\n");
  printf("   %d %d %d %d\n", NUL, SOH, STX, ETX);

  printf("B) 11 12 13\n");
  printf("   %d %d %d\n", VT, FF, CR);

  printf("C) 14 15 16 24 25\n");
  printf("   %d %d %d %d %d\n", SO, SI, DLE, CAN, EM);

  printf("D) 45 46 48 37 38 39\n");
  printf("   %d %d %d %d %d %d\n", ENQ, ACK, BEL, LF, ETB, ESC);

  printf("\n");
  return 0;
}
