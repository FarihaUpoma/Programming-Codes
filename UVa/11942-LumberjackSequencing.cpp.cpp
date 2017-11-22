#include <stdio.h>

int main()
{
    int i, k, c, n;
    int a[10009];
    scanf("%d", &n);
    printf("Lumberjacks:\n");
    for(i=0 ; i<n ; i++) {
        for(k=0 ; k<10 ; k++)
            scanf("%d", &a[k] );
            c=0;
        for(k=0 ; k<9 ; k++) {
            if( a[k+1] > a[k] ) c++;
            else if( a[k+1] < a[k] ) c--;
        }
        if(c==9 || c== -9)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
