#pragma once

#ifndef NTLIB_POLYNOMIAL_H
#define NTLIB_POLYNOMIAL_H

#include <vector>
#include <iostream>
#include "string_modifiers.h"

namespace ntlib {

template<typename T>
class Polynomial {
 private:
  int order;

 public:
  std::vector<T> coefficients;
  size_t number_of_terms;

  Polynomial(std::vector<T> &_coefficients);
  Polynomial(std::string &poly_string) {
    std::vector<std::string> tokens = ntlib::split_into_tokens(poly_string);
    order = tokens.size() - 1;
    number_of_terms = tokens.size();
    for (const std::string token : tokens) {
      std::stringstream ss(token);
      T co_eff;
      ss >> co_eff;
      coefficients.emplace_back(co_eff);
    }
  }
  Polynomial() = default;

  // apply the power rule (c*n)x^(n-1)
  Polynomial<T> Derivative() {
    std::vector<T> terms;

    for (int i = 1; i < number_of_terms; i++) {
      terms.emplace_back(coefficients[i] * i);
    }
    return Polynomial(terms);
  }

  Polynomial<T> Integrate() {

  }
};

template<typename T>
Polynomial<T>::Polynomial(std::vector<T> &_coefficients)
    : coefficients{_coefficients},
      order{static_cast<int>(_coefficients.size() - 1)},
      number_of_terms{_coefficients.size()} {}

template<typename T>
std::ostream &operator<<(std::ostream &os, Polynomial<T> &p) {
  std::stringstream ss;
  int degree = 0;
  const char *c_dot = u8"\u22c5";
  for (T coefficient : p.coefficients) {
    switch (degree) {
      case 0:ss << coefficient << c_dot << "1";
        break;
      case 1:ss << coefficient << c_dot << "x";
        break;
      default:ss << coefficient << c_dot << "x" << "^" << degree;
    }
    if (degree != p.number_of_terms - 1) { ss << " + "; }
    degree++;
  }
  os << ss.str();
  return os;
}

} // namespace

#endif
