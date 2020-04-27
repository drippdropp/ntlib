#ifndef NTLIB_RATIONAL_H
#define NTLIB_RATIONAL_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <exception>
#include "math.h"

namespace ntlib {

template<typename T>
class Rational {
 public:
  T numerator;
  T denominator;
  Rational(T numerator, T denominator)
      : numerator{numerator}, denominator{denominator} {
    if (denominator == 0) {
      throw std::runtime_error("Cannot divide by zero.");
    }
  };

  Rational()
  : numerator{0}, denominator{1} {};

  Rational(Rational<T> &ratio)
  : numerator{ratio.numerator}, denominator{ratio.denominator} {}

  Rational<T> operator+(const Rational& that) {
    Rational<T> ratio{};
    if (this->denominator != that.denominator) {
      ratio = Rational<T>{
          this->numerator * that.denominator + this->denominator * that.numerator,
          this->denominator * that.denominator};
    } else {
      ratio = Rational<T>{this->numerator + that.numerator, this->denominator};
    }
    return ReduceFraction(ratio);
  }

  Rational<T> operator-(const Rational& that) {
    Rational<T> ratio{};
    if (this->denominator != that.denominator) {
      ratio = Rational<T>{
          this->numerator * that.denominator - this->denominator * that.numerator,
          this->denominator * that.denominator};
    } else {
      ratio = Rational<T>{this->numerator - that.numerator, this->denominator};
    }
    return ReduceFraction(ratio);
  }

  Rational<T> operator*(const T& that) {
    Rational<T> ratio = Rational<T>{
      this->numerator * that,
      this->denominator};
    return ReduceFraction(ratio);
  }

  Rational<T> operator*(const Rational& that) {
    Rational<T> ratio = Rational<T>{
      this->numerator * that.numerator,
        this->denominator * that.denominator};
    return ReduceFraction(ratio);
  }

  Rational<T> operator/(const Rational& that) {
    Rational<T> ratio = Rational<T>{
      this->numerator * that.denominator,
      this->denominator * that.numerator
    };
    return ReduceFraction(ratio);
  }

  static Rational<T> Flip(const Rational<T>& fraction) {
    Rational<T> ratio{fraction.denominator, fraction.numerator};
    return ratio;
  }

  static Rational<T> ReduceFraction(const Rational<T>& fraction) {
    T d = gcd(std::abs(fraction.numerator), std::abs(fraction.denominator));
    T numerator = fraction.numerator / d;
    T denominator = fraction.denominator / d;
    Rational<T> output_ratio(numerator, denominator);
    return output_ratio;
  }
};

template<typename T>
Rational<T> operator*(const T& that, Rational<T>& rational) {
  return rational * that;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Rational<T>& fraction) {
  std::stringstream ss;
  ss << fraction.numerator << "//" << fraction.denominator;
  os << ss.str();
  return os;
}

template<typename T>
std::ostream& operator<<(Rational<T>& fraction, std::ostream& os) {
  std::stringstream ss;
  ss << fraction.numerator << "//" << fraction.denominator;
  os << ss.str();
  return os;
}


}

#endif //NTLIB_RATIONAL_H
