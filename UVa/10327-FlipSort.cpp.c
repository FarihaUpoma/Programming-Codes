#include <stdio.h>

int main()
{
    int n, i, c, m, k, tmp;
    int a[1000];
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0 ; i<n ; i++)
            scanf("%d", &a[i]);
        c=0;
        for(m=0 ; m<n-1; m++) {
            for(k=0 ; k<n-m-1; k++) {
                if( a[k] > a[k+1]) {
                    tmp = a[k];
                    a[k] = a[k+1];
                    a[k+1] = tmp;
                    c++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", c);
    }
    return 0;
}
