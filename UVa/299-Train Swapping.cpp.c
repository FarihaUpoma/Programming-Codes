#include <stdio.h>

int main()
{
    int N, L, i, j, k, m, c, a[1000], tmp;
    scanf("%d", &N);
    for(i=0 ; i< N ; i++) {
        scanf("%d", &L);
        for(j=0 ; j< L ; j++)
            scanf("%d", &a[j]);
        c=0;
        for(m=0 ; m<L-1; m++) {
            for(k=0 ; k<L-m-1; k++) {
                if( a[k] > a[k+1]) {
                    tmp = a[k];
                    a[k] = a[k+1];
                    a[k+1] = tmp;
                    c++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", c);
    }
    return 0;
}
