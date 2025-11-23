#include <stdio.h>
#include "gcd.h"
#include "inverse.h"
#include "exponent.h"

int main(void) {

    // --- Existing tests ---
    int a = 7469, b = 2464, g, m, n;
    GCD(a, b, &g, &m, &n);
    printf("GCD(%d,%d) = %d; m=%d, n=%d  -> %d*m + %d*n = %d\n",
           a, b, g, m, n, a, b, a*m + b*n);

    long long x = 3, mod = 11;
    long long inv = inverse(x, mod);
    printf("inverse(%lld mod %lld) = %lld\n", x, mod, inv);


    // --- NEW TEST: Square-and-Multiply ---
    printf("\nTesting Exponent():\n");
    printf("2^79 mod 101 = %llu (expected 42)\n",
           Exponent(2, 79, 101));

    printf("3^97 mod 101 = %llu (expected 15)\n",
           Exponent(3, 97, 101));

    return 0;
}
