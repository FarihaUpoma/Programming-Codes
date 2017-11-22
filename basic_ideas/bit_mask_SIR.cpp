#include <stdio.h>



#define I (1ll << 32)

unsigned long long N, L, R, M, m, i;

int main() {
    while (scanf("%lld %lld %lld", &N, &L, &R) == 3) {
        M = 0;
        for (i = I; i > 0; i >>= 1)
            m = M | i;
            if((m<= L) || ((m <= R) && (~N & i)))
                M = m;
        printf("%lld\n", M);
    }
    return 0;
}
