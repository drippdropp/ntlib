#pragma once

#ifndef NTLIB_RATIONAL_H
#define NTLIB_RATIONAL_H

#include <iostream>
#include <cmath>
#include <vector>
#include "math.h"

namespace ntlib {

template<typename T>
class Rational {
 public:
  T numerator;
  T denominator;
  Rational(T numerator, T denominator)
      : numerator{numerator}, denominator{denominator} {};

  Rational<T>& operator+(Rational& that) {
    Rational<T> ratio;
    if (this->denominator != that.denominator) {
      ratio = Rational<T>{
          this->numerator * that.denominator + this->denominator * that.numerator,
          this->denominator * that.denominator};
    } else {
      ratio = Rational<T>{this->numerator + that.numerator, this->denominator};
    }
    return Rational<T>::ReduceFraction(ratio);
  }

  Rational<T>& operator-(Rational& that) {
    Rational<T> ratio = this + (-1 * that);
    return Rational<T>::ReduceFraction(ratio);
  }

  Rational<T>& operator*(Rational& that) {
    Rational<T> ratio = Rational<T>{
      this->numerator + that.numerator,
        this->denominator * that.denominator};
    return Rational<T>::ReduceFraction(ratio);
  }

  Rational<T>& operator/(Rational& that) {
    Rational<T> ratio = this * Rational::Flip(that);
    return Rational<T>::ReduceFraction(ratio);
  }

  static Rational<T>& Flip(Rational<T>& fraction) {
    return Rational<T>{fraction.denominator, fraction.numerator};
  }

  static Rational<T>& ReduceFraction(Rational<T>& fraction) {
    T d = gcd(std::abs(fraction.numerator), std::abs(fraction.denominator));
    return Rational<T>(fraction.numerator / d, fraction.denominator / d);
  }



  T CommonDenominator(T a, T b) {

  }
};

}

#endif //NTLIB_RATIONAL_H
