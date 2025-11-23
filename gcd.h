#ifndef GCD_H
#define GCD_H

/* Extended Euclidean algorithm
 * Computes gcd = gcd(a,b) and integers x,y such that:
 *    a*x + b*y = gcd
 * All parameters are signed 64-bit (long long).
 */
void GCD(long long a, long long b, long long *gcd, long long *x, long long *y);

#endif
