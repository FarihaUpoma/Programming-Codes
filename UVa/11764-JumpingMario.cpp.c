#include <stdio.h>

int main()
{
    int t, n, q=0, i, j,w, a[100], h, l;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        h=0; l=0;
        for(j=0 ; j<n ; j++)
            scanf("%d", &a[j] );
        for(j=0 ; j<n-1 ; j++) {
            if(a[j+1] > a[j] ) h++;
            else if(a[j+1] < a[j] ) l++;
        }
        printf("Case %d: %d %d\n",i+1, h, l);
    }
    return 0;
}
