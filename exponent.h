#ifndef EXPONENT_H
#define EXPONENT_H

/* Fast modular exponentiation (square-and-multiply).
 * Computes x^e mod m. e must be non-negative. If m <= 0 returns 0.
 * Uses 128-bit intermediate to avoid overflow on multiplication when available.
 */
unsigned long long Exponent(long long x, long long e, long long m);

#endif
