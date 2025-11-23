#ifndef SOLVE_SYSTEM_H
#define SOLVE_SYSTEM_H

/* Chinese Remainder for two moduli.
 * Solves x ≡ a (mod p)
 *        x ≡ b (mod q)
 * Returns a value in [0, p*q-1] when p and q are coprime.
 * If p or q <= 0 or gcd(p,q) != 1 returns -1.
 */
long long Solve_System(long long a, long long p, long long b, long long q);

#endif
