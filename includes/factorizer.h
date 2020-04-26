#pragma once

#ifndef NTLIB_FACTORIZER_H
#define NTLIB_FACTORIZER_H

#include <algorithm>
#include <bitset>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>

namespace ntlib {

class Factorizer {
 public:
  template<typename T>
  static std::vector<T> Factors(T n) {
    std::vector<T> factors;
    factors.push_back(1);
    factors.push_back(n);

    for (std::size_t i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        factors.push_back(i);
        if (i * i != n) factors.push_back((T) n / i);
      }
    }
    std::sort(factors.begin(), factors.end());
    return factors;
  }
};

}

#endif
