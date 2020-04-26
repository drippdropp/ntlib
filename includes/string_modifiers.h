#pragma once

#ifndef NTLIB_STRING_MODIFIERS_H
#define NTLIB_STRING_MODIFIERS_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <type_traits>
#include <boost/algorithm/string.hpp>

namespace ntlib {

std::vector<std::string> split_into_tokens(std::string &s) {
  std::string delimiters("+ ");
  std::vector<std::string> tokens;
  boost::split(tokens, s, boost::is_any_of(delimiters));
  return tokens;
}
/**
 * @todo Add support for other numeric types
 * @tparam T
 * @param s
 * @return [std::vector<T>]
 */
template<typename T>
std::vector<T> split_into_numeric_tokens(std::string &s) {
  // restrict to int, double, and float.
  static_assert(
      std::is_same<T, int>::value ||
          std::is_same<T, double>::value,
      "This function is only supports int and double.");
  std::vector<std::string> tokens = split_into_tokens(s);
  std::vector<T> output_vec;
  output_vec.reserve(tokens.size());
  // only supporting double and int
  bool use_double = std::is_same<T, double>(tokens[0]);
  for (size_t i = 0; i < tokens.size(); i++) {
    if (use_double)
      output_vec[i] = std::stod(tokens[i]);
    else
      output_vec[i] = std::stoi(tokens[i]);
  }
  return output_vec;
}

std::vector<std::string> tokenize(std::string &str) {
  char *cstr = new char[str.length() + 1];
  std::strcpy(cstr, str.c_str());
  char *pch = std::strtok(cstr, " +-");
  std::vector<std::string> tokens;

  while (pch != nullptr) {
    pch = strtok(nullptr, " ,.-");
    tokens.emplace_back(pch);
  }
  delete[] cstr;
  return tokens;
}

template<typename T>
std::vector<T> string_to_numeric(std::vector<std::string> &s_vec) {
  std::vector<T> output_vec;
  output_vec.reserve(s_vec.size());
  for (size_t i = 0; i < s_vec.size(); i++) {
    std::stringstream ss(s_vec[i]);
    T coefficient;
    ss >> coefficient;
    output_vec[i] = coefficient;
  }
  return output_vec;
}

} // namespace

#endif
