#include <stdio.h>

int a[100000];

int main()
{
    int t , i, j, k, l;
    scanf("%d", &t);
    for(i=0 ; i< 2*t ; i++)
        scanf("%d", &a[i] );
    for(i=1 ; i<2*t ; i=i+2) {
        for(j=0 ; j<a[i] ; j++) {
            for(k=1 ; k<=a[i-1] ; k++) {
                for(l=0 ; l <k ; l++)
                    printf("%d", k);
                printf("\n");
            }
            for(k=a[i-1] -1 ; k>0 ; k--) {
                for(l=0 ; l< k ; l++)
                    printf("%d", k);
                printf("\n");
            }
            if(i==2*t-1 && j==a[i]-1) break;
            else
                printf("\n");
        }

    }
    return 0;
}
