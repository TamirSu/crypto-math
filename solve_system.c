#include "gcd.h"
#include "inverse.h"
#include "solve_system.h"
#include <stdint.h>

long long Solve_System(long long a, long long p, long long b, long long q) {
    if (p <= 0 || q <= 0) return -1;

    long long g, sx, sy;
    GCD(p, q, &g, &sx, &sy);
    if (g != 1) return -1; /* moduli must be coprime for this CRT */

    long long n = p * q;

    long long a_mod = a % p; if (a_mod < 0) a_mod += p;
    long long b_mod = b % q; if (b_mod < 0) b_mod += q;

    long long q_inv = inverse(q, p);
    long long p_inv = inverse(p, q);
    if (q_inv < 0 || p_inv < 0) return -1; /* should not happen if coprime */

    /* Use 128-bit intermediate to avoid overflow on multiplications */
    __int128 term1 = (__int128)a_mod * (__int128)q % (__int128)n;
    term1 = (term1 * (__int128)q_inv) % (__int128)n;

    __int128 term2 = (__int128)b_mod * (__int128)p % (__int128)n;
    term2 = (term2 * (__int128)p_inv) % (__int128)n;

    long long x = (long long)((term1 + term2) % (__int128)n);
    if (x < 0) x += n;
    return x;
}
