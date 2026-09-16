

#include <stdio.h>

// No equals sign, this was broken #define N = 10
#define N 10

#define INC(x) x+1
// No space before () or it breaks #define SUB (x,y) x-y
#define SUB(x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void) {
  int a[N], i, j, k, m;

#ifdef N
  i = j;
#else
  j = i;
#endif

  i = 10 * INC(j);
  i = SUB(j, k);
  i = SQR((SQR(j)));
  i = CUBE(j);
  // i = jk is meaningless, removing this line
  // i = M1(j,k);
  puts(M2(i, j));

#undef SQR
  // Can't use SQR if we undefine it!
  // i = SQR(j);
#define SQR
  i = SQR(j);



  return 0;
}
