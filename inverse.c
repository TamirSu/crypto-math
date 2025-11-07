#include "gcd.h"
#include "inverse.h"

// Uses your extended GCD: if gcd(a,n)=1, the coefficient 'm' is the inverse.
// Note: your GCD uses int, so this is good for small/moderate values.
long long inverse(long long a, long long n) {
    int g, m, k;
    GCD((int)(a % n + n) % n, (int)n, &g, &m, &k);
    if (g != 1) return -1;                 // no inverse
    long long inv = ((long long)m % n + n) % n;  // normalize to [0, n-1]
    return inv;
}
