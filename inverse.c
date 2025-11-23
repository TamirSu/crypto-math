#include "gcd.h"
#include "inverse.h"

long long inverse(long long a, long long n) {
    if (n <= 0) return -1;

    long long a_mod = a % n;
    if (a_mod < 0) a_mod += n;

    long long g, x, y;
    GCD(a_mod, n, &g, &x, &y);
    if (g != 1) return -1; /* inverse doesn't exist */

    long long inv = x % n;
    if (inv < 0) inv += n;
    return inv;
}
