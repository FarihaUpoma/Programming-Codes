#include <stdio.h>

int main()
{
    int t, r,i, x1,x2,y;
    double l,w;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &r);
        l=r/.2;
        w=l*.6;
        x1=l*.45;
        x2=l*.55;
        y=w/2;
        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", i+1, -x1,y, x2,y,x2,-y,-x1,-y);
    }
    return 0;
}
