#include <stdio.h>

#define i64 long long int

#define mx 1000009

#define inf (1<<30)

#define pi (2*acos(0.0))

int table[mx];

int f(int n)

{

    if ( table[n] ) return table[n];

    else if( n%2 == 0 )

{

table[n] = f(n/2) + 1;

return table[n];

}

    else

{

table[n] = f(3*n+1) + 1;

return table[n];

}

}

int main()

{

    table[1] = 1;

    i64 max, c, i, j, l, h, temp, m, n;

    while(scanf("%lld %lld", &l, &h)!=EOF)

    {

        printf("%lld %lld", l, h);

           if ( l > h ) {

               temp = l;

               l = h;

               h = temp;

           }

           max=0;

           for(i=l ; i<=h ; i++) {

               c=f(i);

                    if(c>max) max=c;

           }

           printf(" %lld\n", max);

    }

    return 0;

}
