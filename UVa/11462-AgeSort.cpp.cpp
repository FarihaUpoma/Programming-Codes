#include <stdio.h>

int a[100000];

int main()
{
    int n, i, q, j, f;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;
        else {
            f=0;
            for(i=0 ; i<100 ; i++)
                a[i] = 0;
            for(i=0 ; i< n ;i++) {
                scanf("%d", &q);
                a[q-1] ++;
            }
            for(i=0 ; i<100 ; i++ ) {
                if( a[i]>0) {
                    for(j=0 ; j< a[i] ; j++) {
                        if(f==0) {
                            printf("%d", i+1);
                            f=1;
                        }
                        else
                            printf(" %d", i+1 );
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
