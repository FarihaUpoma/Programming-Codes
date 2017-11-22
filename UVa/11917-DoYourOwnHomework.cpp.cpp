#include <stdio.h>
#include <string.h>

char c[1000][1000], b[1000009];
int a[1000009];

int main()
{
    int tst, i, n, k, d, p;
    scanf("%d", &tst);
    for(i=0 ; i<tst ; i++) {
        scanf("%d", &n);
        for(k=0 ; k<n ; k++)
            scanf("%s %d", c[k] , &a[k] );
        scanf("%d %s", &d, b);
        printf("Case %d: ", i+1);
        p=0;
        for(k=0 ; k<n ; k++) {
            if( strcmp(c[k] , b)==0) {
                p=1;
                if(d>= a[k] )
                    printf("Yesss\n");
                else if( a[k]>d && a[k]<=(d+5))
                    printf("Late\n");
                else printf("Do your own homework!\n");
                break;
            }
        }
        if(p==0)
            printf("Do your own homework!\n");
    }
    return 0;
}
