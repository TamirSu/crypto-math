// main.c
#include <stdio.h>
#include "gcd.h"
#include "inverse.h"

int main(void) {
    int g, m, n;

    // demo: extended gcd
    int a = 7469, b = 2464;
    GCD(a, b, &g, &m, &n);
    printf("GCD(%d,%d) = %d; m=%d, n=%d; check=%d\n",
           a, b, g, m, n, a*m + b*n);

    // demo: modular inverse
    long long inv = inverse(3, 11);
    printf("inverse(3 mod 11) = %lld\n", inv);

    return 0;
}
