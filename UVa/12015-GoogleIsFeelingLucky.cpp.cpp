#include <stdio.h>
#include <string.h>

char web[100][100000];
int a[1000];

int main()
{
    int t, max, k, i;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        max=0;
        for(k=0 ; k<10 ; k++) {
            scanf("%s %d", &web[k], &a[k] );
            if( max<a[k] )
                max= a[k];
        }
        printf("Case #%d:\n", i+1);
        for(k=0 ; k<10 ; k++) {
            if( a[k]==max)
                printf("%s\n", web[k] );
        }
    }
    return 0;
}
