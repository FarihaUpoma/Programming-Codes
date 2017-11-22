#include <stdio.h>

int main()
{
    int a, b, c,t, i;
    scanf("%d" , &t);
    for(i=0 ; i<t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", i+1);
        if( (a>b && a<c) || (a>c && a<b) )
            printf("%d\n", a);
        else if( (b>a && b<c) || (b>c && b<a) )
            printf("%d\n", b);
        else
            printf("%d\n", c);
    }
    return 0;
}
