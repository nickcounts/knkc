// Ex. 3
// Write a function gcd(m, n) that calculates the greatest common dicisor
// of the integers m and n.

int gcd(int m, int n) {
  int r;
  do {

    // ensure m is the larger number
    if (m < n) {
      int temp = m;
      m = n;
      n = temp;
    }

    r = m % n;

    if (r == 0 || n == 0) {
      break;
    }

    if (r) {
      m = n;
      n = r;
    }
  } while (1);
  return n;
}
