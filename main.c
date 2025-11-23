#include <stdio.h>
#include <stdlib.h>
#include "gcd.h"
#include "inverse.h"
#include "solve_system.h"
#include "exponent.h"
#include "solve_mod_pq.h"
#include "random_prime.h"

static void test_gcd(void) {
    printf("=== GCD / Extended Euclid tests ===\n");
    long long a = 7469, b = 2464;
    long long g, x, y;
    GCD(a, b, &g, &x, &y);
    printf("GCD(%lld, %lld) = %lld; coefficients x=%lld y=%lld -> %lld*%lld + %lld*%lld = %lld\n",
           a, b, g, x, y, a, x, b, y, a*x + b*y);

    /* edge cases */
    GCD(0, 0, &g, &x, &y);
    printf("GCD(0,0) = %lld (expected 0), x=%lld y=%lld\n", g, x, y);
}

static void test_inverse(void) {
    printf("\n=== Modular inverse tests ===\n");
    printf("inverse(3 mod 11) = %lld (expected 4)\n", inverse(3, 11));
    printf("inverse(10 mod 17) = %lld (expected 12)\n", inverse(10, 17));
    printf("inverse(6 mod 9) = %lld (expected -1 non-invertible)\n", inverse(6,9));
}

static void test_exponent(void) {
    printf("\n=== Exponentiation tests ===\n");
    printf("2^79 mod 101 = %llu (expected 10)\n", Exponent(2,79,101));
    printf("3^0 mod 7 = %llu (expected 1)\n", Exponent(3,0,7));
    printf("(-2)^5 mod 13 = %llu (expected  -32 mod 13 =  -6 => 7) -> got %llu\n",
           Exponent(-2,5,13), Exponent(-2,5,13));
}

static void test_crt(void) {
    printf("\n=== CRT / Solve_System tests ===\n");
    long long x = Solve_System(2,5,3,7);
    printf("Solve x≡2 (mod5), x≡3 (mod7) -> x = %lld (expected 17)\n", x);

    /* non-coprime case should return -1 */
    long long bad = Solve_System(1,6,4,8);
    printf("Solve_System with non-coprime moduli -> %lld (expected -1)\n", bad);
}

static void test_solve_mod_pq(void) {
    printf("\n=== solve_mod_pq tests ===\n");
    unsigned long long r = solve_mod_pq(123456, 79, 101, 113);
    printf("123456^79 mod (101*113) = %llu\n", r);

    /* sanity: compare direct modexp on product when product fits in 64-bit */
    long long p = 101, q = 113;
    long long n = p * q;
    unsigned long long direct = Exponent(123456 % n, 79, n);
    printf("Direct modexp mod %lld = %llu ; CRT result = %llu\n", n, direct, r);
}

static void test_prime_generation(void) {
    printf("\n=== Prime Generation tests ===\n");
    
    /* Test random_odd_32bit generates numbers in correct range */
    printf("Testing random_odd_32bit():\n");
    for (int i = 0; i < 3; i++) {
        unsigned long long n = random_odd_32bit();
        printf("  Generated: %llu (0x%llx) - MSB=%d LSB=%d\n", 
               n, n, (int)((n >> 31) & 1), (int)(n & 1));
    }
    
    /* Test primality checker with known primes and composites */
    printf("\nTesting check_primality():\n");
    printf("  check_primality(2) = %d (expected 1)\n", check_primality(2));
    printf("  check_primality(3) = %d (expected 1)\n", check_primality(3));
    printf("  check_primality(17) = %d (expected 1)\n", check_primality(17));
    printf("  check_primality(97) = %d (expected 1)\n", check_primality(97));
    printf("  check_primality(100) = %d (expected 0)\n", check_primality(100));
    printf("  check_primality(2147483647) = %d (expected 1, Mersenne prime)\n", 
           check_primality(2147483647ULL));
    
    /* Generate a random prime */
    printf("\nGenerating a random 32-bit prime:\n");
    unsigned long long prime = Generate_long_prime();
    printf("Generated prime: %llu\n", prime);
    printf("Verification: check_primality(%llu) = %d\n", prime, check_primality(prime));
}

int main(void) {
    test_gcd();
    test_inverse();
    test_exponent();
    test_crt();
    test_solve_mod_pq();
    test_prime_generation();
    return 0;
}
