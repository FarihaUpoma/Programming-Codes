#include <stdio.h>

int main()
{
    int t, n, i, k;
    int a[1000009];
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        for(k=0 ; k<n ; k++)
            scanf("%d", &a[k] );
        printf("Case %d: %d\n",i+1, a[n/2] );
    }
    return 0;
}
