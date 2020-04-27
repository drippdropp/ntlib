#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RationalSuite
#include <boost/test/unit_test.hpp>
#include "../includes/polynomial.h"
#include "../includes/rational.h"

BOOST_AUTO_TEST_SUITE(RationalTests)
  BOOST_AUTO_TEST_CASE(IntConstructorWithArgs) {
    // constructor for int with provided args
    ntlib::Rational<int> ratio(1, 2);
    BOOST_REQUIRE_EQUAL(ratio.numerator, 1);
    BOOST_REQUIRE_EQUAL(ratio.denominator, 2);
  }
  BOOST_AUTO_TEST_CASE(IntConstructorWithoutArgs) {
    // constructor for int defaults to 0/1 with no args
    ntlib::Rational<int> ratio;
    BOOST_REQUIRE_EQUAL(ratio.numerator, 0);
    BOOST_REQUIRE_EQUAL(ratio.denominator, 1);
  }
  BOOST_AUTO_TEST_CASE(LongConstructorWithArgs) {
    // constructor for int with provided args
    ntlib::Rational<long> ratio(1, 2);
    BOOST_REQUIRE_EQUAL(ratio.numerator, 1L);
    BOOST_REQUIRE_EQUAL(ratio.denominator, 2L);
  }
  BOOST_AUTO_TEST_CASE(LongConstructorWithoutArgs) {
    // constructor for int defaults to 0/1 with no args
    ntlib::Rational<long> ratio;
    BOOST_REQUIRE_EQUAL(ratio.numerator, 0L);
    BOOST_REQUIRE_EQUAL(ratio.denominator, 1L);
  }
  BOOST_AUTO_TEST_CASE(RationalConstructorFromRational) {
    // can generate a Rational from a Rational
    ntlib::Rational<int> ratio{1,2};
    ntlib::Rational<int> ratio2(ratio);
    BOOST_REQUIRE_EQUAL(ratio.numerator, ratio2.numerator);
    BOOST_REQUIRE_EQUAL(ratio.denominator, ratio2.denominator);
  }
  BOOST_AUTO_TEST_CASE(RationalObjsCanBeAdded) {
    ntlib::Rational<int> ratio(1, 2);
    ntlib::Rational<int> ratio2(2, 3);
    ntlib::Rational<int> ratio3(ratio + ratio2);
    BOOST_REQUIRE_EQUAL(ratio3.numerator, 7);
    BOOST_REQUIRE_EQUAL(ratio3.denominator, 6);
  }
  BOOST_AUTO_TEST_CASE(RationalObjsCanBeSubtracted) {
    ntlib::Rational<int> ratio(1, 2);
    ntlib::Rational<int> ratio2(1, 3);
    ntlib::Rational<int> ratio3(ratio - ratio2);
    BOOST_REQUIRE_EQUAL(ratio3.numerator, 1);
    BOOST_REQUIRE_EQUAL(ratio3.denominator, 6);
  }
  BOOST_AUTO_TEST_CASE(RationalObjsCanBeMultiplied) {
    ntlib::Rational<int> ratio(1, 2);
    ntlib::Rational<int> ratio2(2, 3);
    ntlib::Rational<int> ratio3(ratio * ratio2);
    BOOST_REQUIRE_EQUAL(ratio3.numerator, 1);
    BOOST_REQUIRE_EQUAL(ratio3.denominator, 3);
  }

BOOST_AUTO_TEST_SUITE_END();
