#ifndef INVERSE_H
#define INVERSE_H

/* Compute modular inverse: returns a^{-1} mod n in [0, n-1].
 * If inverse does not exist (gcd != 1) returns -1.
 */
long long inverse(long long a, long long n);

#endif
