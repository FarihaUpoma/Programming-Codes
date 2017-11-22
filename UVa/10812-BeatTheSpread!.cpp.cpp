#include <stdio.h>

int main()
{
    int t, i, s, d, x, y;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %d", &s, &d);
        y=(s-d)/2;
        x=s-y;
        if(x<0 || y<0 || (x+y)!=s || (x-y)!=d)
            printf("impossible\n");
        else
            printf("%d %d\n", x, y);
    }
    return 0;
}
