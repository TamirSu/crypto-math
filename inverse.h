// inverse.h
#ifndef INVERSE_H
#define INVERSE_H
#include <stdbool.h>

// Returns a^{-1} mod n, or -1 if it doesn't exist (gcd != 1)
long long inverse(long long a, long long n);

// Convenience checker
bool has_inverse(long long a, long long n);

#endif
