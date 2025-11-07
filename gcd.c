#include <stdio.h>
void GCD(int a ,int b, int* gcd, int* m,int*n){
        if (b==0){
            *gcd=a;
            *m=1;
            *n=0;
        }
        else{
            int gcd_temp, m_temp, n_temp;

            GCD(b, a % b, &gcd_temp, &m_temp, &n_temp);

            *gcd =gcd_temp;
            *m=n_temp;
            *n=m_temp-(a/b)* n_temp;
            
        }
    }
