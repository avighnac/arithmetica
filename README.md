# Arithmetica

Arithmetica is a general purpose linux math library with a wide variety of mathematical functions and features.

This library uses [basic_math_operations](https://github.com/avighnac/basic_math_operations) to achieve arbitrary precision. While linking an application using arithmetica, basic_math_operations will also have to be linked.

# Functions

Currently, arithmetica has the following functions:

- `arcsin()` computes the [inverse sine](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions) of any number within the function's domain to any decimal place.
- `arctan()` computes the [inverse tangent](https://en.wikipedia.org/wiki/Inverse_trigonometric_functions) of any number within the function's domain to any decimal place.
- `exponential()` computes e^x, where x is any rational number to any decimal place.
- `factorial()` computes the [factorial](https://en.wikipedia.org/wiki/Factorial) of a non-negative integer.
- `fraction_to_continued_fraction()` converts a non-negative rational fraction to a [continued fraction](https://en.wikipedia.org/wiki/Continued_fraction).
- `igcd()` computes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two non-negative integers.
- `ilcm()` computes the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of two non-negative integers.
- `natural_logarithm()` computes the [natural logarithm](https://en.wikipedia.org/wiki/Natural_logarithm) of a positive number to any decimal place.
- `repeating_decimal_to_fraction()` converts a [repeating decimal](https://en.wikipedia.org/wiki/Repeating_decimal) to a fraction.
- `sine()` computes the [sine](https://en.wikipedia.org/wiki/Sine_and_cosine) of an angle in radians to any decimal place.
- `square_root()` computes the [square root](https://en.wikipedia.org/wiki/Square_root) of a number to any decimal place.
- `terminating_decimal_to_fraction()` converts a terminating decimal to a fraction.
