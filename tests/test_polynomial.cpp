#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PolynomialSuite
#include <boost/test/unit_test.hpp>
#include "../includes/polynomial.h"

BOOST_AUTO_TEST_SUITE(PolynomialTests)

BOOST_AUTO_TEST_CASE(PolyConstructorWithArgs) {
  std::vector<int> coefficients{1, 2, 3};
  ntlib::Polynomial poly1(coefficients);
  ntlib::Polynomial poly2(coefficients);
  BOOST_CHECK(poly1.coefficients == poly2.coefficients);
}

BOOST_AUTO_TEST_CASE(PolyConstructorWithoutArgs) {
  std::vector<int> coefficients{};
  ntlib::Polynomial poly1(coefficients);
  ntlib::Polynomial poly2(coefficients);
  BOOST_CHECK(poly1.coefficients == poly2.coefficients);
}

BOOST_AUTO_TEST_CASE(DerivativeCanBeComputed)
{
  std::vector<int> coefficients{1, 2, 3};
  ntlib::Polynomial poly(coefficients);
  ntlib::Polynomial D1_poly = poly.Derivative();
  std::vector<int> poly_derivative{2, 6};
  BOOST_CHECK(D1_poly.coefficients == poly_derivative);
}

BOOST_AUTO_TEST_CASE(IntegralCanBeComputed)
{
  std::vector<int> coefficients{1, 2, 3};
  ntlib::Polynomial poly(coefficients);
  ntlib::Polynomial Poly = poly.Integrate();
  std::vector<ntlib::Rational<int>> poly_integrand{
    ntlib::Rational<int>(0,1),
      ntlib::Rational<int>(1,1),
      ntlib::Rational<int>(1,1),
      ntlib::Rational<int>(1,1),
  };
}

BOOST_AUTO_TEST_SUITE_END()