#ifndef NTLIB_MATH_H
#define NTLIB_MATH_H

namespace ntlib {

long gcd(long a, long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

long lcm(long a, long b) {
  return (a*b)/gcd(a, b);
}

}

#endif //NTLIB_MATH_H
