#include "random_prime.h"
#include "exponent.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generate a random 32-bit odd number with MSB=1, LSB=1 */
unsigned long long random_odd_32bit(void) {
    /* Generate 30 random bits for the middle */
    unsigned long long middle = 0;
    for (int i = 0; i < 30; i++) {
        if (rand() & 1) {
            middle |= (1ULL << i);
        }
    }
    
    /* Set MSB (bit 31) and LSB (bit 0) to 1 */
    unsigned long long result = (1ULL << 31) | (middle << 1) | 1ULL;
    
    return result;
}

/* Helper: Modular multiplication with overflow protection using 128-bit intermediate */
static unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    return (unsigned long long)((__uint128_t)a * (__uint128_t)b % (__uint128_t)mod);
}

/* Miller-Rabin primality test - single round with base a */
static int miller_rabin_round(unsigned long long n, unsigned long long a, 
                               unsigned long long d, int s) {
    /* Compute x = a^d mod n using our fast exponentiation */
    unsigned long long x = Exponent(a, d, n);
    
    if (x == 1 || x == n - 1) {
        return 1; /* possibly prime */
    }
    
    /* Square x (s-1) times */
    for (int i = 0; i < s - 1; i++) {
        x = mulmod(x, x, n);
        if (x == n - 1) {
            return 1; /* possibly prime */
        }
    }
    
    return 0; /* composite */
}

/* Miller-Rabin primality test with 20 rounds */
int check_primality(unsigned long long n) {
    /* Handle edge cases */
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (n % 2 == 0) return 0;
    
    /* Write n-1 as 2^s * d where d is odd */
    unsigned long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    
    /* Perform 20 rounds of Miller-Rabin */
    for (int round = 0; round < 20; round++) {
        /* Generate random base in [2, n-2] */
        unsigned long long a;
        if (n <= 4) {
            a = 2;
        } else {
            a = 2 + (unsigned long long)rand() % (n - 3);
        }
        
        if (!miller_rabin_round(n, a, d, s)) {
            return 0; /* definitely composite */
        }
    }
    
    return 1; /* probably prime */
}

/* Generate a random 32-bit prime */
unsigned long long Generate_long_prime(void) {
    static int seeded = 0;
    
    /* Seed the random number generator once */
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }
    
    unsigned long long candidate;
    int attempts = 0;
    
    while (1) {
        attempts++;
        candidate = random_odd_32bit();
        
        if (check_primality(candidate)) {
            printf("Prime = %llu, attempts = %d\n", candidate, attempts);
            return candidate;
        }
    }
}
