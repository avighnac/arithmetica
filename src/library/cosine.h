#ifndef _cosine_h_
#define _cosine_h_

#include "arcsin.h"
#include "sine.h"
#include "truncate.h"
#include <basic_math_operations.h>
#include <stddef.h>
#include <string.h>

char *cosine(const char *number, size_t accuracy) {
  // cos(x) = sin(pi / 2 - x)
  // = sin(arcsin(1) - x)

  size_t num_accuracy = 10;
  if (strchr(number, '.') != NULL)
    num_accuracy = number + strlen(number) - 1 - strchr(number, '.');
  num_accuracy += 2; // to keep final answer accuracy high
  char _half_pi[] = "1."
                    "5707963267948966192313216916397514420985846996875529104874"
                    "722961539082031431044993140174126710585339";
  char *half_pi = (char *)calloc(num_accuracy + 3, 1);
  if (num_accuracy > 100) {
    free(half_pi);
    half_pi = arcsin("1", num_accuracy);
  } else {
    truncate(_half_pi, num_accuracy);
    strcpy(half_pi, _half_pi);
  }
  char *sine_arg = (char *)calloc(strlen(half_pi) + strlen(number) + 3, 1);
  subtract(half_pi, number, sine_arg);
  char *answer = sine(sine_arg, accuracy);

  free(half_pi);
  free(sine_arg);

  return answer;
}

#endif