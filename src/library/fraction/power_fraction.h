#ifndef _power_fraction_h_
#define _power_fraction_h_

#include "fraction.h"
#include "parse_fraction.h"
#include <basic_math_operations.h>
#include <stdlib.h>
#include <string.h>

struct fraction power_fraction(struct fraction base, struct fraction exponent,
                               size_t accuracy) {
  // If the exponent is negative, then invert the fraction and make the exponent
  // positive since x^(-n) = (1/x)^n
  if (exponent.numerator[0] == '-') {
    size_t n = strlen(exponent.numerator);
    memmove(exponent.numerator, exponent.numerator + 1, n - 1);
    exponent.numerator[n - 1] = 0;

    // Reciprocate the fraction.
    if (base.numerator[0] == '-') {
      char *tempSwap = (char *)calloc(strlen(base.numerator), 1);
      strcpy(tempSwap, base.numerator + 1);
      base.numerator =
          (char *)realloc(base.numerator, strlen(base.denominator) + 2);
      strcpy(base.numerator + 1, base.denominator);
      base.denominator =
          (char *)realloc(base.denominator, strlen(tempSwap) + 1);
      strcpy(base.denominator, tempSwap);
      free(tempSwap);
    } else {
      char *tempSwap = (char *)calloc(strlen(base.numerator) + 1, 1);
      strcpy(tempSwap, base.numerator);
      base.numerator =
          (char *)realloc(base.numerator, strlen(base.denominator) + 1);
      strcpy(base.numerator, base.denominator);
      base.denominator =
          (char *)realloc(base.denominator, strlen(tempSwap) + 1);
      strcpy(base.denominator, tempSwap);
      free(tempSwap);
    }
  }

  char *exponentDecimal = (char *)calloc(
      strlen(exponent.numerator) + strlen(exponent.denominator) + accuracy + 3,
      1);
  divide(exponent.numerator, exponent.denominator, exponentDecimal, accuracy);

  char *powerNumerator = power(base.numerator, exponentDecimal, accuracy);
  char *powerDenominator = power(base.denominator, exponentDecimal, accuracy);

  char *parseFractionArgument =
      (char *)calloc(strlen(powerNumerator) + strlen(powerDenominator) + 2, 1);
  strncpy(parseFractionArgument, powerNumerator, strlen(powerNumerator));
  parseFractionArgument[strlen(powerNumerator)] = '/';
  strncpy(parseFractionArgument + strlen(powerNumerator) + 1, powerDenominator,
          strlen(powerDenominator));
  struct fraction answer = parse_fraction(parseFractionArgument);

  free(exponentDecimal);
  free(powerNumerator);
  free(powerDenominator);
  free(parseFractionArgument);

  return answer;
}

#endif