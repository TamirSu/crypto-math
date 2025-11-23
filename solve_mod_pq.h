#ifndef SOLVE_MOD_PQ_H
#define SOLVE_MOD_PQ_H

/* Compute x^e mod (p*q) by computing residues mod p and q and combining via CRT.
 * Returns value in [0, p*q-1] on success, or (unsigned long long)-1 on error.
 */
unsigned long long solve_mod_pq(long long x, long long e, long long p, long long q);

#endif
