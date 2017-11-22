#include <stdio.h>
#include <string.h>

char a[1000009] , b[1000009], c[1000009];

int main()
{
    int l, k, m, n, z,i, j, s;
    int x,y;
    while(scanf("%d %d", &x, &y)!=EOF)
    {
        if( x==0 && y==0) break;
        else {
            n=0;z=0;
            sprintf(a , "%d", x);
            sprintf(b , "%d", y);
            l=strlen(a);
            k=strlen(b);
            if(l>k) {
                strcpy( &c[0] , &b[0] );
                for(i=0 ; i<l-k ; i++ )
                    b[i] = '0';
                strcpy( &b[i] , &c[0] );
                s=l;
            }
            else if(k>l) {
                strcpy( &c[0] , &a[0] );
                for(i=0 ; i<k-l ; i++ )
                    a[i] = '0';
                strcpy( &a[i] , &c[0] );
                s=k;
            }
            if(l==k) s=l;
            for(i=s-1, j=s-1 ; i>=0 ; i--, j--) {
                m=a[i]+b[j]+n-96;
                n= m/10;
                if(m>9) z++;
            }
            if(z==0) printf("No carry operation.\n");
            else if(z==1) printf("1 carry operation.\n");
            else printf("%d carry operations.\n", z);
        }
    }
    return 0;
}
