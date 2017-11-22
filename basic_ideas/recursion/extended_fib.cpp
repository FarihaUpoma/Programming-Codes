#include <stdio.h>
#include <string.h>

int a, b, c, d, e, f;
long long int nf[10009];

long long int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if( nf[n] != -1)
        return nf[n];
    else {
        nf[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )% 10000007;
        return nf[n];
    }
}
int main() {
    freopen("input.txt", "r" , stdin);

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        memset(nf, -1, sizeof(nf));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n)% 10000007 );
    }
    return 0;
}
