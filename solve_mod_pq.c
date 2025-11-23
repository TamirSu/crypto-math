#include "exponent.h"
#include "solve_system.h"
#include "solve_mod_pq.h"

unsigned long long solve_mod_pq(long long x, long long e,
                                long long p, long long q)
{
    if (p <= 0 || q <= 0) return (unsigned long long)-1;

    unsigned long long vp = Exponent(x, e, p);
    unsigned long long vq = Exponent(x, e, q);

    long long vp_ll = (long long)vp;
    long long vq_ll = (long long)vq;

    long long res = Solve_System(vp_ll, p, vq_ll, q);
    if (res < 0) return (unsigned long long)-1;
    return (unsigned long long)res;
}
