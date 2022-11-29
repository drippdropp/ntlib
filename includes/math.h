#ifndef NTLIB_MATH_H
#define NTLIB_MATH_H

#define swap(p, q) { int temp = p; p = q; q = temp; }

namespace ntlib {
  
   /**
    * gcd (recursive version of gcd)
    **/
  long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  /**
   * gcd (recursive version of gcd)
   **/
  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  /**
   * gcdi (iterative version of gcd)
   **/
  long gcdi(long a, long b) {
    long gcd_output;
    if (a > b) swap(a, b);
    for (size_t i = 1; i <= b; ++i) {
      if (a % i == 0 && b % i == 0) {
        gcd_output = i;
      }
    }
    return gcd_output;
  }

  /**
   * gcdi (iterative version of gcd)
   **/
  int gcdi(int a, int b) {
    int gcd_output;
    if (a > b) swap(a, b);
    for (size_t i = 1; i <= b; ++i) {
      if (a % i == 0 && b % i == 0) {
        gcd_output = i;
      }
    }
    return gcd_output;
  }  
  
  long lcm(long a, long b) {
    return (a*b)/gcd(a, b);
  }
  
  long lcmi(long a, long b) {
    return (a*b)/gcdi(a, b); 
  }

}

#endif //NTLIB_MATH_H
