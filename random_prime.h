#ifndef RANDOM_PRIME_H
#define RANDOM_PRIME_H

/* Generate a random 32-bit odd integer with MSB=1 and LSB=1.
 * Uses rand() which should be seeded with srand(time(NULL)) before calling.
 * Returns a number in range [0x80000001, 0xFFFFFFFF] that is odd.
 */
unsigned long long random_odd_32bit(void);

/* Miller-Rabin primality test with 20 rounds.
 * Returns 1 if n is probably prime, 0 if composite.
 * Handles edge cases: n < 2 (not prime), n == 2 (prime), even n > 2 (not prime).
 */
int check_primality(unsigned long long n);

/* Generate a random 32-bit prime number.
 * Repeatedly generates random odd 32-bit numbers and tests with Miller-Rabin.
 * Prints "Prime = <value>, attempts = <k>" when found.
 * Returns the prime number.
 */
unsigned long long Generate_long_prime(void);

#endif
