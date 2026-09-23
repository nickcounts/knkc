/* Chapter 16, Exercise 11
 *
 * Suppose that `s` is the following structure:
 *
 * 
 * struct {
 *   double a;
 *   union {
 *     char b[4];
 *     double c;
 *     int d;
 *   } e;
 *   char f[4];
 * } s;
 * 
 * if `char` values occupy one byte, `int` values are 4-bytes, and 
 * `double` values are 8-bytes, how much space with the compiler allocate 
 * for `s` (assuming no holes)
 *
 *
 *
 * struct {
 *   double a;        8
 *   union {          8 (max of union)
 *     char b[4];         1x4
 *     double c;          8
 *     int d;             4
 *   } e;
 *   char f[4];       1x4
 * } s;
 *
 *
 * Total bytes: 8 + 8 + 4 = 20 bytes
 */

// Function to allow `make all` to complete
int main(void) {
  return 0;
}


