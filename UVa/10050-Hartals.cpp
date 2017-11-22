#include <stdio.h>

int a[1000009];

int main()
{
    int n, p, i, k, h, l,c, t, q;
    scanf("%d", &t);
    for(q=0 ; q<t ; q++) {
        scanf("%d %d", &n, &p);
        c=0;
        for(i=0 ; i<n ; i++) a[i]=0;
        for(k=0 ; k<p ; k++) {
            scanf("%d", &h);
            for(l=h-1 ; l<n ; l=l+h)
                a[l]= 1;
        }
        for(k=6 ; k<=n ; k=k+7) {
            a[k]=0;
            a[k-1]=0;
        }

        for(i=0 ; i<n ; i++)
            if( a[i]==1) c++;
        printf("%d\n", c);
    }
    return 0;
}
