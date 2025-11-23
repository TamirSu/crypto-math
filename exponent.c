#include "exponent.h"
#include <stddef.h>

unsigned long long Exponent(long long x, long long e, long long m) {
    if (m <= 0) return 0;
    if (e < 0) return 0; /* negative exponents not supported here */

    unsigned long long mod = (unsigned long long)m;
    unsigned long long base = (unsigned long long)((x % m + m) % m);
    unsigned long long res = 1 % mod;

    while (e > 0) {
        if (e & 1) {
            res = (unsigned long long)((__uint128_t)res * base % mod);
        }
        base = (unsigned long long)((__uint128_t)base * base % mod);
        e >>= 1;
    }

    return res;
}
