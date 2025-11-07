#include <stdio.h>
#include "gcd.h"
#include "inverse.h"

int main(void) {
    // demo: gcd + coefficients
    int a = 7469, b = 2464, g, m, n;
    GCD(a, b, &g, &m, &n);
    printf("GCD(%d,%d) = %d; m=%d, n=%d  -> %d*m + %d*n = %d\n",
           a, b, g, m, n, a, b, a*m + b*n);

    // demo: modular inverse
    long long x = 3, mod = 11;
    long long inv = inverse(x, mod);
    if (inv == -1)
        printf("No inverse for %lld mod %lld (gcd != 1)\n", x, mod);
    else
        printf("inverse(%lld mod %lld) = %lld  (check: %lld)\n",
               x, mod, inv, (x*inv)%mod);

    return 0;
}
