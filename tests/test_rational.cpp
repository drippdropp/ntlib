#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RationalSuite
#include <boost/test/unit_test.hpp>
#include "../includes/polynomial.h"
#include "../includes/rational.h"

BOOST_AUTO_TEST_SUITE(RationalTests)

BOOST_AUTO_TEST_CASE(IntConstructorWithArgs) {
  ntlib::Rational<int> ratio(1, 2);
  BOOST_REQUIRE_EQUAL(ratio.numerator, 1);
  BOOST_REQUIRE_EQUAL(ratio.denominator, 2);
}
BOOST_AUTO_TEST_CASE(IntConstructorWithoutArgs) {
  ntlib::Rational<int> ratio;
  BOOST_REQUIRE_EQUAL(ratio.numerator, 0);
  BOOST_REQUIRE_EQUAL(ratio.denominator, 1);
}
BOOST_AUTO_TEST_CASE(LongConstructorWithArgs) {
  ntlib::Rational<long> ratio(1, 2);
  BOOST_REQUIRE_EQUAL(ratio.numerator, 1L);
  BOOST_REQUIRE_EQUAL(ratio.denominator, 2L);
}
BOOST_AUTO_TEST_CASE(LongConstructorWithoutArgs) {
  ntlib::Rational<long> ratio;
  BOOST_REQUIRE_EQUAL(ratio.numerator, 0L);
  BOOST_REQUIRE_EQUAL(ratio.denominator, 1L);
}
BOOST_AUTO_TEST_CASE(RationalConstructorFromRational) {
  ntlib::Rational<int> ratio{1,2};
  ntlib::Rational<int> ratio2(ratio);
  BOOST_REQUIRE_EQUAL(ratio.numerator, ratio2.numerator);
  BOOST_REQUIRE_EQUAL(ratio.denominator, ratio2.denominator);
}
BOOST_AUTO_TEST_CASE(CannotUseZeroAsDenominator) {
  BOOST_CHECK_THROW(
      ntlib::Rational<int> ratio(1, 0),
      std::runtime_error
      );
}
BOOST_AUTO_TEST_CASE(RationalObjectsCanBeAdded) {
  ntlib::Rational<int> ratio(1, 2);
  ntlib::Rational<int> ratio2(2, 3);
  ntlib::Rational<int> ratio3(ratio + ratio2);
  BOOST_REQUIRE_EQUAL(ratio3.numerator, 7);
  BOOST_REQUIRE_EQUAL(ratio3.denominator, 6);
}
BOOST_AUTO_TEST_CASE(RationalObjectsCanBeSubtracted) {
  ntlib::Rational<int> ratio(1, 2);
  ntlib::Rational<int> ratio2(1, 3);
  ntlib::Rational<int> ratio3(ratio - ratio2);
  BOOST_REQUIRE_EQUAL(ratio3.numerator, 1);
  BOOST_REQUIRE_EQUAL(ratio3.denominator, 6);
}
BOOST_AUTO_TEST_CASE(RationalObjectsCanBeScaledByNumericsFromRight) {
  ntlib::Rational<int> ratio(1, 2);
  int some_constant = 2;
  ntlib::Rational<int> ratio2(ratio * some_constant);
  BOOST_REQUIRE_EQUAL(ratio2.numerator, 1);
  BOOST_REQUIRE_EQUAL(ratio2.denominator, 1);
}

BOOST_AUTO_TEST_CASE(RationalObjectsCanBeScaledByNumericsFromLeft) {
  ntlib::Rational<int> ratio(1, 2);
  int some_constant = 2;
  ntlib::Rational<int> ratio2(some_constant * ratio);
  BOOST_REQUIRE_EQUAL(ratio2.numerator, 1);
  BOOST_REQUIRE_EQUAL(ratio2.denominator, 1);
}

BOOST_AUTO_TEST_CASE(RationalObjectsCanBeMultiplied) {
  ntlib::Rational<int> ratio(1, 2);
  ntlib::Rational<int> ratio2(2, 3);
  ntlib::Rational<int> ratio3(ratio * ratio2);
  BOOST_REQUIRE_EQUAL(ratio3.numerator, 1);
  BOOST_REQUIRE_EQUAL(ratio3.denominator, 3);
}
BOOST_AUTO_TEST_CASE(RationalObjectsCanBeDivided) {
  ntlib::Rational<int> ratio(1, 2);
  ntlib::Rational<int> ratio2(2, 3);
  ntlib::Rational<int> ratio3(ratio / ratio2);
  BOOST_REQUIRE_EQUAL(ratio3.numerator, 3);
  BOOST_REQUIRE_EQUAL(ratio3.denominator, 4);
}

BOOST_AUTO_TEST_SUITE_END();
