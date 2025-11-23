#include "gcd.h"

/* Iterative extended Euclidean algorithm using 64-bit integers.
 * Produces gcd >= 0 and coefficients x,y such that a*x + b*y = gcd.
 */
void GCD(long long a, long long b, long long *g, long long *x, long long *y) {
    long long old_r = a, r = b;
    long long old_s = 1, s = 0;
    long long old_t = 0, t = 1;

    while (r != 0) {
        long long q = old_r / r;
        long long tmp;

        tmp = r;
        r = old_r - q * r;
        old_r = tmp;

        tmp = s;
        s = old_s - q * s;
        old_s = tmp;

        tmp = t;
        t = old_t - q * t;
        old_t = tmp;
    }

    /* Make gcd non-negative; adjust signs of coefficients accordingly */
    if (old_r < 0) {
        old_r = -old_r;
        old_s = -old_s;
        old_t = -old_t;
    }

    if (g) *g = old_r;
    if (x) *x = old_s;
    if (y) *y = old_t;
}
