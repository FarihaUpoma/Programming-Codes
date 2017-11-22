#include <stdio.h>

int main()
{
    int a,b,c,i;
    while(scanf("%d %d", &a, &b))
    {
        c=0;
        if(a==0 && b==0) break;
        for(i=1 ; i*i <=b ; i++) {
            if(i*i >=a && i*i <=b)
                c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
