#include <stdio.h>

int a[1000009];

int main()
{
    int t, i, n, sum, k;
    double c;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        sum=0;
        c=0;
        for(k=0 ; k<n ; k++) {
            scanf("%d", &a[k] );
            sum=sum + a[k];
        }
        for(k=0  ; k<n ; k++) {
            if( a[k]> (sum/n) )
                c++;
        }
        printf("%.3lf%c\n", (c/n)*100, '%' );
    }
    return 0;
}
