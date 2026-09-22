/* Chapter 16, Exercise 12
 *
 * Suppose that `s` is the following union:
 *
 * 
 * union {
 *   double a;
 *   struct {
 *     char b[4];
 *     double c;
 *     int d;
 *   } e;
 *   char f[4];
 * } u;
 * 
 * if `char` values occupy one byte, `int` values are 4-bytes, and 
 * `double` values are 8-bytes, how much space with the compiler allocate 
 * for `s` (assuming no holes)
 *
 *
 *
 * union {
 *   double a;        8
 *   struct {         16 
 *     char b[4];         1x4
 *     double c;          8
 *     int d;             4
 *   } e;
 *   char f[4];       4   1x4
 * } u;
 *
 *
 * The struct is 16 bytes, which is the largest of the 3 members (16, 8, 4)
 * The compiler will allocate 16 bytes to the union `u`
 */


#include <stddef.h>
#include <stdio.h>

union {
  double a;
  struct {
    char b[4];
    double c;
    int d;
  } e;
  char f[4];
} u;

int main(void){
  size_t union_size = sizeof(u);

  size_t s_struct_size = sizeof(u.e);
  size_t s_char_size   = sizeof(u.e.b);
  size_t s_double_size = sizeof(u.e.c);
  size_t s_int_size    = sizeof(u.e.d);

  size_t double_size = sizeof(u.a);
  size_t char_size   = sizeof(u.f);

  printf("The double is allocated %zu bytes\n", double_size);
  printf("The struct is allocated %zu bytes\n", s_struct_size);

  printf("   The struct char[] is %zu bytes\n", s_char_size);
  printf("   The struct double is %zu bytes\n", s_double_size);
  printf("   The struct int is    %zu bytes\n", s_int_size);


  printf("The char[] is allocated %zu bytes\n", char_size);

  printf("The union is allocated %zu bytes\n", union_size);


  printf("\n\nIt seems that my compiler pads the struct, making it 24 bytes\n");
  printf("instead of 20. Regardless, the struct is the largest element of \n"); 
  printf("the union, and is therfore the size of the union.\n");

  return 0;
}
