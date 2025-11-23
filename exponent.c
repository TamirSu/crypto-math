#include "exponent.h"

unsigned long long Exponent(long long x, long long e, long long p) {
    unsigned long long result = 1;
    unsigned long long base = x % p;

    while (e > 0) {
        if (e & 1) {
            result = (result * base) % p;
        }
        base = (base * base) % p;
        e >>= 1;  // divide exponent by 2
    }
    return result;
}
