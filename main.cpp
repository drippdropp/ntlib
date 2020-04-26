#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <limits>
#include <chrono>
#include "includes/crypto.h"
#include "includes/factorizer.h"
#include "includes/primes.h"
#include "includes/string_modifiers.h"
#include "includes/polynomial.h"

using namespace ntlib;

int main(int argc, char **argv) {
  std::vector<int> co_eff = {2, 4, -3, 4};
  Polynomial<int> poly(co_eff);
  std::cout << poly << std::endl;
  std::cout << std::endl;

  Polynomial<int> D_poly = poly.Derivative();
  std::cout << D_poly << std::endl;

  return 0;
}