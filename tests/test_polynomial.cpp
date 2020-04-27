#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../includes/polynomial.h"

BOOST_AUTO_TEST_SUITE(PolynomialCheckSuite)

BOOST_AUTO_TEST_CASE(Constructors)
{
  std::vector<int> coefficients{1, 2, 3};
  ntlib::Polynomial poly1(coefficients);
  ntlib::Polynomial poly2(coefficients);
  BOOST_CHECK(poly1.coefficients == poly2.coefficients);
}

BOOST_AUTO_TEST_CASE(Derivative)
{
  std::vector<int> coefficients{1, 2, 3};
  ntlib::Polynomial poly(coefficients);
  ntlib::Polynomial D1_poly = poly.Derivative();
  std::vector<int> poly_derivative{2, 6};
  BOOST_CHECK_EQUAL(D1_poly.coefficients, poly_derivative);
}

BOOST_AUTO_TEST_SUITE_END()